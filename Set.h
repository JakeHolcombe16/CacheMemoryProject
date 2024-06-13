#ifndef SET_H
#define SET_H
#include "AddressDecoder.h"
#include "Memory.h"
#include "Block.h"
#include "PerformanceCounter.h"

class Set
{
private:
    int numBlocks;
    int blockSize;
    Block **setBlocks;

    Memory *memoryPointer;
    PerformanceCounter *p;

public:
    Set(int numBlocks, int blockSize, Memory *memoryPointer, PerformanceCounter *p);
    unsigned char read(unsigned long tag, unsigned long blockOffset, Memory *memory);
    void write(unsigned long tag, unsigned long blockOffset, Memory *memory, unsigned char data);
    bool isLoaded(unsigned long address);
    Block *findBlock(unsigned long tag);
    void display();
    Block *LRUBlock();
    void updateLRU(Block *b);
    void loadAndSet(unsigned long blockOffset, unsigned long tag, Block *block);
};

#endif