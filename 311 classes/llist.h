// =======================================================

// HW3P1 Linked List Header

// Your name: Jeff Bunce
// Compiler:  g++ 4.1.2
// File type: header file llist.h

// Description: This is the header for my llist class;
//   it is currently for integers only

//=======================================================

#ifndef LLIST_H
#define LLIST_H

typedef char el_t;


struct Node // for Singularly Linked Lists
{
  el_t Elem; // the element stored in the list
  Node * Next; // points to the next node in the list
};

class llist
{
 protected:
  Node * Front; // points to the first element in the list
  Node * Rear; // points to the last element in the list
  int Count; // for inserting and deleting from ith position


 public:
  class Underflow { }; // Exception class
  class OutOfRange { }; // Exception class

  llist(); // LL constructor -- Initializes to empty list
  ~llist(); // LL destructor -- ensures no garbage is left on heap


  // Purpose: Used to check if LL is empty
  // How To Call: Use in a boolean expression
  bool isEmpty();

  // Purpose: Displays the entire list using stdout
  // How To Call: Call by itself;  Warning:  This prints directly to
  // terminal if stdout isn't redirected
  void displayAll();

  // Purpose: Adds a new node to the rear and places NewNum inside the node
  // How To Call: Pass an el_t variable to the function
  void addRear( el_t NewNum );

  // Purpose: Delete the first node in the list; will return the element using the
  // parameter
  // How To Call: Pass a el_t variable to the function
  void deleteFront( el_t & OldNum );

  // Purpose: Add a new node to the front of the list
  // How To Call: Pass an el_t to the function to store it at the front of the list
  void addFront( el_t NewNum );

  // Purpose: Deletes the last element on the list
  // How To Call: Pass an el_t variable to the function to retrieve the stored element
  void deleteRear( el_t & OldNum );

  // Purpose: Deletes the chosen element
  // How To Call: pass the position to delete and an el_t variable to retrieve
  //   the stored element.  Eg.An I of 1 deletes the FIRST element.
  void deleteIth( int I, el_t & OldNum );

  // Purpose: Adds a new node BEFORE the chosen element
  // How To Call: pass the position after where you'd like your new node placed, then pass
  //   an el_t to be stored into the new node
  // Note that: If you pass I=Count+1 then a new element will be created at the
  //   rear of the list instead of being considered OutOfRange
  void addBeforeIth( int I, el_t NewNum );
};

#endif //LLIST_H
