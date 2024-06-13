testCache: Simulation.o Memory.o Cache.o Set.o Block.o AddressDecoder.o PerformanceCounter.o
	g++ Simulation.o Memory.o Cache.o Set.o Block.o AddressDecoder.o PerformanceCounter.o -o test 
	./test

Simulation.o: Simulation.cc Memory.h Cache.h
	g++ Simulation.cc -c

Memory.o: Memory.cc Memory.h
	g++ Memory.cc -c

Cache.o: Cache.cc Cache.h Set.h AddressDecoder.h PerformanceCounter.h
	g++ Cache.cc -c

Set.o: Set.cc Set.h Block.h Memory.h PerformanceCounter.h
	g++ Set.cc -c

Block.o: Block.cc Block.h Memory.h
	g++ Block.cc -c

AddressDecoder.o: AddressDecoder.cc AddressDecoder.h
	g++ AddressDecoder.cc -c

PerformanceCounter.o: PerformanceCounter.cc PerformanceCounter.h
	g++ PerformanceCounter.cc -c

clean:
	rm -f *.o
	rm -f testCache
