#include <stdio.h>

/* Funtion to reset arrays */
void resetShort(uint8_t *buf, size_t size);
void resetLong(uint16_t *buf, size_t size);
unsigned short bufferReset(uint8_t *buf, size_t size);

/* Function to conversion from 10bit array to 8bits */
unsigned short tenToEightBits(uint16 *src);
void bufferMap(uint16_t *src, uint8_t *dst, size_t size);
void bufferCopyMap(uint16_t *src, uint8_t *dst, size_t srcSize, size_t dstSize);

/* Function to copy 8bits arrays */
void copy(uint16_t *src, uint16_t *dst, size_t size);
unsigned short bufferCopy(uint16_t *src, uint16_t *dst, size_t srcSize, size_t dstSize);