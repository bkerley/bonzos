#ifndef BUS_H
#define BUS_H

#include "types.h"

void bus_out_byte(uint16 port, uint8 byte);
void bus_out_word(uint16 port, uint16 word);
uint8 bus_in_byte(uint16 port);
uint16 bus_in_word(uint16 port);
#endif
