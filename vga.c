#include "vga.h"
#include "bochs_vga.h"
#include "bus.h"
#include "memory.h"

void bochs_vga_write(uint16 index, uint16 value);
uint16 bochs_vga_read(uint16 index);

char bochs_vga_available() {
  uint16 identification_data;
  identification_data = bochs_vga_read(VBE_DISPI_INDEX_ID);

  return identification_data == VBE_DISPI_ID5;
}

void bochs_vga_set_resolution(uint16 width, uint16 height) {
  bochs_vga_write(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_DISABLED);
  bochs_vga_write(VBE_DISPI_INDEX_XRES, width);
  bochs_vga_write(VBE_DISPI_INDEX_YRES, height);
  bochs_vga_write(VBE_DISPI_INDEX_BPP, 32);
  bochs_vga_write(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_ENABLED | VBE_DISPI_LFB_ENABLED);
}

void draw_box(uint16 top_left_x, uint16 top_left_y, uint16 width, uint16 height, uint32 color) {
  uint32* videoram = VBE_DISPI_LFB_PHYSICAL_ADDRESS;
  uint32* cursor = videoram + top_left_y*800 + top_left_x;
  size_t offset = 800 - width;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      *cursor = color;
      cursor++;
    }
    cursor += offset;
  }
}

void clear_screen(uint8 grey) {
  memset(VBE_DISPI_LFB_PHYSICAL_ADDRESS, grey, 800*600*4);
}

void bochs_vga_write(uint16 index, uint16 value) {
  bus_out_word(VBE_DISPI_IOPORT_INDEX, index);
  bus_out_word(VBE_DISPI_IOPORT_DATA, value);
}

uint16 bochs_vga_read(uint16 index) {
  bus_out_word(VBE_DISPI_IOPORT_INDEX, index);
  return bus_in_word(VBE_DISPI_IOPORT_DATA);
}
