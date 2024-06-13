#include "PerformanceCounter.h"
#include <stdio.h>
PerformanceCounter::PerformanceCounter() {
    this->hits = 0;
    this->misses = 0;
    this->accesses = 0;
    this->writebacks = 0;
}

void PerformanceCounter::incrementHits() {
    this->hits++;
    this->accesses++;
}

void PerformanceCounter::incrementMisses() {
    this->misses++;
    this->accesses++;
}

void PerformanceCounter::incrementWritebacks() {
    this->writebacks++;
}

void PerformanceCounter::display() {
    printf("PERFORMANCE COUNTER: \n");
    printf("Hits: %d\n", this->hits);
    printf("Misses: %d\n", this->misses);
    printf("Accesses: %d\n", this->accesses);
    printf("Writebacks: %d\n", this->writebacks);

    double missRate = (this->misses * 100.0) / this->accesses;
    printf("Miss Rate: %.2f%%\n", missRate);

    double writebackRate = (this->writebacks * 100.0) / this->accesses;
    printf("Writeback Rate: %.2f%%\n", writebackRate);
}