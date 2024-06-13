#include "Set.h"
#include <stdio.h>
#include "Block.h"

Set::Set(int numBlocks, int blockSize, Memory *memoryPointer, AddressDecoder addressDecoder)
{
    this->numBlocks = numBlocks;
    this->blockSize = blockSize;
    this->memoryPointer = memoryPointer;
    this->addressDecoder = addressDecoder;

    setBlocks = new Block *[blockSize];
    for (int i = 0; i < this->numBlocks; i++)
    {
        setBlocks[i] = new Block(this->blockSize, this->memoryPointer);
    }
}

void Set::read()
{
}

void Set::write()
{
}

void Set::display()
{
    printf("Blocks /n");
    for (int i = 0; i < numBlocks; i++)
    {
        printf("%d:/n", i);
        setBlocks[i]->display();
        printf("/n");
    }
}