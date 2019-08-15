#ifndef NH_BYTEORDER
#define NH_BYTEORDER

#include <cstdint>

namespace nh {

    /* Check endianness */
    int isLittleEndian();
    int isBigEndian();

    /* Swap bytes */
    uint16_t swap16(uint16_t in);
    uint32_t swap32(uint32_t in);
    uint64_t swap64(uint64_t in);

    /* Convert to little endian */
    uint16_t toLittleEndian16(uint16_t in);
    uint32_t toLittleEndian32(uint32_t in);
    uint64_t toLittleEndian64(uint64_t in);

    /* Convert to big endian */
    uint16_t toBigEndian16(uint16_t in);
    uint32_t toBigEndian32(uint32_t in);
    uint64_t toBigEndian64(uint64_t in);

#if defined NH_BYTEORDER_IMPLEMENTATION || defined NH_IMPLEMENT_ALL

    /* Check endiannes*/

    union _endian_test {
        uint16_t word;
        uint8_t byte[2];
    };

    int isLittleEndian() {
        _endian_test test;
        test.word = 0xAA00;

        return test.byte[0] == 0x00;
    }

    int isBigEndian() {
        _endian_test test;
        test.word = 0xAA00;

        return test.byte[0] == 0xAA;
    }

    /* Swap bytes */

    uint16_t swap16(uint16_t in)
    {
        return (in >> 8) | (in << 8);
    }

    uint32_t swap32(uint32_t in)
    {
        return  ((in & 0xFF000000) >> 24) | ((in & 0x00FF0000) >>  8) | 
                ((in & 0x0000FF00) <<  8) | ((in & 0x000000FF) << 24);
    }

    uint64_t swap64(uint64_t in)
    {
        uint64_t a = swap32(0xFFFFFFFF & in);
        uint64_t b = swap32(((0xFFFFFFFFL << 32) & in) >> 32);

        return (a << 32) | b;
    }

    /* Convert to little endian */

    uint16_t toLittleEndian16(uint16_t in) 
    {
        return isLittleEndian() ? in : swap16(in);
    }

    uint32_t toLittleEndian32(uint32_t in) 
    {
        return isLittleEndian() ? in : swap32(in);
    }

    uint64_t toLittleEndian64(uint64_t in) 
    {
        return isLittleEndian() ? in : swap64(in);
    }

    /* Convert to big endian */
    
    uint16_t toBigEndian16(uint16_t in)
    {
        return isBigEndian() ? in : swap16(in);
    }

    uint32_t toBigEndian32(uint32_t in)
    {
        return isBigEndian() ? in : swap32(in);
    }

    uint64_t toBigEndian64(uint64_t in)
    {
        return isBigEndian() ? in : swap64(in);
    }

#endif
}

#endif /* NH_BYTEORDER */
