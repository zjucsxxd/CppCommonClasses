#include <iostream>
#include "BitVector64.C"
#include <gtest/gtest.h>
using namespace std;

#define NUM_OF_BITS = 128; // any number can be chosen but multiples of 64 are most useful




void print() const;


int main(int argc, char *argv[]))
{
  testing::InitGoogleTest(&argc, argv);


  BitVector64 bitVec(NUM_OF_BITS);
  bitVec.setAll();
  print(bitVec); // test manually if any test fails
  return RUN_ALL_TESTS();
}


TEST(BitVector64Test, AbstractOperations)
{
  BitVector64 bitVec(NUM_OF_BITS);
  bitVec.setAll();
  ASSERT_EQ(0, bitVec & (2^NUM_OF_BITS));
  bitVec.setAll();

  
}

TEST(BitVector64Test, AccessSingleBit)
{
  BitVector64 bitVec(NUM_OF_BITS);
  bitVec.setAll();


}

TEST(BitVector64Test, Resize)
{ 
  BitVector64 bitVec(NUM_OF_BITS);
  bitVec.setAll();


}


void print(BitVector64& vec) const
{
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
}


  int notes()
  {
    cout << "BitVectors\n";
    cout << "  \"storing particular data in particular bits\"\n";

    cout << "\nPress enter to continue reading notes\n";
    getchar();

    cout << "\nSince processors can only process 32 (or 64 in my case) bit packets, you can store and manipulate data much faster in bitvectors";

    cout << "\nFor my computer, unsigned long ints are 64-bits long\n";
    getchar();

    cout << "\nThis implementation is an array of 64-bit bitvectors.  You need more than 64 bits, look in the next array cell\n";
    getchar();

    cout << "\nRetrieving an individual bit:\n";
    cout << "1. Find the correct index; divide index by 64.If you want bits 0-63, look in cell one.";
    cout << "\n     If  you want bits 64-126, look in the second.  Pattern continues\n";
    cout << "2.Retrive the bit;\n";
    return 0;
  }
