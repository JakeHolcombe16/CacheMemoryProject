#include <stdio.h>
#include "Cache.h"
#include "Memory.h"

Cache::Cache(Memory *memoryPointer, int cacheSize, int blockSize, int setAssociativity)
{
    this->memoryPointer = memoryPointer;
    this->cacheSize = cacheSize;
    this->blockSize = blockSize;
    this->setAssociativity = setAssociativity;

    this->amountOfSets = cacheSize / (blockSize * setAssociativity);
    this->sets[amountOfSets];
}

void Cache::write(unsigned long address, unsigned char data)
{
}
unsigned char Cache::read(unsigned long address)
{
}
void Cache::display()
{
    printf("CACHE: \n");
    for (int i = 0; i < amountOfSets; i++)
    {
        printf("Set %d\n", i);
        int *currentSet;
        currentSet = sets[i];
        currentSet->display();
    }
}
