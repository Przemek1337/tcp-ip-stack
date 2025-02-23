
#ifndef TCP_IP_ICMP_HEADER_H
#define TCP_IP_ICMP_HEADER_H
#include <cstdint>
#include <cstring>
struct icmp_header{
    uint8_t icmp_type;
    uint8_t icmp_code;
    uint16_t icmp_checksum;
    uint16_t icmp_identifier;
    uint16_t icmp_sequence_number;

    icmp_header() :
    icmp_type(8), icmp_code(0), icmp_checksum(0), icmp_identifier(0), icmp_sequence_number(0) {};

    void compute_icmp_checksum() {
        this->icmp_checksum = 0;
        uint32_t temp_sum = 0;
        uint16_t* data = reinterpret_cast<uint16_t*>(this);

        for (std::size_t i = 0; i < sizeof(icmp_header) /2; ++i){
            temp_sum += data[i];
        }

        temp_sum = (temp_sum >> 16) + (temp_sum & 0xFFFF);
        temp_sum += (temp_sum >> 16);

        this->icmp_checksum = ~static_cast<uint16_t>(temp_sum);
    }
};
#endif //TCP_IP_ICMP_HEADER_H
