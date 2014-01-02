// =========================================================

//HW3P1  Linked List Implementation
//Your name: Jeff Bunce
//Complier:  g++ 4.1.2
//File type: implementation file llist.cpp

// Description: This is an implementation for a Linked List
//  that only stores integers

//================================================================

#ifndef LLIST_CPP
#define LLIST_CPP

#include <iostream>
#include <cstddef>
#include "llist.h" 
using namespace std;



// Purpose: Initializes the list; list is initially empty
// Parameters Purpose: no parameters 
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

// Purpose: Destroys the list and ensures no garbage is left on the heap
// Parameters Purpose: no parameters
// Algorithm: Iterate through the list and delete until the list is empty
llist::~llist()
{
  //cout << "Calling the llist destructor.\n";
  el_t unusedVar; // required param
  while( ! isEmpty() )
    deleteFront( unusedVar );
}

// Purpose: Returns true if the list is empty
// Parameters Purpose: no parameters
bool llist::isEmpty()
{
  if( Front == NULL && Rear == NULL )
    {
      return true;
    }
  else
    return false;
}

// Purpose: Displays the entire list in form: [ el1 el2 ... ]\n
// Parameters Purpose: no parameters
// Algorithm: iterate through the list and display elements as you go
void llist::displayAll()
{
  if( isEmpty() ) // special case: if empty, displays [ empty ]
    {
      cout << " [ empty ]\n";
    }
  else
    {
      
      Node * P = Front; // pointer used as iterator
      cout << "List: [ ";
      while( P != NULL )
	{
	  cout << P->Elem << " ";
	  P = P->Next;
	}
      cout << "]\n";
    }
}

// Purpose: Add a new node to the back of the list
// Parameters Purpose: NewNum passes an el_t to be stored into the new node
void llist::addRear( el_t NewNum )
{
  if( isEmpty() ) // special case: if empty, create the first cell using addFront
      addFront( NewNum );  
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      ++Count;
    }
}

// Purpose: Deletes the first element in the list
// Parameters Purpose: OldNum is used to pass the element in the deleted node up a level
void llist::deleteFront( el_t & OldNum )
{
  if( isEmpty() ) // if empty, throw Underflow exception
    throw Underflow();
  else
    {
      if( Front == Rear ) // if there exists a single element..
	{
	  Rear = NULL; // ..make user Rear does not dangle
	}
      OldNum = Front->Elem;
      Node * Second = Front->Next; // Second stores Front->Next after Front is deleted
      delete Front;
      Front = Second;
      --Count;
    }
}

// Purpose: Add a new element to the front of the list
// Parameters Purpose: NewNum gives an el_t to be stored in the new node
void llist::addFront( el_t NewNum )
{
  Node * newFront = new Node; //new node ensures the list is not lost
  newFront->Next = Front;

  if( isEmpty() ) // if empty, ensure Rear also points to NewFront
    Rear = newFront;

  // proceed normally
      Front = newFront;
      Front->Elem = NewNum;
      ++Count;
}

// Purpose: Delete the last element in the list
// Parameters Purpose: OldNum is used to pass the element in the deleted node up a level
void llist::deleteRear( el_t & OldNum )
{
  if( isEmpty() ) // if empty, throw Underflow exception
    throw Underflow();
  else if( Front == Rear ) // if final element, let deleteFront handle it
    deleteFront( OldNum );
  else
    {
      OldNum = Rear->Elem;
      Node * newRear = Front; // is used to reassign rear to rear[n-1]

      while( newRear->Next != Rear ) // move newRear to point to rear[n-1]
	newRear = newRear->Next;

      delete Rear;
      Rear = newRear;
      Rear->Next = NULL;
      --Count;
    }
}

// Purpose: Deletes a chosen node
// Parameters Purpose: I is the node to be deleted (the first node starts at 1),
//  OldNum is used to pass the el_t of the deleted node up a level
void llist::deleteIth( int I, el_t & OldNum )
{
  if(  I<1  ||  I>Count ) // If out of bouds, throw OutOfRange exception
    throw OutOfRange(); // ..will also be thrown if list is empty
  else if( I == 1 ) // If deleting front, let deleteFront handle it
    deleteFront( OldNum ); // ..this also handles deletion of the final element
  else if( I == Count ) // If deleting rear, let deleteRear handle it
    deleteRear( OldNum );
  else  //otherwise, delete Ith element
    {
      Node * PMinus1 = Front; // will be moved to Ith-1 position 
      int currPos = 1; // keeps track of times pointer moves from Node to Node
      while( currPos != I-1 ) // move to Ith-1 position
	{
	  PMinus1 = PMinus1->Next;
	  ++currPos;
	}
      Node * PPlus1 = (PMinus1->Next)->Next; // stores the Node after Node(I)
      OldNum = (PMinus1->Next)->Elem; // retrieve contents of Ith Node
      delete PMinus1->Next;  // delete Ith Node
      PMinus1->Next = PPlus1; // connect I-1 and I+1
      --Count;
    }
}

// Purpose: Adds a new node before the node you choose
// Parameters Purpose: I is the node that will have a new node placed before it;
//   NewNum is the element to be placed into the new node
// Note that: If you pass I=Count+1 then a new element will be created at the
//   rear of the list instead of being considered OutOfRange
void llist::addBeforeIth( int I, el_t NewNum )
{
  if( I == 1 ) // If adding to front, let addFront handle it
    addFront( NewNum ); // .. this also handles adding to an empty list
  else if( I == Count+1 ) // If adding to rear, let addRear handle it
    addRear( NewNum );
  else if(  I<1  ||  I>Count+1 ) // If out of bounds, throw OutOfRange exception
    throw OutOfRange(); // ..will also be thrown if list is empty
  else 
    {
      Node * PMinus1 = Front;
      int currPos = 1;
      while( currPos != I-1 )
	{
	  PMinus1 = PMinus1->Next;
	  ++currPos;
	}
      Node * PPlus1 = PMinus1->Next;
      Node * newNode = new Node;
      newNode->Elem = NewNum;
      PMinus1->Next = newNode;
      newNode->Next = PPlus1;
      ++Count; 
    }
}

#endif //LLIST_CPP
