#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

void* memcpy(void *, const void *, size_t);
void* memset(void *, int, size_t);
int memcmp(void*, void*, size_t);

#endif
