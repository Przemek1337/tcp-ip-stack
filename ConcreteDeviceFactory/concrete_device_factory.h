
#ifndef TCP_IP_CONCRETE_DEVICE_FACTORY_H
#define TCP_IP_CONCRETE_DEVICE_FACTORY_H
#include "C:\Users\przem\Desktop\tcp_ip\AbstractDeviceFactory\abstract_device_factory.h"
class ConcreteDeviceFactory: public AbstractDeviceFactory{
public:
    std::shared_ptr<Computer> createComputer() override {
        return std::make_shared<Computer>();
    }
    std::shared_ptr<Server> createServer() override {
        return std::make_shared<Server>();
    }
};
#endif //TCP_IP_CONCRETE_DEVICE_FACTORY_H
