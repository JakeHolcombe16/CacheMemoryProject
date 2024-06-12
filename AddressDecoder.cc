#include "AddressDecoder.h"


AddressDecoder::AddressDecoder(unsigned long address,int tagBits, int setIndexBits, int blockOffsetBits){
    this->address = address;
    this->tagBits = address;
    this->setIndexBits = setIndexBits;
    this->blockOffsetBits = blockOffsetBits;
}

int AddressDecoder::getTag(){
    
}
int AddressDecoder::getSetIndex(){

}
int AddressDecoder::getBlockOffset(){

}
int AddressDecoder::addressOfBlock(){

}


