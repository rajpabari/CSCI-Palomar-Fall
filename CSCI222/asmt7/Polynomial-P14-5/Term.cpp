#include "Term.h"

Term::Term(int coeff, int deg) {
  // set the private member variables equal to the arguments
  coefficient = coeff;
  degree = deg;
}

int Term::getCoefficient() { return coefficient; }
int Term::getDegree() { return degree; }

void Term::add(const Term other) {
  // add the other coefficient to the coefficient of this
  this->coefficient += other.coefficient;
}

Term Term::multiply(const Term other) {
  // this is how monomial multiplication works
  // multiply the coefficients and add the degrees
  // make a term that does that calculation, and return it
  return Term(coefficient * other.coefficient, degree + other.degree);
}