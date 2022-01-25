#ifndef PARALLELRESONANTCIRCUIT_H
#define PARALLELRESONANTCIRCUIT_H
#include "ResonantCircuit.h"
#include <iostream>

using namespace std;

class ParallelResonantCircuit : public ResonantCircuit {
public:
  // Default constructor, sets frequency bandwidth and gain to 0
  ParallelResonantCircuit();
  // Overloaded constructor, has user supplied values in constructor
  // calls initValues from ResonantCircuit
  // @param freq the frequency to set it to
  // @param band the bandwith to set
  // @param inGain the gain to set
  ParallelResonantCircuit(double freq, double band, double inGain);

  // Initialize resistance, capacitance, and inductance based on prompt formulas
  // This implements the virtual void from ResonantCircuit
  void designCircuit();

  // Display all calculated values
  // Needs to be overriden because ResonantCircuit::display() only shows
  // frequency, bandwidth, and gain
  void display();
};

#endif