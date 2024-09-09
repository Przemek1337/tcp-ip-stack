
#include "..\NetworkMonitor\network_monitor.h"

#include "../NetworkObserver/network_observer.h"
#include "../NetworkMonitor/network_monitor.h"

void NetworkMonitor::onConnectionLost(Device& device){
    std::cout << "Connection lost with device: " << device.getDeviceHostName() << std::endl;
}
void NetworkMonitor::onConnectionRestored(Device& device){
    std::cout << "Connection restored with device: " << device.getDeviceHostName() << std::endl;
}

void NetworkMonitor::addObserver(NetworkMonitor *network_monitor) {
    network_observers.push_back(network_monitor);
}
void NetworkMonitor::removeObserver(NetworkMonitor *network_monitor) {
    //network_observers.erase(std::remove(network_observers.begin(), network_observers.end(), network_observers), network_observers.end());
    // TODO
}


