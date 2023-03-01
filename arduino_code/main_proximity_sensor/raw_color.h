#ifndef _raw_color_h_
#define _raw_color_h_

#include <stdint.h>

struct raw_color_t
{
    uint32_t red;
    uint32_t green;
    uint32_t blue;
    uint32_t ir;

    raw_color_t(uint32_t r, uint32_t g, uint32_t b, uint32_t _ir) : red(r), green(g), blue(b), ir(_ir) {}
};
#endif
