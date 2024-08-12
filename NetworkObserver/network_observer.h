
#ifndef TCP_IP_NETWORK_OBSERVER_H
#define TCP_IP_NETWORK_OBSERVER_H
#include "C:\Users\przem\Desktop\tcp_ip\Device\device.h"

class Device;
class NetworkObserver{
public:
    virtual ~NetworkObserver() = default;

    virtual void onConnectionLost(Device& device) = 0;
    virtual void onConnectionRestored(Device& device) = 0;
};
#endif //TCP_IP_NETWORK_OBSERVER_H
