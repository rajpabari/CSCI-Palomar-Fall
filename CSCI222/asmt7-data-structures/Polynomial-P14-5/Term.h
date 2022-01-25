#ifndef TERM_H
#define TERM_H

class Term {
public:
  // Constructs a term with a coefficient and a degree
  // @param int coeff the coefficient of the term
  // @param int deg the degree of the term
  // @return none
  Term(int coeff, int deg);

  // Adds this by another term
  // Precondition: degrees of the terms are equal,
  // otherwise it doesn't make sense to be adding them in the first place
  // @param const Term other a term to add to this
  // @return none
  void add(const Term other);

  // Multiplies this by another term
  // @param const Term other another term to multiply this by
  // @return Term the product of this and the other term
  Term multiply(const Term other);

  // Returns the coefficient of the term
  // @param none
  // @return int the coefficient of the term
  int getCoefficient();

  // Returns the degree of the term
  // @param none
  // @return int the degree of the term
  int getDegree();

private:
  int coefficient;
  int degree;
};

#endif