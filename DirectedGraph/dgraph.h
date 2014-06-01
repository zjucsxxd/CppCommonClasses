// =======================================================

// HW6 Directed Graph Header

// Your name: Jeff Bunce
// Compiler:  g++ 4.1.2
// File type: header file dgraph.h

// Description: This is header file for a Directed Graph
//   class.It can be used to store any type of 
//   data; typedef is set in the header file slist.h
//=======================================================

#ifndef DGRAPH_H
#define DGRAPH_H


#include "slist.h"

struct Gvertex // for Directed Graph
{
  char name;
  int visitNo;
  int outDegree;
  slist adjacentOnes;
};

class dgraph
{
 public:
  // Purpose: Initialize data members when creating dgraph objects
  // How To Call: Client calls when declaring dgraph objects
  dgraph();

  // Purpose: Ensures composed objects and dgraph object are properly deleted
  // How To Call: Implicitly called when an automatic object goes out of scope
  //               or explicitly deleted when on the heap
  ~dgraph();

  // Purpose: Displays the table content in a readable format.  Unused slots
  //           are not displayed.
  // How To Call: Call only when you want to display the graph using stdout stream
  void displayGraph();

  // Purpose: Reads the input file 'table.txt' to fill the table
  // How To Call: As of this time, you can only read from the file 'table.txt'
  //               Because of this, call the function without a parameter
  void fillTable();  

  // Purpose: Returns the out degree of a given vertex
  // How To Call: pass the character of the vertex that you'd like to find
  //               the out degree of
  int findOutDegree(char);

  // Purpose: Returns a list of vertices that are adjacent to a chosen vertex
  // How To Call: pass the vertex that you'd like to know the adjacent vectors of
  slist findAdjacency(char);

  //   Added the following functions 11/24/2013

  // Purpose: Enters the given visit number for a given vertex to indicate order
  //   in which vertices were visited
  // How To Call: pass the visit number followed by the given vertex as a char
  void visit(int,char);

  // Purpose: BOOLEAN; returns true if given vertex was already visited
  // How To Call: check a vertex by its name (a char); use in a boolean expression
  bool isMarked(char);


 protected:

  // Purpose: Sort the table of Gvertex after it is filled
  // How To Call: Call after the table is filled
  void GtableSort(Gvertex filledTable[], int length);

  // Purpose: Access particular vertices quickly
  // How To Call: Use to return an index directly
  int binarySearch(char search);

  Gvertex Gtable[28]; // array of vertices large enough to store all uppercase letters
  static const int MAX_TABLE_LENGTH;
  int currentSlot;
};

#endif // DGRAPH_H  
