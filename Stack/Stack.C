/*
This is a TEMPLATE Stack class using a linked list style implementation
*Interface and Implementation in SAME file for MSVC compatibility*
  By Jeff Bunce
  05/21/2013
*/

#ifndef STACK_C
#define STACK_C
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;


template<class T>
class Node
{
public:
  Node(T theData, Node<T>* theLink) : data(theData), link(theLink) {}
  Node<T>* getLink( ) const { return link; }
  const T getData( ) const {return data; }
  void setData(const T& theData) { data = theData; }
  void setLink(Node<T>* pointer) { link = pointer; }
private:
  T data;
  Node<T> *link;
};



template<class T>
class Stack
{
public:
  Stack( ) : top(NULL) //initializes the object to an empty stack.
  {
    //intentionally empty
  }

  Stack(const Stack<T>& aStack) // copy constructor
  {
    if (aStack.isEmpty( ))
      top = NULL;
    else
      {
	Node<T> *temp = aStack.top; //temp moves through
	//the nodes from top to bottof of aStack
	Node<T> *end;//Points to end of the new stack

	end = new Node<T>(temp->getData( ), NULL);
	top = end;
	//Frist node created and filled with data.
	//New nodes are now added AFTER this first node.

	temp = temp->getLink( ); //move temp to second node
	                 //or NULL if there is no second node.
	while (temp != NULL)
	  {
	    end->setLink(
			 new Node<T>(temp->getData( ), NULL));
	    temp = temp->getLink( );
	    end = end->getLink( );
	  }
	//At this point, end->link == NULL;.
      }
  }
  Stack<T>& operator =(const Stack<T>& rightSide) //overloading =
  {
    if (top == rightSide.top) //if two stacks are the same
      return *this;
    else //send left side back to freestore
      {
	T next;
	while (! isEmpty( ))
	  pop();
	  // next = pop( ); //pop calls delete.
      }
    if (rightSide.isEmpty( ))
      {
	top = NULL;
	return *this;
      }
    else
      {
	Node<T> *temp = rightSide.top; //temp moves through
	//the nodes from the front top to bottom of rightSide

	Node<T> *end; //Points to the end of the left side stack.
	end = new Node<T>(temp->getData( ), NULL);
	top = end;
	//First node created and filled with data.
	//New nodes are now added AFTER this first node.

	temp = temp->getLink(); //Move temp to second node or
	            //set to Null if there is no second node.

	while (temp != NULL)
	  {
	    end->setLink(new Node<T>(temp->getData(), NULL));
	    temp = temp->getLink();
	    end = end->getLink();
	  }
	//At this point, back->link == NULL;.
	return *this;
      }
  }
  virtual ~Stack( ) //Destructor
  {
    //T next;
    while (! isEmpty( ))
      pop( );
      //next = pop( ); //pop calls delete
  }


  void push(T stackFrame)
  //Postcondition: The stackFrame has been added to the stack
  {
    top = new Node<T>(stackFrame, top);
  }

  T pop( )
  //Precondition: The stack is not empty
  //Returns the top stack frame and removes the top
  //stack frame from the stack
  {
    if (isEmpty( ))
      {
	cout << "Error: popping from an empty stack => Exting program\n";
	exit(1);
      }
    T result = top->getData( );

    Node<T> *discard;
    discard = top;
    top = top->getLink();

    delete discard;
    return result;
  }
  bool isEmpty( ) const
  //Returns true if the stack is empty.  Returns false otherwise.
  {
    return (top == NULL);
  }

private:
  Node<T> * top;
};

#endif //STACK_C
