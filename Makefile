CC=g++52 # pick the correct version CXX is for the g++ compiler
CFLAGS=-g -std=c++11 -static-libstdc++ # -g = debug, -O2 for optimized code CPPFLAGS for g++
MODULES=$(wildcard modules/*.cpp)
ALGOS=$(wildcard algorithms/*.cpp)

mmu: main.cpp modules/constants.h $(MODULES) $(ALGOS)
	$(CC) $(CFLAGS) -o mmu main.cpp modules/constants.h $(MODULES) $(ALGOS)

clean:
	rm -f mmu
