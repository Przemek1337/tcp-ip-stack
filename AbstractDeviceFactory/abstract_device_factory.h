
#ifndef TCP_IP_ABSTRACT_DEVICE_FACTORY_H
#define TCP_IP_ABSTRACT_DEVICE_FACTORY_H
#include "memory"

#include "..\Computer\computer.h"
#include "..\Server\server.h"

#include "../Computer/computer.h"
#include "../Server/server.h"

class AbstractDeviceFactory{
public:
    virtual ~AbstractDeviceFactory() = default;

    virtual std::shared_ptr<Computer> createComputer(const std::string& hostname, const std::string& ip, const std::string& subnet, NetworkMonitor* network_monitor) = 0;
    virtual std::shared_ptr<Server> createServer(const std::string& hostname, const std::string& ip, const std::string& subnet, NetworkMonitor* network_monitor) = 0;
};
#endif //TCP_IP_ABSTRACT_DEVICE_FACTORY_H
