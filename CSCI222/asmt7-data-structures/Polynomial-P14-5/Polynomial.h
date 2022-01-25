#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"
#include <string>
#include <vector>

using namespace std;

class Polynomial {
public:
  // Constructs an empty polynomial
  // @param none
  // @return none
  Polynomial();

  // Constructs a polynomial with one term in it
  // @param Term first the first term to put in the polynomial
  // @return none
  Polynomial(Term first);

  // Adds a term to the original polynomial
  // @param Term other the term to add to the original polynomial
  // @return none
  void add(Term other);

  // Adds each term of another polynomial to the original polynomial
  // @param Polynomial other the polynomial to add to the original polynomial
  // @return none
  void add(Polynomial other);

  // Multiplies a polynomial by another
  // @param Polynomial other the polynomial to multiply by the this pointer
  // @return Polynomial ans the resulting polynomial when the two polynomials
  // are multiplied
  Polynomial multiply(Polynomial other);

  // Gets the string representation of the polynomial
  // @param none
  // @return string a string with each term of the polynomial
  string toString();

private:
  vector<Term> terms; // stores each term of the polynomial
};

#endif