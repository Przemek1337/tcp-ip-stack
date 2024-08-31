
#ifndef TCP_IP_SERVER_H
#define TCP_IP_SERVER_H
#include "C:\Users\przem\Desktop\tcp_ip\Device\device.h"
class Server: public Device{
public:
    Server(const std::string& server_hostname, const std::string& server_ipaddr, const std::string& server_subnet) :
            Device(server_hostname, server_ipaddr, server_subnet){};

    Server() : Device("", "", ""){};
};
#endif //TCP_IP_SERVER_H
