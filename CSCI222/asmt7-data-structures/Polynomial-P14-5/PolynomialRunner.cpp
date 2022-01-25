#include "Polynomial.h"
#include "Term.h"
#include <iostream>

using namespace std;

int main() {
  // make polynomial p(x) using default constructor
  Polynomial p;

  // add terms 5x^10 and 9x^7 to the polynomial
  p.add(Term(5, 10));
  p.add(Term(9, 7));

  // print it out
  cout << "Polynomial p(x): " << p.toString() << endl;

  // make polynomial q(x) using overloaded constructor with one term to start
  // with -x
  Polynomial q(Term(-1, 1));
  // add terms -10, 3x^2, and x^10 to the polynomial
  q.add(Term(-10, 0));
  q.add(Term(3, 2));
  q.add(Term(1, 10));

  // print q(x) out
  cout << "Polynomial q(x): " << q.toString() << endl;

  // add q to p
  p.add(q);
  // print it out
  cout << "Polynomial p(x) + q(x): " << p.toString() << endl;

  // multiply p by itself
  Polynomial r = p.multiply(p);

  // print out the resulting polynomial
  cout << "Polynomial (p(x) + q(x)) * (p(x) + q(x)): " << r.toString() << endl;
  return 0;
}