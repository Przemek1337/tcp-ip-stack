
#ifndef TCP_IP_CONCRETE_DEVICE_FACTORY_H
#define TCP_IP_CONCRETE_DEVICE_FACTORY_H
#include "..\AbstractDeviceFactory\abstract_device_factory.h"
class ConcreteDeviceFactory: public AbstractDeviceFactory{
public:
    std::shared_ptr<Computer> createComputer(const std::string& hostname, const std::string& ip, const std::string& subnet, NetworkMonitor* network_monitor) override {
        return std::make_shared<Computer>(hostname, ip, subnet, network_monitor);
    }
    std::shared_ptr<Server> createServer(const std::string& hostname, const std::string& ip, const std::string& subnet, NetworkMonitor* network_monitor) override {
        return std::make_shared<Server>(hostname, ip, subnet, network_monitor);
    }
};
#endif //TCP_IP_CONCRETE_DEVICE_FACTORY_H
