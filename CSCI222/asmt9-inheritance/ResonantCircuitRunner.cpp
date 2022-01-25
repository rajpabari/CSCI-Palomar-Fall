#include "ParallelResonantCircuit.h"
#include "SeriesResonantCircuit.h"
#include <iostream>

using namespace std;

int main() {
  // driver class to test the series and parallel resonant circuits
  cout << "-------" << endl;
  // use overloaded constructor and display values
  SeriesResonantCircuit seriesResonantCircuit(10.0, 20.0, 30.0);
  seriesResonantCircuit.display();
  cout << endl << endl;

  // change a value to make sure all other necessary values change
  seriesResonantCircuit.setBandwidth(40.0);
  seriesResonantCircuit.display();

  cout << "-------" << endl;
  // use overloaded constructor and display values
  ParallelResonantCircuit parallelResonantCircuit(10.0, 20.0, 30.0);
  parallelResonantCircuit.display();
  cout << endl << endl;
  // change a value to make sure all other necessary values change
  parallelResonantCircuit.setBandwidth(40.0);
  parallelResonantCircuit.display();

  return 0;
}