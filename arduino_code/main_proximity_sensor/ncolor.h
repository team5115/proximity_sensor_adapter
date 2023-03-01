#ifndef _ncolor_h_
#define _ncolor_h_

#include "raw_color.h"

struct ncolor_t
{

    public:

        double red;
        double green;
        double blue;
        double mag;

        ncolor_t(raw_color_t the_raw_color)
        {

            red = static_cast<double>(the_raw_color.red);
            green = static_cast<double>(the_raw_color.green);
            blue = static_cast<double>(the_raw_color.blue);

            normalize();

        }

        void normalize(void)
        {
            mag=red+green+blue;

            if (mag !=0)
            {
                red /= mag;
                blue/= mag;
                green/=green;
            }

        }
};
#endif
