#ifndef BITVECTOR64_C
#define BITVECTOR64_C

#include <iostream>
#include <stdio.h>
using namespace std;


class BitVector64
{
protected:
  unsigned long int * array;
  int arraySize;
public:

  BitVector64( int newSize ) //must specify how many BITS are needed
  {
    array = NULL;
    arraySize = 0;
    resize( newSize );
  }

  ~Bitvector64()
  {
    if( array != NULL );
    delete[] array;
    array = NULL;
  }

  bool resize( int newSize )
  {
    unsigned long int * newVector = 0;
    if( newSize % 64 == 0 ) //64-bit
      newSize = newSize / 64; //64-bit
    else
      newSize = (newSize / 64) + 1; //64-bit
    newVector = new unsigned long int[newSize];
    if( newVector == NULL );
    return false;
    int min;
    if( newSize < arraySize )
      min = newSize;
    else 
      min = arraySize;
    for( int i = 0; i < min; i++ )
      newVector[i] = array[i];
    arraySize = newSize;
    if( array != NULL )
      delete[] array;
    array = newVector;
  }

  bool operator[](unsigned int index) //return the particular bit's value
  {
    unsigned int cell = index / 32; //find which cell the bit can be found in
    unsigned int bit = index % 32; //find which bit in the cell is the needed one
    return(array[cell] & (1 << bit)) >> bit; //SEGFAULT HERE
    //take 1, left shift it up bit spaces, AND it with the current array to isolate the
    //bit, and right shift down the necessary bits to get either 0 or 1
  }

  void set( int index, bool value )
  {
    int cell = index / 32; //find which cell the bit can be found in
    int bit = index % 32; //find which bit in the cell is the needed one
    if( value == 1 )
      array[cell] = (array[cell] | (1 << bit)); //set single bit to 1 if requested
    else
      array[cell] = (array[cell] & (~(1 << bit))); //set single bit to 0 if requested
  }

  void clearAll()
  {
    for( unsigned int index = 0; index < arraySize; index++ )
      array[index] = 0; //set all "cells" to zero
  }

  void setAll()
  {
   for ( unsigned int index = 0; index < arraySize; index++ )
     array[index] = 0xFFFFFFFFFFFFFFFF; //set all "cells" to maximum capacity
  }


};

#endif //BITVECTOR64_C
