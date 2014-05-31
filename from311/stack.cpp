// =========================================================

//HW1P2 Stack   vector<int> implementation
//Your name: Jeff Bunce
//Complier:  g++
//File type: implementation file stack.cpp

// Description: This is the implementation of a std::vector INTEGER stack class

// Notable Implementation Differences: No max size; vector grows as needed,
//  No top variable; use (vector::size()-1) instead,
//  isFull() always returns true if vectors aren't told to 
//    resize by increments larger than 1

//================================================================
#include <iostream>
#include "stack.h"
using namespace std;

// Purpose: None when using vector-based stack
// Parameter Purpose: no parameters
stack::stack()
{} //does nothing

stack::~stack()
{clearIt();} //vector array; Destructor must ensure no cells left behind

// Purpose: If stack is empty returns true, otherwise false
//  Parameter Purpose: no parameters
bool stack::isEmpty()
{ if (el.size() == 0) return true; else return false; } //stack is empty if ( el.size() == 0), else not empty
    
// Purpose: isFull checks top and returns true if full, false otherwise.
// Parameter Purpose: no parameters
bool stack::isFull()
{ return false; } // vector-based stack will have room for more elements as long as
 //                     your computer has memory


 // Purpose: push places the passed item onto the stack
 //            if the stack is full, an Overflow() exception is thrown
 // Parameter Purpose: pass the element that you want to push on the stack
 // Throws Exception: throws Overflow exception if push is called on full stack
 void stack::push(stackElement elem)
 { if (isFull()) throw Overflow(); // if full, then throw Overflowexception;
   else { el.push_back(elem); }} // if not, push elem onto stack


 // Purpose: pop retrieves the passed element and removes the element from the top
 //            if the stack is empty, an Underflow() exception is thrown
 // Parameter Purpose: provides an element in which to store the popped element
 // Throws Exception: throws Underflow exception if pop is called on empty stack
 void stack::pop(stackElement& elem)
 { 
   if (isEmpty())
     throw Underflow(); //if empty, then throw Underflow exception
   else // if not empty, then pop an element into elem 
     { 
       elem = el.back(); // retrieve element then...
       el.pop_back();       // pop from the stack
     }
 }

  // Purpose: topElem calls isEmpty and if true, throws an exception (underflow)
  //    Otherwise, gives back the top element from el.
  // Parameter Purpose: provides a variable to store the (un-popped) element
  // Throws Exception: throws Underflow exception if topElem is called on empty stack
  //      Underflow tells the client that there is no element to look at
void stack::topElem(stackElement& elem)
{ 
  if (isEmpty())
    throw Underflow(); //if empty, then throw Underflow exception
  else  
    {
      //if not empty, then place element into parameter elem
      elem = el.back();
    }
}

//Purpose: displays all elements, from top of stack to bottom
// Parameter Purpose: no parameter
// Algorithm: iterate through stack, from top to bottom, using a for loop
// **NOTE FOR HEADER AUTHOR**: cout is used here; inform header author immediately!
void stack::displayAll()
{  
  if (isEmpty())
    cout << "[ empty ]Z" << endl; //if empty, display "[ empty ]"
  else 
    {
      std::vector<stackElement>::reverse_iterator rit;
      for (rit = el.rbegin(); rit!= el.rend(); ++rit) //if not empty, print elements of stack from top to bottom
       cout << *rit << endl; 
    }
}

// Purpose:  clearIt pops all elements from the stack to make it empty if it is not empty yet.
// Parameter Purpose: no parameter
//Algorithm:  Use a while loop to pop elements from the stack until
//             the vectors size is 0
void stack::clearIt()
{
  if ( isEmpty() )//if empty, do nothing; stack is already clear
    {
      //do nothing
    }
  else // if not empty, pop elements of stack from top to bottom
    while(el.size() > 0)
      el.pop_back(); // removes elements one at a time
}
