#include <iostream>
using namespace std;
#include "Person.h"
#include "ArrayList.C"
#include "Bitvector64.C"


int main()
{
  ArrayList<Person> people( 2 ); 
  cout << "\n\nHi " << people[0].getName() << "!\n";

  return 0;
}

