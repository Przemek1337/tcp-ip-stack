
#ifndef TCP_IP_SERVER_H
#define TCP_IP_SERVER_H
#include "../Device/device.h"
class Server: public Device{
public:
    Server() : Device("Computer") {};
};
#endif //TCP_IP_SERVER_H
