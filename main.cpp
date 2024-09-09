#include <iostream>
#include "ConcreteDeviceFactory/concrete_device_factory.h"
#include "NetworkMonitor/network_monitor.h"

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <functional>
#include "device/device.h"
#include "commandMenager/commandMenager.h"

void print_prompt() {
    std::cout << "TCP_IP> ";
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    ConcreteDeviceFactory factory;
//    asio::io_context io_context;
//
//
//    auto computer = factory.createComputer("Computer", "192.168.1.10", "255.255.255.0");
//    auto server = factory.createServer("Computer", "192.168.1.20", "255.255.255.0");
//
//    bool res = computer->pingBetweenDevices(io_context, *server);
//    if (res){
//        std::cout << "Ping succ" << std::endl;
//    }else{
//        std::cout << "Ping failed" << std::endl;
//    }
//
//
//    CommandMenager commandMenager;
//    std::string command {};
//
////    auto computer = factory.createComputer();
////    auto server = factory.createServer();
//
//    NetworkMonitor monitor;
//    computer->addObserver(&monitor);
//    server->addObserver(&monitor);
//
//
//    while (true) {
//        print_prompt();
//        std::getline(std::cin, command);
//
//        std::istringstream iss(command);
//        std::vector<std::string> command_parts;
//        std::string word {};
//
//        while (iss >> word) {
//            command_parts.push_back(word);
//        }
//
//        // for (auto e : command_parts) {
//        //     std::cout << e << std::endl;
//        // }
//
//        if (command_parts.empty()) {
//            continue;
//        }
//
//        if (command_parts[0] == "exit") {
//            exit(0);
//        }
//
//        commandMenager.executeComand(command_parts);
//    }
//
//

    return 0;
}