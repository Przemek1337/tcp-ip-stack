
#ifndef TCP_IP_SERVER_H
#define TCP_IP_SERVER_H

#include "..\Device\device.h"

#include "../Device/device.h"

class Server: public Device{
public:
    Server(const std::string& server_hostname, const std::string& server_ipaddr, const std::string& server_subnet, NetworkMonitor* network_monitor) :
            Device(server_hostname, server_ipaddr, server_subnet, network_monitor){};

    Server() : Device("", "", "", nullptr){};
};
#endif //TCP_IP_SERVER_H
