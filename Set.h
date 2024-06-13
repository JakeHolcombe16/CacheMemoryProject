#ifndef SET_H
#define SET_H
#include "AddressDecoder.h"
#include "memory.h"
#include "Block.h"

class Set
{
private:
    int numBlocks;
    int blockSize;
    Block **setBlocks;

    Memory *memoryPointer;
    AddressDecoder addressDecoder;

public:
    Set(int numBlocks, int blockSize, Memory *memoryPointer, AddressDecoder addressDecoder);
    void read(unsigned long address);
    void write(unsigned long address);
    bool isLoaded(unsigned long address);
    void display();
};

#endif