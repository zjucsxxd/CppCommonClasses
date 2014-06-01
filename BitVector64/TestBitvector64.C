#include <iostream>
#include "Bitvector64.C"
using namespace std;

void printBitvector( const Bitvector64& vec, int size );

int main( )
{
  const int NUM_OF_BITS = 128;
  Bitvector64 bitVec(NUM_OF_BITS); //must specify how many BITS are needed
  bitVec.setAll( );
  int lineCount = 0;
  for ( int i = 0; i < NUM_OF_BITS; i++ )
    {
      cout << bitVec[i] << " ";
      ++lineCount;
      if ( lineCount == 8 )
        {
          cout << "\n";
          lineCount = 0;
        }
    }

  return 0;
}
