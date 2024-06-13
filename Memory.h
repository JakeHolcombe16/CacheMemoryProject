#ifndef MEMORY_H
#define MEMORY_H

class Memory
{
public:
    // Constructor
    Memory(int memorySize);

    // Methods
    // unsigned char* getByte(unsigned long address);
    unsigned char getByte(unsigned long address);
    void setByte(unsigned long address, unsigned char byte);
    int getMemorySize();
    void display();

private:
    int memorySize;
    unsigned char *memoryPointer;
};

#endif
