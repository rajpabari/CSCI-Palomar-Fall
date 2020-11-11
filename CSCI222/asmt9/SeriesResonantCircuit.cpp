#include "SeriesResonantCircuit.h"

// note i didn't comment this one becuase it's
// more or less the same as ParallelResonantCircuit.cpp

void SeriesResonantCircuit::designCircuit() {
  // this is the only real difference between Parallel and Series
  // just the formulas change according to the prompt
  resistance = 1.0 / getFrequency();
  inductance = resistance / getBandwidth();
  capacitance = 1.0 / (getGain() * getGain() * inductance);
}

void SeriesResonantCircuit::display() {
  cout << "Series ";
  ResonantCircuit::display();
  cout << "Resistance: " << fixed << setprecision(3) << resistance << endl;
  cout << "Inductance: " << fixed << setprecision(3) << inductance << endl;
  cout << "Capacitance: " << fixed << setprecision(3) << capacitance << endl;
}

SeriesResonantCircuit::SeriesResonantCircuit(double freq, double band,
                                             double inGain) {
  initValues(freq, band, inGain);
}
SeriesResonantCircuit::SeriesResonantCircuit() {
  SeriesResonantCircuit(0.0, 0.0, 0.0);
}
