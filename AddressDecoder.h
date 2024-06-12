#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

AddressDecoder{
    private:
    unsigned long address;
    int tagBits;
    int setIndexBits;
    int blockOffsetBits;

    public:
    AddressDecoder(unsigned long address,int tagBits, int setIndexBits, int blockOffsetBits);
    int getTag();
    int getSetIndex();
    int getBlockOffset();
    int addressOfBlock();
};

#endif




