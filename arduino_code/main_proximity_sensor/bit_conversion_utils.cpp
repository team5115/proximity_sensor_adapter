#include "bit_conversion_utils.h"

uint32_t to_20_bit(uint8_t *val)
{
    return (static_cast<uint32_t>(val[0]) |
        (static_cast<uint32_t>(val[1]) << 8) |
        (static_cast<uint32_t>(val[2]) << 16)) &
        0x03FFFF;
}


uint16_t to_11_bit(uint8_t *val)
{
    return (static_cast<uint16_t>(val[0]) |
        (static_cast<uint16_t>(val[1]) << 8)) &
        0x7FF;
}
