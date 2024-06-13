#include "Block.h"
#include <cstring> // For memcpy

Block::Block(int blockSize, unsigned char *memoryPointer)
{
    this->blockSize = blockSize;
    this->memoryPointer = memoryPointer;
    isValid = false;
    isDirty = false;

    byteData = new unsigned char[blockSize];
    updateTimestamp();
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
}
