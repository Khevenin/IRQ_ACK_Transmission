#include <stdio.h>

#include "libbuf.h"

void bufferCopyMap(uint16_t *source, uint8_t *buf, uint8_t bufSize)
{
    for (int i = 0; i < bufSize; i++)
    {
        buf[i] = map(source[i], 0, 1023, 0, 255);
    }
}

unsigned short bufferCopy(uint16_t *src, uint16_t *dst, size_t srcSize, size_t dstSize)
{
    if ((srcSize > 0) && (dstSize > 0)))
        {
            if (srcSize > dstSize)
            {
                copy(src, dst, dstSize);
                return 1;
            }
            else //Source size less than Destiny size
            {
                copy(src, dst, dstSize);
                return 1;
            }
        }
    else
    {
        return 0;
    }
}

void copy(uint16_t *src, uint16_t *dst, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dst[i] = src[i];
    }
}

void bufferReset(uint8_t *buf, uint8_t bufSize)
{
    for (int i = 0; i < bufSize; i++)
    {
        buf[i] = 0;
    }
}
