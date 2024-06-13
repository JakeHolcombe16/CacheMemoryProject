#include <stdio.h>
#include "Cache.h"
#include "Memory.h"

Cache::Cache(Memory *memoryPointer, int cacheSize, int blockSize, int setAssociativity)
{
    this->memoryPointer = memoryPointer;
    this->cacheSize = cacheSize;
    this->blockSize = blockSize;
    this->setAssociativity = setAssociativity;
    performanceCounter = new PerformanceCounter();
    amountOfSets = cacheSize / (blockSize * setAssociativity);
    sets = new Set *[amountOfSets];
    for (int i = 0; i < amountOfSets; i++)
    {
        sets[i] = new Set(setAssociativity, blockSize, memoryPointer, performanceCounter);
    }
    addDecode = new AddressDecoder(amountOfSets, blockSize);
}

void Cache::write(unsigned long address, unsigned char data)
{
    AddressInfo in = addDecode->decode(address);

    Set *set = sets[in.setIndex];
    set->write(in.tag, in.blockOffset, memoryPointer, data);
}
unsigned char Cache::read(unsigned long address)
{
    AddressInfo in = addDecode->decode(address);

    Set *set = sets[in.setIndex];
    return set->read(in.tag, in.blockOffset, memoryPointer);
}
void Cache::display()
{
    printf("CACHE: \n");
    for (int i = 0; i < amountOfSets; i++)
    {
        printf("Set: %d\n  Blocks\n", i);
        for (int j = 0; j < setAssociativity; j++)
        {
            sets[i]->display(); // Sets display will call the Blocks display
            printf("%d:\n", j);
        }
    }
}
