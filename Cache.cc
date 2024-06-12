#include <stdio.h>
#include "Cache.h"
#include "Memory.h"


Cache::Cache(Memory* memoryPointer,int cacheSize, int blockSize, int setAssociativity){
    this->memoryPointer = memoryPointer;
    this->cacheSize = cacheSize;
    this->blockSize = blockSize;
    this-> setAssociativity = setAssociativity;
    
    int amountOfSets = cacheSize/setAssociativity;
    int* sets[amountOfSets];
}


void Cache::write(unsigned long address){

}
void Cache::read(unsigned long address){

}
void Cache::display(){
    printf("CACHE: /n");
    for(int i = 0; i < amountOfSets; i++){
        printf("Set: %d/n  Blocks/n",i);
        for(int j = 0; j < setAssociativity; j++){
            printf("%d:/n",j);
        }
    }
}
