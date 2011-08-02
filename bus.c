#include "bus.h"

void bus_out_byte(uint16 port, uint8 byte) {
  asm volatile ("outb %1, %0" : : "dN" (port), "a" (byte));
}

void bus_out_word(uint16 port, uint16 word) {
  asm volatile ("outw %1, %0" : : "dN" (port), "a" (word));
}

uint8 bus_in_byte(uint16 port) {
  uint8 result;
  asm volatile ("inb %1, %0" : "=a" (result) : "dN" (port));
  return result;
}

uint16 bus_in_word(uint16 port) {
  uint16 result;
  asm volatile ("inw %1, %0" : "=a" (result) : "dN" (port));
  return result;
}
