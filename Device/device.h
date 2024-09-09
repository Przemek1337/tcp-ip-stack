
#ifndef TCP_IP_DEVICE_H
#define TCP_IP_DEVICE_H
#include <utility>

#include "vector"
#include "string"
#include "../NetworkObserver/network_observer.h"
class NetworkObserver;
class Device{
private:
    std::string device_hostname;
    std::vector<NetworkObserver*> observers_list;

public:
    Device(std::string  hostname_param);

    std::string getDeviceHostName() const;

    void addObserver (NetworkObserver* network_observer);
    void removeObserver (NetworkObserver* network_observer);
};
#endif //TCP_IP_DEVICE_H
