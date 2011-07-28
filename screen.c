#include "screen.h"
#include "bus.h"

unsigned char *videoram = (unsigned char *) 0xb8000;

void clear() {
  unsigned char *videoram_cursor = (unsigned char *) 0xb8000;
  int row_cursor = 0, col_cursor = 0;

  for (int row_cursor = 0; row_cursor < ROWS; row_cursor++) {
    for (int col_cursor = 0; col_cursor < COLS; col_cursor++) {
      *videoram_cursor++ = 0x20;
      *videoram_cursor++ = 0x07;
    }
  }
}

void kputs(char* line) {
  static int row_cursor = 0;
  unsigned char *videoram_cursor = (unsigned char *) 0xb8000 + (2 * COLS * row_cursor);
  char *line_cursor = line;

  while (*line_cursor != 0) {
    *videoram_cursor = *line_cursor;
    videoram_cursor += 2;
    line_cursor++;
  }

  row_cursor++;
}
