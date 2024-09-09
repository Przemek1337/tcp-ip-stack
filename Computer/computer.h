
#ifndef TCP_IP_COMPUTER_H
#define TCP_IP_COMPUTER_H

#include "..\Device\device.h"

#include "../Device/device.h"

class Computer: public Device{
public:
    Computer(const std::string& computer_hostname, const std::string& computer_ipaddr, const std::string& computer_subnet, NetworkMonitor* network_monitor) :
            Device(computer_hostname, computer_ipaddr, computer_subnet, network_monitor){};

    Computer() : Device("", "", "", nullptr){};
};
#endif //TCP_IP_COMPUTER_H
