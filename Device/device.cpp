#include "..\Device\device.h"

Device::Device(std::string hostname_param, std::string ipaddr_param, std::string subnet_param, NetworkMonitor* network_monitor) :
    device_hostname(hostname_param), device_ip_address(ipaddr_param), device_subnet_mask(subnet_param), network_monitor(network_monitor){}

std::string Device::getDeviceHostName()const {
    return device_hostname;
}
std::string Device::getDeviceIpAddress() const {
    return device_ip_address;
}
bool Device::pingBetweenDevices(asio::io_context& io_context, Device& target_device_to_ping) {
    std::cout << "[LOG] Starting ping to: " << target_device_to_ping.getDeviceIpAddress() << std::endl;

    if (!isSameSubnet(target_device_to_ping)) {
        std::cout << "Devices are not in the same subnet. Ping aborted." << std::endl;
        if (network_monitor != nullptr) {
            network_monitor->onConnectionLost(*this);
        } else {
            std::cerr << "[ERROR] Network monitor is not initialized!" << std::endl;
        }
        return false;
    }

    asio::ip::icmp::resolver resolver(io_context);
    asio::ip::icmp::endpoint destination =
            *resolver.resolve(asio::ip::icmp::v4(), target_device_to_ping.getDeviceIpAddress(), "").begin();

    asio::ip::icmp::socket socket(io_context, asio::ip::icmp::v4());
    socket.connect(destination);

    icmp_header icmp_request;
    icmp_request.icmp_identifier = static_cast<uint16_t>(::getpid());
    icmp_request.icmp_sequence_number = 0;
    icmp_request.compute_icmp_checksum();

    std::vector<uint8_t> request(sizeof(icmp_request));
    std::memcpy(request.data(), &icmp_request, sizeof(icmp_request));

    socket.send(asio::buffer(request));
    std::cout << "[LOG] ICMP request sent." << std::endl;

    target_device_to_ping.receivePing(icmp_request);
    std::cout << "[LOG] Starting running io_context." << std::endl;
    io_context.run();
    std::cout << "[LOG] Ending running io_context." << std::endl;
    io_context.stop(); // Zatrzymanie run loop po zakończeniu operacji
    if (network_monitor != nullptr) {
        network_monitor->onConnectionRestored(*this);
    } else {
        std::cerr << "[ERROR] Network monitor is not initialized!" << std::endl;
    }
    return true;
}
std::string
Device::calculateNetworkAddress(const std::string &device_ip_address, const std::string &device_subnet_mask) {
    asio::ip::address_v4::bytes_type convert_ip_to_bytes = asio::ip::make_address_v4(device_ip_address).to_bytes();
    asio::ip::address_v4::bytes_type convert_subnet_mask_to_bytes = asio::ip::make_address_v4(device_subnet_mask).to_bytes();
    asio::ip::address_v4::bytes_type network_bytes;

    for(size_t i{0}; i < convert_ip_to_bytes.size(); i++){
        network_bytes[i] = convert_ip_to_bytes[i] & convert_subnet_mask_to_bytes[i];
    }

    return asio::ip::address_v4(network_bytes).to_string();
}
bool Device::isSameSubnet(const Device &other) const {
    return (
    calculateNetworkAddress(device_ip_address, device_subnet_mask) ==
    calculateNetworkAddress(other.device_ip_address, other.device_subnet_mask)
    );
}
void Device::receivePing(const icmp_header &request) {
    std::cout << "[LOG] Received ICMP request." << std::endl;

    asio::io_context io_context;
    asio::ip::icmp::socket socket(io_context, asio::ip::icmp::v4());

    sendICMPReply(io_context, socket, request);
}
void Device::sendICMPReply(asio::io_context& io_context, asio::ip::icmp::socket& socket, const icmp_header& request) {
    icmp_header reply;
    reply.icmp_type = 0;
    reply.icmp_code = 0;
    reply.icmp_identifier = request.icmp_identifier;
    reply.icmp_sequence_number = request.icmp_sequence_number;
    reply.compute_icmp_checksum();

    std::vector<uint8_t> response(sizeof(reply));
    std::memcpy(response.data(), &reply, sizeof(reply));

    // Bind socket to a local endpoint if necessary
    socket.bind(asio::ip::icmp::endpoint(asio::ip::icmp::v4(), 0));

    // Wysłanie odpowiedzi ICMP do źródła (używamy adresu IP docelowego z nagłówka lub innego znanego adresu)
    asio::ip::icmp::resolver resolver(io_context);
    asio::ip::icmp::endpoint source_endpoint =
            *resolver.resolve(asio::ip::icmp::v4(), "192.168.1.10", "").begin(); // zastąp adresem IP nadawcy

    socket.send_to(asio::buffer(response), source_endpoint);
    std::cout << "ICMP reply sent to " << source_endpoint.address().to_string() << std::endl;
}
