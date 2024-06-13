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
    void read(unsigned long blockOffset, unsigned char &data);
    void write(unsigned long blockOffset, unsigned char data);
    void loadFromMemory();
    void saveToMemory();
    void updateTimestamp();
    void display();
    void setTag(unsigned long tag);
};

#endif