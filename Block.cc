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
    this->timestamp = 0;

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

bool Block::isBlockValid()
{
    return this->isValid;
}

bool Block::isBlockDirty()
{
    return this->isDirty;
}

long Block::getTimestamp()
{
    return this->timestamp;
}
unsigned char Block::read(unsigned long blockOffset)
{
    updateTimestamp();
    return byteData[blockOffset];
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

void Block::loadFromMemory(unsigned long address)
{
    for (int i = 0; i < blockSize; i++)
    {
        byteData[i] = memoryPointer->getByte(address + i);
    }

    isValid = true;
    isDirty = false;
    updateTimestamp();
}

void Block::saveToMemory(unsigned long address)
{
    for (int i = 0; i < blockSize; i++)
    {
        memoryPointer->setByte(address + i, byteData[i]);
    }
    isDirty = false;
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
