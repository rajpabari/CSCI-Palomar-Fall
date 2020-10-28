#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(Term first) {
  // add this term to the vector of terms
  terms.push_back(first);
}

Polynomial::Polynomial() {
  // add a term 0x^0 to the polynomial
  Polynomial(Term(0, 0));
}

void Polynomial::add(Term other) {
  // we need to check each term currently in the polynomial
  for (int i = 0; i < terms.size(); i++) {
    // if the degrees are equal we should just add this term to the existing
    // term with equal degree;
    if (terms[i].getDegree() == other.getDegree()) {
      terms[i].add(other);

      // once we've added it to a term we dont need to check any more
      return;
    }
  }
  // otherwise, we just add the term to the terms vector in the polynomial
  terms.push_back(other);
}

void Polynomial::add(Polynomial other) {

  // for each term in the other polynomial
  for (int i = 0; i < other.terms.size(); i++) {
    // add it to the polynomial
    this->add(other.terms[i]);
  }
}

Polynomial Polynomial::multiply(Polynomial other) {
  Polynomial ans; // the resulting polynomial

  // for every term in the first polynomial
  for (int i = 0; i < this->terms.size(); i++) {
    for (int j = 0; j < other.terms.size(); j++) {

      // multiply it by every term in the second polynomial
      // and then add that term to the resulting polynomial
      ans.add(this->terms[i].multiply(other.terms[j]));
    }
  }

  // return the resulting polynomial
  return ans;
}

string Polynomial::toString() {
  string ans = ""; // resulting string to return

  // for every term in the polynomial
  for (int i = 0; i < terms.size(); i++) {

    // if the coefficient is 0 we dont need to print that term
    // so just continue ie. move on to the next term
    if (terms[i].getCoefficient() == 0)
      continue;

    // if it's a positive coefficient and it's not the first term being printed,
    // add a plus sign to signify adding
    if (i != 0 && terms[i].getCoefficient() > 0)
      ans += "+";

    // degree 0 is a constant, degree 1 is just x
    // this formats the term as coefficientx^degree
    if (terms[i].getDegree() != 0 && terms[i].getDegree() != 1)
      ans += to_string(terms[i].getCoefficient()) + "x^" +
             to_string(terms[i].getDegree()) + " ";

    // if it's degree 0 we just output the coefficent because it's a constant
    else if (terms[i].getDegree() == 0)
      ans += to_string(terms[i].getCoefficient()) + " ";

    // if it's degree 1 we output x instead of x^1
    else
      ans += to_string(terms[i].getCoefficient()) + "x ";
  }
  return ans;
}