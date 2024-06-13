#ifndef CACHE_H
#define CACHE_H
#include "Memory.h"
#include "Set.h"
#include "PerformanceCounter.h"
#include "AddressDecoder.h"

class Cache
{
private:
    Memory *memoryPointer;
    int cacheSize;
    int blockSize;
    int setAssociativity;
    int amountOfSets;
    Set **sets;
    PerformanceCounter *performanceCounter;
    AddressDecoder *addDecode;

public:
    // constructor
    Cache(Memory *memoryPointer, int cacheSize, int blockSize, int setAssociativity);

    // methods
    void write(unsigned long address, unsigned char data);
    unsigned char read(unsigned long address);
    void display();
};

#endif