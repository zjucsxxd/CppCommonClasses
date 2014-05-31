// =========================================================

//HW6   Directed Graph Implementation
//Your name: Jeff Bunce
//Complier:  g++ 4.1.2
//File type: implementation file dgraph.C

// Description: This is table-based and slist-based  implmentation
//   of a directe graph.  It can be used to store any type of 
//   data; typedef is set in the header file dgraph.h
//===========================================================


#ifndef DGRAPH_C
#define DGRAPH_C


#include <iostream> // for cout
 #include <fstream> // for ifstream
#include <cctype> /// for toupper
#include "dgraph.h"
using namespace std;

const int dgraph::MAX_TABLE_LENGTH = 28; // STATIC 
                             // WARNING: this number is also hard coded in class
                             //           definition as an array size of Gtable



// Purpose: Initialize data members of dgraph objects
// Parameters Purpose: none
dgraph::dgraph()
{
  currentSlot = 0;

  for( int i = 0; i < MAX_TABLE_LENGTH; i++ )
    {
      Gtable[i].name = ' ';
      Gtable[i].visitNo = 0;
      Gtable[i].outDegree = 0;
    }
}

// Purpose: Destroy dgraph objects; currently unecessary
// Parameters Purpose: none
dgraph::~dgraph()
{
  //implicitly calls destructors of composed lists
}

void dgraph::displayGraph()
{
  string seperator = "*********************\n";
  cout << seperator;
  cout << "Printing the Graph\n";
  slist tmpList;
  for( int i = 0; i < currentSlot; i++ )// currentSlot is also how many slots of
    {                                    //  the table you're using
      cout << Gtable[i].name << " "
	   << Gtable[i].outDegree << " ";
      tmpList = Gtable[i].adjacentOnes;
      for( int j = 0; j < Gtable[i].outDegree; j++ )
	{
	  char adj;
	  tmpList.deleteFront(adj);
	  cout << adj << " ";
	}
      cout << "\n";
    }
  cout << seperator;
}


// Purpose: Find the number of Adjacent vertices easily
// Parameters Purpose: Input the name of the vertex as a char
// Return Values: -1(chosenVertex DNE), any positive int(chosenVertex found)
int dgraph::findOutDegree(char chosenVertex)
{
  int index = binarySearch(chosenVertex);
  if( index == -1 )
    return -1;
  else
    return Gtable[index].outDegree;
}

// Purpose: Fill the table using a very specific file named "table.txt"
// Parameters Purpose: none; it would be good to allow users to pick different
//   file names
void dgraph::fillTable()
{
  
  string fileName = "table.txt";
  ifstream fin;
  fin.open(fileName.c_str());

  //if any problem opening file, then throw EXCEPTION
  if( ! fin.is_open() ) //eg. file is read protected
      throw "ERROR: File could not be opened\n"; 


  //fin successfully opened the file
  while( fin >> Gtable[currentSlot].name ) // first token is NAME
    {
      fin >> Gtable[currentSlot].outDegree; // second token is # ADJACENT VERTICES
	
      for( int i = 0; i < Gtable[currentSlot].outDegree; i++ )
	{
	  el_t anAdjVertex;
	  fin >> anAdjVertex; // additional tokens per line are ADJACENT VERTICES
	  (Gtable[currentSlot].adjacentOnes).addRear(anAdjVertex); 
	}
      ++currentSlot;
    }

  GtableSort(Gtable, currentSlot); // sort table contents by NAME  

}

// Purpose: Get the list of adjacent vertices to a chosen vertex
// Parameters Purpose: Input the chosen vertex as a char
slist dgraph::findAdjacency(char chosenVertex)
{

  int index = binarySearch(chosenVertex);
  if( index == -1 ) //if not found
    {
      slist empty;
      return empty;
    }
  else //vertex was found, so return it
    return Gtable[index].adjacentOnes;
}


// Purpose: Ensure that unsorted file entries get sorted
// Parameters Purpose: must pass the table as array of Gvertex objects, 
//   also pass length because it is needed with array implementation
// Algorithm: uses quicksort; implemenetation relies on order of tokens;
//   only the first token of each slist, NAME, is compared for sorting
void dgraph::GtableSort(Gvertex filledTable[], int length)
{
  int i,j;
  char temp;
  for( i=1; i<length; i++ )
    {
      j=i;
      while( j>0 && (filledTable[j-i].name > filledTable[j].name) ) 
	{
	  temp = filledTable[j].name;
	  filledTable[j].name = filledTable[j-1].name;
	  filledTable[j-1].name = temp;
	  --j;
	}
    }
}

// Purpose: Quickly find an element in a SORTED list
// Parameters Purpose: elements name is passed as a char
// Algorithm: binary search; midpoint is chosen to be floor(middle)
int dgraph::binarySearch(char key)
{
  key = toupper(key); //make sure key is upper case

  int first, last, mid;
  first = 0;
  last = currentSlot-1;
  mid = (first+last)/2;
  while( (Gtable[mid].name != key) && (first<=last) )
    {
      if(Gtable[mid].name > key)
	last = mid-1;
      else
	first = mid+1;

      mid = (first+last)/2;
    }


  if( first <= last ) // vertex was found
    {
      return mid; // return it
    }
  else //vertex DNE
    return -1; //return what cannot be an index
}
#endif // DGRAPH_C
