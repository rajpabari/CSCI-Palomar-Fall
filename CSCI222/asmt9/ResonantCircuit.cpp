#include "ResonantCircuit.h"

// most of this code is obvious getters and setters

void ResonantCircuit::setFrequency(double freq) {
  frequency = freq;
  // every time a value is set, the circuit design changes
  // the circuit design calcs need to be redone because everything is
  // dependent on frequency, bandwidth, and gain
  designCircuit();
}
void ResonantCircuit::setBandwidth(double band) {
  bandwidth = band;
  designCircuit();
}
void ResonantCircuit::setGain(double inGain) {
  gain = inGain;
  designCircuit();
}
void ResonantCircuit::initValues(double freq, double band, double inGain) {
  // set all variables
  setFrequency(freq);
  setBandwidth(band);
  setGain(inGain);
}
double ResonantCircuit::getFrequency() { return frequency; }
double ResonantCircuit::getBandwidth() { return bandwidth; }
double ResonantCircuit::getGain() { return gain; }

void ResonantCircuit::display() {

  // display all info rounded to 3 decimal places
  cout << "Resonant Circuit Info:" << endl;
  cout << "Frequency: " << fixed << setprecision(3) << frequency << endl;
  cout << "Bandwidth: " << fixed << setprecision(3) << bandwidth << endl;
  cout << "Gain: " << fixed << setprecision(3) << gain << endl;
}