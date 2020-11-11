#ifndef SERIESRESONANTCIRCUIT_H
#define SERIESRESONANTCIRCUIT_H
#include "ResonantCircuit.h"
#include <iostream>

using namespace std;

// note i didn't comment this one becuase it's
// more or less the same as ParallelResonantCircuit.h

class SeriesResonantCircuit : public ResonantCircuit {
public:
  SeriesResonantCircuit();
  SeriesResonantCircuit(double freq, double band, double inGain);
  void designCircuit();
  void display();
};

#endif