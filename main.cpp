#include <iostream>
#include "C:\Users\przem\Desktop\tcp_ip\ConcreteDeviceFactory\concrete_device_factory.h"
#include "C:\Users\przem\Desktop\tcp_ip\NetworkMonitor\network_monitor.h"
int main() {
//    std::cout << "Hello, World!" << std::endl;
    ConcreteDeviceFactory factory;

    auto computer = factory.createComputer();
    auto server = factory.createServer();

    NetworkMonitor monitor;
    computer->addObserver(&monitor);
    server->addObserver(&monitor);
    return 0;
}
