#include "apds_9151_utils.h"

uint32_t To20Bit(uint8_t *val)
{
    return (static_cast<uint32_t>(val[0]) |
        (static_cast<uint32_t>(val[1]) << 8) |
        (static_cast<uint32_t>(val[2]) << 16)) &
        0x03FFFF;
}


uint16_t To11Bit(uint8_t *val)
{
    return (static_cast<uint16_t>(val[0]) |
        (static_cast<uint16_t>(val[1]) << 8)) &
        0x7FF;
}
