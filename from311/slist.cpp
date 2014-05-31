// =========================================================

//HW3P2  Searchable Linked List Implementation
//Your name: Jeff Bunce
//Complier:  g++ 4.1.2
//File type: implementation file slist.cpp

// Description: This is an implementation for a Searchable Linked 
//   List.  This file (and unless otherwise stated, only this file)
//  makes no assumptions as to what type el_t is defined as.  To 
// change el_t's type, redefine it in llist.h.

//================================================================





#ifndef SLIST_CPP
#define SLIST_CPP

#include <iostream>
#include "slist.h"
using namespace std;

// Purpose: Initialize the object using llist()
// Paremeters Purpose: no parameters
slist::slist() : llist() 
{
  //The following lines would be redundant even if I did not explicitly
  //  call llist()

  /*Front = NULL;
  Rear = NULL;
  Count = 0;*/
}

// Purpose: Initialize the object by copying an existing list
// Parameters Purpose: pass an slist that will be copied 
slist::slist(const slist& Original) : llist()
{
    // ** Front, Rear, and Count initialized in llist()
  

    // ** If Original was empty, then you're done
  // ** Else, copy each element into new list
  Node * P = Original.Front; // P points to original list
  while( P != NULL )
    {
      this->addRear(P->Elem); // copy element into new list
      P = P->Next; 
    }
}

// Purpose: ASSIGNMENT OPERATOR Copy the elements of one list into another
// Parameters Purpose: OtherOne is a const reference to the 
//   list (OtherOne is the RHS operand)
slist& slist::operator=(const slist& OtherOne)
{
  if( &OtherOne == this ) //if LHS==RHS, return LHS
    return *this;


  // Otherwise, empty the list on LHS
  el_t unusedVar;
  while( ! this->isEmpty() )
    this->deleteRear(unusedVar);

 // ** If OtherOne is empty, then you're done
  // ** Else, copy each element into new list
  Node * P = OtherOne.Front; // P points to original list
  while( P != NULL )
    {
      this->addRear(P->Elem); // copy element into new list
      P = P->Next; 
    }

  return *this; // return the result unconditionally
}


// Purpose: EQUALIITY OPERATOR  Check that 
//    1. both lists are of equal length
//    2. all elements are the same
// Parameters Purpose: rhs and lhs are lists that must be 
//    passed so that they can be compared
bool slist::operator==(const slist& rhs)
{
  Node * L = this->Front; // points to nodes in lhs list
  Node * R = rhs.Front; // points to nodes in rhs list

  if( L==NULL && R==NULL ) // if both lists are empty
    return true;

  while( L!=NULL && R!=NULL )
    {
      if( L->Elem != R->Elem ) // elements must be equivalant
	return false;

      L = L->Next;
      R = R->Next;
    }

  if( L!=NULL || R!=NULL ) // both lists must be of the same length
    return false;
  else // 1. length is the same; 2. all elements are the same
    return true;
}

// Purpose: Search for a specific Key in the list.  Returns the position if
//   the element exists.  Returns 0 if the elem DNE.
// Paremeters Purpose: "Key" is the el_t you search for
// Algorithm: Iterate through each node until a node whose element matches Key
//   is found.  Duplicate elements can exist in the list but only the first is
//   found.
int slist::search(el_t Key)
{
  if( isEmpty() ) // If the list is empty, return 0
    return 0;

  int nodeNumber = 1; // is the current node being accessed
  Node * P = Front; // P points to the current element

  // The following loop is safe because the conditional always checks if P equals
  //    NULL before it trys to access P->Elem
  while ( P != NULL && P->Elem != Key ) 
    {
      P = P->Next; // iterate through the list until
                   //  you get a match or reach the end
      ++nodeNumber;
    }
  if( P == NULL ) // if P is NULL then the key DNE
    return 0;
  else // and if P points to a Node, then return its number
    return nodeNumber;
}


// Purpose: Replaces the element contained in an existing node
// Paremeters Purpose: "Key" is an element of type el_t that replaces
//   the contents of Node "I" with the key "Key"
// Algorithm: Navigate to the node "I", replace its content with the elem
//   "Key"
void slist::replace(el_t Key,  int I)
{
  if( isEmpty() ) // If the list is empty, throw Underflow
    throw Underflow();
  else if( I>Count || I<1 ) // If given an out of range index, throw OutOfRange
    throw OutOfRange();

 
  int nodeNumber = 1; // is the current node being accessed
  Node * P = Front; // P points to the current element
  while ( nodeNumber < I ) //navigate to nodeNumber I 
    {
      P = P->Next;
      ++nodeNumber;
    }
  P->Elem = Key; 
}


#endif //SLIST_CPP
