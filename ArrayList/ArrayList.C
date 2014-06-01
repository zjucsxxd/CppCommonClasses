#ifndef ARRAYLIST_C
#define ARRAYLIST_C

#include <iostream>
#include <stdio.h>
using namespace std;

template<class DataType>
class ArrayList
{
private:
  DataType * array;
  unsigned int arraySize;
public:
  ArrayList( unsigned int newSize )
  {
    array = new DataType[newSize];
    arraySize = newSize;
  }

  ~ArrayList()
  {
    if( array != NULL )
      delete[] array;
    array = NULL;
  }


  bool resize( int newSize )
  {
    DataType newArray = new DataType[newSize];
    if( newArray == NULL )
      return false;
    int min;
    if( newSize < arraySize )
      min = newSize;
    else
      min = arraySize;
    for( int i = 0; i < min; i++ )
      newArray[i] = array[i];
    arraySize = newSize;
    if( array != NULL )
      delete[] array;
    array = newArray;
    return true;
  }

  void insert( DataType newItem, int insertIndex )
  {
    for( int i = (arraySize - 1); i > insertIndex; i-- )
      array[i] = array[ i-1 ];
    array[insertIndex] = newItem;
  }

  void remove( int removeIndex )
  {
    for( int i = removeIndex + 1; i < arraySize; i++ )
      array[ i-1 ] = array[i]; //one less step than explicitly deleting the contents of cell
  }


  /*Overloaded Operators*/
  DataType& operator[] ( int index )
  {
    return array[index];
  }

  /*The Conversion Operator--Convert ArrayList to c++ array-- USED AS GETTER*/
  operator DataType* ()
  {
    return array;
  }

  /*the other getter-- getSize of array*/
  int getSize()
  {
    return arraySize;
  }

  /*Saving array to Disk
    uses C functions
    MUST ONLY BE USED TO STORE VALUES; NO POINTERS*/

  bool writeFile( const char * fileName )
  {
    FILE* outFile = NULL;
    int written = 0;
    outFile = fopen( fileName, "wb" ); //"write binary" option overwrites existing data is file
    if( outFile == 0 )
      return false;
    written = fwrite( array, sizeof( DataType ), arraySize, outFile );
    fclose( outFile );
    if( written != arraySize )
      return false;
    return true;
  }

  /*Reading an array from Disk
    also uses C functions
    BEWARE OF FILES THAT MAY CONTAIN POINTERS INSTEAD OF VALUES*/

  bool readFile( const char* fileName )
  {
    FILE* inFile = NULL;
    int read = 0;
    inFile = fopen( fileName, "rb" ); //"read binary"
    if( inFile == 0 )
      return false;
    read = fread( array, sizeof( DataType ), arraySize, inFile );
    fclose( inFile );
    if( read != arraySize )
      return false;
    return true;
  }

};

#endif //ARRAYLIST_C
