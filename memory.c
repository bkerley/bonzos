#include "memory.h"

void* memcpy(void* destination, void* source, size_t length) {
  uint8* cursor = (uint8*)destination;
  while(length > 0) {
    *cursor++ = (*(uint8*)source++);
    length--;
  }

  return destination;
}

void* memset(void* destination, uint8 value, size_t length) {
  uint8* cursor = (uint8*)destination;
  while(length > 0) {
    *cursor++ = value;
    length --;
  }

  return destination;
}
