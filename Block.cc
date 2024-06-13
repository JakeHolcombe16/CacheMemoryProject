#include "Block.h"
#include <cstring> // For memcpy
#include <stdio.h>
#include <stdbool.h>
#include "Memory.h"

Block::Block(int blockSize, Memory *memoryPointer)
{
    this->blockSize = blockSize;
    this->memoryPointer = memoryPointer;
    isValid = false;
    isDirty = false;
    this->tag = 0;

    byteData = new unsigned char[blockSize];
    updateTimestamp();
}

void Block::setTag(unsigned long tag)
{
    this->tag = tag;
}

unsigned long Block::getTag()
{
    return this->tag;
}
void Block::read(unsigned long blockOffset, unsigned char &data)
{
    if (blockOffset < blockSize)
    {
        data = byteData[blockOffset];
        updateTimestamp();
    }
}

void Block::write(unsigned long blockOffset, unsigned char data)
{
    if (blockOffset < blockSize)
    {
        byteData[blockOffset] = data;
        isDirty = true;
        updateTimestamp();
    }
}

void Block::loadFromMemory()
{
    if (memoryPointer != nullptr)
    {
        std::memcpy(byteData, memoryPointer, blockSize);
        isValid = true;
        isDirty = false;
        updateTimestamp();
    }
}

void Block::saveToMemory()
{
    if (memoryPointer != nullptr && isDirty)
    {
        std::memcpy(memoryPointer, byteData, blockSize);
        isDirty = false;
        updateTimestamp();
    }
}

void Block::updateTimestamp()
{
    timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
}

void Block::display()
{
    printf("Valid: %d  Tag: %d  Dirty: %d  Timestamp: %lu", isValid, isDirty, timestamp);
    for (int i = 0; i < blockSize; i++)
    {
        printf("%02X  ", byteData[i]);
    }
    printf("/n");
}
