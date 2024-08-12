cmake_minimum_required(VERSION 3.26)
project(tcp_ip)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        tcp_ip main.cpp
        Device/device.h
        Device/device.cpp
        NetworkObserver/network_observer.h
        NetworkObserver/network_observer.cpp
        NetworkMonitor/network_monitor.cpp
        NetworkMonitor/network_monitor.h
        Packet/packet.cpp
        Packet/packet.h
        EthernetPacket/ethernet_packet.cpp
        EthernetPacket/ethernet_packet.h
        IPPacket/ip_packet.cpp
        IPPacket/ip_packet.h
        TCPSegment/tcp_segment.cpp
        TCPSegment/tcp_segment.h
        UDPSegment/udp_segment.cpp
        UDPSegment/udp_segment.h
        AbstractDeviceFactory/abstract_device_factory.cpp
        AbstractDeviceFactory/abstract_device_factory.h
        ConcreteDeviceFactory/concrete_device_factory.cpp
        ConcreteDeviceFactory/concrete_device_factory.h
        Computer/computer.h
        Server/server.h
)
