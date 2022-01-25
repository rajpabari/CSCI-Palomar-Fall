#include "ParallelResonantCircuit.h"

void ParallelResonantCircuit::designCircuit() {
  // apply formulas from prompt to calculate circuit values
  resistance = getFrequency();
  capacitance = 1.0 / (getBandwidth() * resistance);
  inductance = 1.0 / (getGain() * getGain() * capacitance);
}

void ParallelResonantCircuit::display() {
  cout << "Parallel "; // to differentiate between series and parallel circuit
  // display frequency, bandwidth, and gain
  ResonantCircuit::display();

  // output rounded to 3 decimal places
  cout << "Resistance: " << fixed << setprecision(3) << resistance << endl;
  cout << "Inductance: " << fixed << setprecision(3) << inductance << endl;
  cout << "Capacitance: " << fixed << setprecision(3) << capacitance << endl;
}

ParallelResonantCircuit::ParallelResonantCircuit(double freq, double band,
                                                 double inGain) {
  initValues(freq, band, inGain);
}
ParallelResonantCircuit::ParallelResonantCircuit() {
  ParallelResonantCircuit(0.0, 0.0, 0.0);
}
