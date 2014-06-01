#ifndef BIGINTEGER_C
#define BIGiNTEGER_C

#include <iostream>
#include <string>

using namespace std;

#include "BigInteger.h"

BigInteger::BigInteger()
{
  cout << "\"default object instantiated\"\n";
}

BigInteger::~BigInteger()
{
  cout << "\"object deconstructed\"\n";
}

int main()
{
  cout << "~Test Driver for BigInteger Class~\n";
  BigInteger b1;
}
#endif //BIGINTEGER_C
