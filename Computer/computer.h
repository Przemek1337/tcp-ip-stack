
#ifndef TCP_IP_COMPUTER_H
#define TCP_IP_COMPUTER_H
#include "C:\Users\przem\Desktop\tcp_ip\Device\device.h"
class Computer: public Device{
public:
    Computer(const std::string& computer_hostname, const std::string& computer_ipaddr, const std::string& computer_subnet) :
            Device(computer_hostname, computer_ipaddr, computer_subnet){};

    Computer() : Device("", "", ""){};
};
#endif //TCP_IP_COMPUTER_H
