// =======================================================================

// HW3P2 Searchable Linked List Header

// Your name: Jeff Bunce
// Compiler:  g++ 4.1.2
// File type: header file slist.h

// Description: This is the header for my searchable linked
//   list class.  This file (and unless otherwise stated, only this file)
//  makes no assumptions as to what type el_t is defined as.  To 
// change el_t's type, redefine it in llist.h.

//=========================================================================




#ifndef SLIST_H
#define SLIST_H

#include "llist.h"

class slist : public llist
{
 public:

  // Purpose: Initialize data members by calling llist()
  // How To Call: Client calls this implicitly
  slist();

  // Purpose: Initialize a list by copying an existing list
  // How To Call: When creating a new list, pass an existing
  //   list as an argument
  slist(const slist& Original);


  // Purpose: Overload the assignment operator '=' to correctly copy the list
  // How To Call: Client calls this as is typical for the
  //    copy operator; newList = oldList;
  slist& operator=(const slist& OtherOne);


  // Purpose: Overload the equality operator '==' to 
  //           1. check that both lists are of equal length
  //           2. check that each element are the same
  // How To Call: Call this as part of a boolean expression
  bool operator==(const slist& rhs);

  // Purpose: Search for a specific element and return its position
  // How To Call: Pass an el_t to see if that key exists.  This returns an int
  //   to show where the key was found or 0 if the key DNE in the list.
  int search(el_t Key);


  // Purpose:  Replace the contents of the Node in position "I" with
  //   the element "Key"
  // How To Call: Pass an el_t that will be the new element, pass the
  //   position of the node that you would like to overwrite
  void replace(el_t Key,  int I);
};

#endif //SLIST_H
