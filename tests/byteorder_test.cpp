#include <iostream>
#define NH_BYTEORDER_IMPLEMENTATION
#include "../headers/nh_byteorder.hpp"

#define ERROR(msg) {std::cerr << "Error: " << (msg) << std::endl; return 1;}
#define SUCCESS(msg) {std::cout << "Test: " << (msg) << "\tOK!" << std::endl;}
#define ASSERT(cond, msg) {if (cond) SUCCESS(msg) else ERROR(msg)}

int main() {

    std::cout << "Is Little Endian: " << (nh::isLittleEndian() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Is Big Endian:    " << (nh::isBigEndian() ? "TRUE" : "FALSE") << std::endl;

    ASSERT(nh::swap16(0xFF00) == 0x00FF, "swap16(0xFF00)");
    ASSERT(nh::swap16(0x00FF) == 0xFF00, "swap16(0x00FF)");

    ASSERT(nh::swap32(0xFF) == 0xFF000000, "swap32(0xFF)");
    ASSERT(nh::swap32(0xFF000000) == 0xFF, "swap32(0xFF000000)");
    ASSERT(nh::swap32(0xF500BDAC) == 0xACBD00F5, "swap32(0xF500BDAC)");

    ASSERT(nh::swap64(0xF500BDAC) == 0xACBD00F500000000, "swap64(0xF500BDAC)");
    ASSERT(nh::swap64(0x1234567890ABCDEF) == 0xEFCDAB9078563412, "swap64(0x1234567890ABCDEF)");

    std::cout << "Everything OK" << std::endl;
    return 0;
}
