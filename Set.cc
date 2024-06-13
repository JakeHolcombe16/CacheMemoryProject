#include "Set.h"
#include <stdio.h>
#include "Block.h"
#include "PerformanceCounter.h"

Set::Set(int numBlocks, int blockSize, Memory *memoryPointer, PerformanceCounter *p)
{
    this->numBlocks = numBlocks;
    this->blockSize = blockSize;
    this->memoryPointer = memoryPointer;
    this->p = p;

    setBlocks = new Block *[numBlocks];
    for (int i = 0; i < this->numBlocks; i++)
    {
        setBlocks[i] = new Block(this->blockSize, this->memoryPointer);
    }
}

Block *Set::findBlock(unsigned long tag)
{
    for (int i = 0; i < numBlocks; i++)
    {
        if (setBlocks[i]->getTag() == tag && setBlocks[i]->isBlockValid())
        {
            return setBlocks[i];
        }
    }

    return nullptr;
}

Block *Set::LRUBlock()
{
    int lruIndex = 0;
    for (int i = 1; i < numBlocks; i++)
    {
        if (setBlocks[i]->getTimestamp() < setBlocks[lruIndex]->getTimestamp())
        {
            lruIndex = i;
        }
    }

    return setBlocks[lruIndex];
}

void Set::updateLRU(Block *b)
{
    b->updateTimestamp();
}

unsigned char Set::read(unsigned long tag, unsigned long blockOffset, Memory *memory)
{
    Block *block = findBlock(tag);

    if (block)
    {
        updateLRU(block);
        p->incrementHits();
        return block->read(blockOffset);
    }
    else
    {   
        p->incrementMisses();
        block = LRUBlock();
        if (block->isBlockDirty())
        {
            p->incrementWritebacks();
            block->saveToMemory((block->getTag() << (blockSize + blockOffset)) | blockOffset);
        }

        loadAndSet(blockOffset, tag, block);

        // read the value and return it
        return block->read(blockOffset);
    }
}

void Set::write(unsigned long tag, unsigned long blockOffset, Memory *memory, unsigned char data)
{
    Block *block = findBlock(tag);

    if (block)
    {
        updateLRU(block);
        p->incrementHits();
        block->write(blockOffset, data);
    }
    else
    {
        block = LRUBlock();
        p->incrementMisses();
        if (block->isBlockDirty())
        {
            p->incrementWritebacks();
            block->saveToMemory((block->getTag() << (blockSize + blockOffset)) | blockOffset);
        }
        // loadAndSet(blockOffset, tag, block);
        loadAndSet(blockOffset, tag, block);
        block->write(blockOffset, data);
    }

    
}

void Set::loadAndSet(unsigned long blockOffset, unsigned long tag, Block *block)
{
    block->loadFromMemory((tag << (blockSize + blockOffset)) | blockOffset);
    block->setTag(tag);
    updateLRU(block);
}

void Set::display()
{
    printf("Blocks \n");
    for (int i = 0; i < numBlocks; i++)
    {
        printf("%d:\n", i);
        setBlocks[i]->display();
        printf("\n");
    }
}