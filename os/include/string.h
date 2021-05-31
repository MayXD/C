#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_

#include "types.h"
void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);
void memset(void *dest, uint8_t val, uint32_t len);
#endif