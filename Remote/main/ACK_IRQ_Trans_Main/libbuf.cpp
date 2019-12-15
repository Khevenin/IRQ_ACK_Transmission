#include "libbuf.h"

void bufferCopyMap(uint16_t *src, uint8_t *dst, size_t srcSize, size_t dstSize)
{
    if ((srcSize > 0) && (dstSize > 0)) //detect invalid size of src and dst arrays
        {
            if (srcSize > dstSize)
            {
                bufferMap(src, dst, dstSize);
                return 1;
            }
            else //Source size less than Destiny size
            {
                bufferMap(src, dst, srcSize);
                return 1;
            }
        }
    else
    {
        return 0;
    }
}

void bufferMap(uint16_t *src, uint8_t *dst, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dst[i] = tenToEightBits(src);
    }
}

unsigned short tenToEightBits(uint16_t *src)
{
    unsigned int tmp = (*src >> 2);
    return (unsigned short)tmp;
}

unsigned short bufferCopy(uint8_t *src, uint8_t *dst, size_t srcSize, size_t dstSize)
{
    if ((srcSize > 0) && (dstSize > 0)) //detect invalid size of src and dst arrays
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

void copy(uint8_t *src, uint8_t *dst, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dst[i] = src[i];
    }
}

unsigned short bufferReset(uint8_t *buf, size_t size )
{
    if (size> 0)
    {
        resetShort(buf, size);
        return 1;
    }
    else
    {
        return 0;
    }
}

void resetShort(uint8_t *buf, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        buf[i] = 0;
    }
}

void resetLong(uint16_t *buf, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        buf[i] = 0;
    }
}
