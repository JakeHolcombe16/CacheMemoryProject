#ifndef BLOCK_H
#define BLOCK_H

#include <chrono>
#include "memory.h"

class Block
{
private:
    int blockSize;
    Memory *memoryPointer;
    unsigned char *byteData;
    unsigned long tag;
    bool isValid;
    bool isDirty;

    std::chrono::high_resolution_clock m_clock;
    long timestamp;

public:
    Block(int blockSize, Memory *memoryPointer);
    unsigned char read(unsigned long blockOffset);
    void write(unsigned long blockOffset, unsigned char data);
    void loadFromMemory(unsigned long address);
    void saveToMemory(unsigned long address);
    void updateTimestamp();
    void display();
    void setTag(unsigned long tag);
    unsigned long getTag();
    bool isBlockValid();
    bool isBlockDirty();
    long getTimestamp();
};

#endif