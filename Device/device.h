
#ifndef TCP_IP_DEVICE_H
#define TCP_IP_DEVICE_H
#include <utility>

#include "vector"
#include "string"

#include "..\NetworkMonitor\network_monitor.h"
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include "..\ICMPHeader\icmp_header.h"
struct icmp_header;
class NetworkMonitor;

#include "../NetworkObserver/network_observer.h"
class NetworkObserver;

class Device{
private:
    std::string device_hostname;
    std::string device_ip_address;
    std::string device_subnet_mask;
    NetworkMonitor* network_monitor;
    std::vector<NetworkMonitor*> monitor_list;
    icmp_header icmp_request;

public:
    Device(std::string  hostname_param, std::string device_ip_address, std::string device_subnet_mask, NetworkMonitor* network_monitor);

    std::string getDeviceHostName() const;
    std::string getDeviceIpAddress() const;

    bool isSameSubnet(const Device& other) const;
    bool pingBetweenDevices(asio::io_context& io_context, Device& target_device_to_ping);
    void receivePing(const icmp_header& request);
    void sendICMPReply(asio::io_context& io_context, asio::ip::icmp::socket& socket, const icmp_header& request);


private:
    static std::string calculateNetworkAddress(const std::string& device_ip_address, const std::string& device_subnet_mask) ;
};
#endif //TCP_IP_DEVICE_H
