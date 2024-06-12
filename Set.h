#ifndef SET_H
#define SET_H

Set{
    private:

    int numBlocks;
    int blockSize;
    
    Memory* memoryPointer;
    AddressDecoder addressDecoder;

    public:

    void read(unsigned long address);
    void write(unsigned long address);
    void display();

}