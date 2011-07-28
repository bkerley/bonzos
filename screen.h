#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"

#define ROWS 25
#define COLS 80

void clear();
void kputs(char*);
void move_cursor(uint16, uint16);

#endif
