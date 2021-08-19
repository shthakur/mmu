#ifndef Stats_h
#define Stats_h

class Stats {

private:
  unsigned long long instruction_count;
  unsigned long long unmaps;
  unsigned long long maps;
  unsigned long long ins;
  unsigned long long outs;
  unsigned long long zeros;
  unsigned long long total_cost;
public:
  Stats();
  void incrementInstructionCount();
  void incrementUnmaps();
  void incrementMaps();
  void incrementIns();
  void incrementOuts();
  void incrementZeros();
  void incrementTotalCost();
  void printSummary();
};

#endif
