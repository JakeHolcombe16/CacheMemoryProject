#include <stdio.h>
#include "Memory.h"

Memory::Memory(int memorySize)
{
    this->memorySize = memorySize;

    // creating memory array
    // filling it with temp values
    memoryPointer = new unsigned char[memorySize];
    // this->memoryPointer = memoryPointer;
    for (int i = 0; i < memorySize; i++)
    {
        // memoryArray[i] = i%255;
        memoryPointer[i] = i % 255;
    }
}

// returns byte at a given address
unsigned char Memory::getByte(unsigned long address)
{
    return memoryPointer[address];
}

// sets byte at a given address
void Memory::setByte(unsigned long address, unsigned char byte)
{
    if (address < memorySize)
    {
        memoryPointer[address] = byte;
    }
}
int Memory::getMemorySize()
{
    return memorySize;
}

void Memory::display()
{
    for (int i = 0; i < memorySize; i++)
    {
        printf("%x20  ", memoryPointer[i]);

        // makes a new line every 16 bytes
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
}