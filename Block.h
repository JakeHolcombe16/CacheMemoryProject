#ifndef BLOCK_H
#define BLOCK_H

#include <chrono>

class Block
{
private:
    int blockSize;
    unsigned char *memoryPointer;
    unsigned char *byteData;
    int tag;
    bool isValid;
    bool isDirty;

    std::chrono::high_resolution_clock m_clock;
    long timestamp;

public:
    Block(int blockSize, unsigned char *memoryPointer);
    void read(unsigned long blockOffset, unsigned char &data);
    void write(unsigned long blockOffset, unsigned char data);
    void loadFromMemory();
    void saveToMemory();
    void updateTimestamp();
    void display();
};

#endif