#include "Stats.h"
#include <cstdio>

Stats::Stats() {
  instruction_count = 0;
  unmaps = 0;
  maps = 0;
  ins = 0;
  outs = 0;
  zeros = 0;
  total_cost = 0;
}

void Stats::incrementUnmaps() {
  unmaps++;
  total_cost += 400;
}

void Stats::incrementMaps() {
  maps++;
  total_cost += 400;
}

void Stats::incrementIns() {
  ins++;
  total_cost += 3000;
}

void Stats::incrementOuts() {
  outs++;
  total_cost += 3000;
}

void Stats::incrementZeros() {
  zeros++;
  total_cost += 150;
}

void Stats::incrementTotalCost() {
  total_cost += 1;
}

void Stats::incrementInstructionCount() {
  instruction_count += 1;
}

void Stats::printSummary() {
  std::printf("SUM %lld U=%lld M=%lld I=%lld O=%lld Z=%lld ===> %llu\n",
  instruction_count, unmaps, maps, ins, outs, zeros, total_cost);
}
