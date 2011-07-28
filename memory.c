#include "memory.h"

void* memcpy(void* destination, const void* source, size_t length) {
  uint8* cursor = (uint8*)destination;
  uint8* source_cursor = (uint8*)source;
  while(length > 0) {
    *cursor++ = *source_cursor++;
    length--;
  }

  return destination;
}

void* memset(void* destination, int value, size_t length) {
  uint8* cursor = (uint8*)destination;
  while(length > 0) {
    *cursor++ = (uint8)value;
    length --;
  }

  return destination;
}

int memcmp(void* s1, void* s2, size_t length) {
  uint8 *sa1 = (uint16*)s1;
  uint8 *sa2 = (uint16*)s2;
  int diff;

  if (length == 0) return 0;

  if (length == 1) return (*sa1) - (*sa2);

  while (length > 0) {
    diff = *sa1++ - *sa2++;
    if (diff) return diff;
    length--;
  }

  return 0;
}
