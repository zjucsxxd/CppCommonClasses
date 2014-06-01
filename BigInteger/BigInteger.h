/*
 *Array-of-integer that is used to easily compute arithmetic of VERY large integers
 *
 *Implemention?  - More and more Bitvectors used to achieve 2^n precision?
 *               - Dynamic Arrays
 *               - Arrays
 *               * The hard part is the operations performed on each ADS    
 */

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <string>

class BigInteger
{
 public:
  BigInteger();
  ~BigInteger(); //if using dynamic arrays this is necessary
  BigInteger operator + (const BigInteger& n2);
  BigInteger operator - (const BigInteger& n2);
  BigInteger operator * (const BigInteger& n2);
  BigInteger operator / (const BigInteger& n2);
  BigInteger operator % (const BigInteger& n2);
  /*compareTo returns 1 if calling object is greater than passed object, 0 if equal to, and -1 if less than.
   */
  int compareTo(const BigInteger& n2); 
  const BigInteger operator - () const; //allows negation using unary -
  bool operator == (const BigInteger& n2);
  BigInteger operator = (const BigInteger& n);
  std::string toString (const BigInteger& n);
 private:

};

#endif //BIGINTEGER_H
