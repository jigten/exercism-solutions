#include "resistor_color.h"
#include <stdlib.h>

int color_code(resistor_band_t color)
{
    return color;
}

resistor_band_t *colors()
{
    static resistor_band_t bands[10];
    for (int i = 0; i <= 9; i++)
    {
        bands[i] = i;
    }
    return bands;
}
