#include "C:\Users\przem\Desktop\tcp_ip\NetworkObserver\network_observer.h"
#include "C:\Users\przem\Desktop\tcp_ip\NetworkMonitor\network_monitor.h"
void NetworkMonitor::onConnectionLost(Device& device){
    std::cout << "Connection lost with device: " << device.getDeviceHostName() << std::endl;
}
void NetworkMonitor::onConnectionRestored(Device& device){
    std::cout << "Connection restored with device: " << device.getDeviceHostName() << std::endl;
}


