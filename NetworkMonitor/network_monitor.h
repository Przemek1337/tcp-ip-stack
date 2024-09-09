
#ifndef TCP_IP_NETWORK_MONITOR_H
#define TCP_IP_NETWORK_MONITOR_H
#include "../NetworkObserver/network_observer.h"
#include <iostream>
class NetworkMonitor: public NetworkObserver{
public:
    void onConnectionLost(Device& device) override;
    void onConnectionRestored(Device& device) override;
};
#endif //TCP_IP_NETWORK_MONITOR_H
