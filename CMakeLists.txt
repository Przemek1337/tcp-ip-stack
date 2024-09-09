cmake_minimum_required(VERSION 3.26)
project(tcp_ip)

set(CMAKE_CXX_STANDARD 17)


set(ASIO_INCLUDE_DIR C:/Users/przem/Desktop/Softwares/asio-1.30.2/include)
include_directories(${ASIO_INCLUDE_DIR})

# Tworzenie programu tcp_ip
add_executable(tcp_ip
        main.cpp
        Device/device.h
        Device/device.cpp
        NetworkObserver/network_observer.h
        NetworkObserver/network_observer.cpp
        NetworkMonitor/network_monitor.h
        NetworkMonitor/network_monitor.cpp
        AbstractDeviceFactory/abstract_device_factory.h
        AbstractDeviceFactory/abstract_device_factory.cpp
        ConcreteDeviceFactory/concrete_device_factory.h
        ConcreteDeviceFactory/concrete_device_factory.cpp
        addNewDeviceCommand/addNewDeviceCommand.h
        addNewDeviceCommand/addNewDeviceCommand.cpp
        commandMenager/commandMenager.h
        command/command.cpp
        command/command.h
        Computer/computer.h
        Server/server.h
        ICMPHeader/icmp_header.h
)

# Linkowanie z biblioteką Windows Sockets
target_link_libraries(tcp_ip PRIVATE ws2_32)
