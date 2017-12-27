#include "../include/type.h"

int kernel_entry() {
    u8_t *output_buf = (u8_t *) 0xB8000;
    u8_t color = (0 << 4) | (15 & 0x0F);
    *output_buf++ = 'H'; *output_buf++ = color;
    *output_buf++ = 'E'; *output_buf++ = color;
    *output_buf++ = 'L'; *output_buf++ = color;
    *output_buf++ = 'L'; *output_buf++ = color;
    *output_buf++ = 'O'; *output_buf++ = color;
    *output_buf++ = '!'; *output_buf++ = color;

    return 0;
}