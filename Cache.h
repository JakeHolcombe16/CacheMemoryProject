#ifndef CACHE_H
#define CACHE_H
#include "Memory.h"

class Cache
{
private:
    Memory *memoryPointer;
    int cacheSize;
    int blockSize;
    int setAssociativity;

public:
    // constructor
    Cache(Memory *memoryPointer, int cacheSize, int blockSize; int setAssociativity);

    // methods
    void write(unsigned long address);
    void read(unsigned long address);
    void display();
};

#endif