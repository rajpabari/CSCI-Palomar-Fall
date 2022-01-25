#ifndef RESONANTCIRCUIT_H
#define RESONANTCIRCUIT_H
#include <iomanip>
#include <iostream>

using namespace std;

class ResonantCircuit {
public:
  // Initialize all values (calls setters)
  // @param freq the frequency to set it to
  // @param band the bandwith to set
  // @param inGain the gain to set
  void initValues(double freq, double band, double inGain);
  // Set the frequency to freq
  // @param freq the frequency to set
  void setFrequency(double freq);

  // Set the bandwidth to band
  // @param band the bandwidth to set
  void setBandwidth(double band);

  // Set the gain to inGain
  // @param inGain the gain to set
  void setGain(double inGain);

  //@return the frequency of the circuit
  double getFrequency();
  //@return the bandwidth of the circuit
  double getBandwidth();
  //@return the gain of the circuit
  double getGain();

  // Display the frequency, bandwidth, gain of Resonant Circuit
  void display();

  // Depending on circuit type, initialize resistance, capacitance, inductance
  virtual void designCircuit() = 0;

  // Note on the protected variables...
  // I thought that it would make sense from an OOP perpsective to make these
  // protected because every circuit has a resistance, capacitance, inductance
  // and every derived class must have a designCircuit() to initialize them
  // so I think they should be able to access the variables themselves
protected:
  double resistance;
  double capacitance;
  double inductance;

private:
  double frequency;
  double bandwidth;
  double gain;
};

#endif