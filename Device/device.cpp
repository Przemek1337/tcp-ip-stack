#include "../Device/device.h"

Device::Device(std::string hostname_param) : device_hostname(std::move(hostname_param)){}

std::string Device::getDeviceHostName()const {
    return device_hostname;
}

void Device::addObserver(NetworkObserver *network_observer) {
    observers_list.push_back(network_observer);
}

void Device::removeObserver(NetworkObserver *network_observer) {

}
