#include "AddressDecoder.h"
#include <cmath>

AddressDecoder::AddressDecoder(int numSets, int blockSize)
{
    this->numSets = numSets;
    this->blockSize = blockSize;

    this->blockOffsetBits = static_cast<int>(std::log2(numSets));
    this->blockOffsetBits = static_cast<int>(std::log2(blockSize));
}

AddressInfo AddressDecoder::decode(unsigned long address)
{
    AddressInfo info;

    info.blockOffset = address & ((1 << blockOffsetBits) - 1);
    info.setIndex = (address >> blockOffsetBits) & ((1 << setIndexBits) - 1);
    info.tag = address >> (blockOffsetBits + setIndexBits);

    return info;
}
