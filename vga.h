#ifndef VGA_H
#define VGA_H

#include "types.h"

char bochs_vga_available();
void bochs_vga_set_resolution(uint16 width, uint16 height);

void draw_box(uint16 top_left_x, uint16 top_left_y, uint16 width, uint16 height, uint32 color);
void clear_screen(uint8 grey);

#endif
