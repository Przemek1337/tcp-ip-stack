#include <iostream>
#include "C:\Users\przem\Desktop\tcp_ip\ConcreteDeviceFactory\concrete_device_factory.h"
#include "C:\Users\przem\Desktop\tcp_ip\NetworkMonitor\network_monitor.h"
int main() {
//    std::cout << "Hello, World!" << std::endl;
    ConcreteDeviceFactory factory;
    asio::io_context io_context;

    auto computer = factory.createComputer("Computer", "192.168.1.10", "255.255.255.0");
    auto server = factory.createServer("Computer", "192.168.1.20", "255.255.255.0");

    bool res = computer->pingBetweenDevices(io_context, *server);
    if (res){
        std::cout << "Ping succ" << std::endl;
    }else{
        std::cout << "Ping failed" << std::endl;
    }

    return 0;
}
