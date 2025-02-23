
#ifndef TCP_IP_NETWORK_MONITOR_H
#define TCP_IP_NETWORK_MONITOR_H

#include "..\NetworkObserver\network_observer.h"

#include "../NetworkObserver/network_observer.h"

#include <iostream>
class Device;
class NetworkMonitor: public NetworkObserver{
private:
    std::vector<NetworkObserver*> network_observers;
public:
    void onConnectionLost(Device& device) override;
    void onConnectionRestored(Device& device) override;
    void addObserver (NetworkMonitor* network_monitor);
    void removeObserver (NetworkMonitor* network_monitor);
};
#endif //TCP_IP_NETWORK_MONITOR_H
