#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H

class PerformanceCounter
{
private:
    int hits;
    int misses;
    int accesses;
    int writebacks;

public:
    PerformanceCounter();
    void incrementHits();
    void incrementMisses();
    void incrementWritebacks();
    void display();
    int getHits();
    int getMisses();
    int getWritbacks();
};

#endif