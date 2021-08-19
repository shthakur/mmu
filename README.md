# Memory Management Unit

Implementation of Memory Management Unit which handles all the paging from page faults to page write

## Compilation and Running

Compile using `make` command and it will generate a new binary `mmu` in the main folder.

Run it using following pattern:

> ./mmu [-a<algo>] [-o<options>] [–f<num_frames>] inputfile randomfile

All output will go to stdout.

## Structure

```
├── algorithms
│   ├── AgingAlgo.cpp
│   ├── AgingAlgo.h
│   ├── BaseAlgo.cpp
│   ├── BaseAlgo.h
│   ├── ClockAlgo.cpp
│   ├── ClockAlgo.h
│   ├── FIFOAlgo.cpp
│   ├── FIFOAlgo.h
│   ├── NRUAlgo.cpp
│   ├── NRUAlgo.h
│   ├── RandomAlgo.cpp
│   ├── RandomAlgo.h
│   ├── SecondChanceAlgo.cpp
│   └── SecondChanceAlgo.h
├── main.cpp
├── Makefile
├── modules
│   ├── Args.cpp
│   ├── Args.h
│   ├── constants.h
│   ├── Entry.cpp
│   ├── Entry.h
│   ├── FileReader.cpp
│   ├── FileReader.h
│   ├── FrameTable.cpp
│   ├── FrameTable.h
│   ├── Instruction.cpp
│   ├── Instruction.h
│   ├── Simulator.cpp
│   ├── Simulator.h
│   ├── Stats.cpp
│   ├── Stats.h
│   ├── utils.cpp
│   └── utils.h
└── README.md
```
