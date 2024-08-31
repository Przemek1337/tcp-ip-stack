cmake_minimum_required(VERSION 3.26)
project(tcp_ip)

set(CMAKE_CXX_STANDARD 17)
set(ASIO_INCLUDE_DIR C:/Users/przem/Desktop/Softwares/asio-1.30.2/include)
#set(Boost_LIBRARY_DIR C:/Users/przem/Desktop/Softwares/asio-1.30.2/include)

#find_package(Boost COMPONENTS system REQUIRED)

include_directories(${ASIO_INCLUDE_DIR})
#link_directories(${ASIO_INCLUDE_DIR})

add_executable(
        tcp_ip main.cpp
        Device/device.h
        Device/device.cpp
        NetworkObserver/network_observer.h
        NetworkObserver/network_observer.cpp
        NetworkMonitor/network_monitor.cpp
        NetworkMonitor/network_monitor.h
        AbstractDeviceFactory/abstract_device_factory.cpp
        AbstractDeviceFactory/abstract_device_factory.h
        ConcreteDeviceFactory/concrete_device_factory.cpp
        ConcreteDeviceFactory/concrete_device_factory.h
        Computer/computer.h
        Server/server.h
        ICMPHeader/icmp_header.h
)
target_link_libraries(tcp_ip PRIVATE ws2_32)