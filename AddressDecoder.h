#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

struct AddressInfo
{
    unsigned long tag;
    unsigned long setIndex;
    unsigned long blockOffset;
};

class AddressDecoder
{
private:
    int numSets;
    int blockSize;
    int setIndexBits;
    int blockOffsetBits;

public:
    AddressDecoder(int numSets, int blockSize);
    AddressInfo decode(unsigned long address);
};

#endif
