/*
This is a TEMPLATE LinkedList class using a linked list style implementation
*Interface and Implementation in SAME file for MSVC compatibility*
  By Jeff Bunce
  05/22/2013
*/

#ifndef LINKEDLIST_C
#define LINKEDLIST_C
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
class LinkedList
{
public:
  LinkedList( ) : top(NULL) //initializes the object to an empty linked list.
  {
    //intentionally empty
  }

  LinkedList(const LinkedList<T>& oldLL) // copy constructor
  {
    if (oldLL.isEmpty( ))
      top = NULL;
    else
      {
	Node<T> *temp = oldLL.top; //temp moves through
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
  LinkedList<T>& operator =(const LinkedList<T>& rightSide) //overloading =
  {
    if (top == rightSide.top) //if two stacks are the same
      return *this;
    else //send left side back to freestore
      {
	//T next;
	while (! isEmpty( ))
	  deleteFirstNode(top);
	  //next = deleteFirstNode( ); //deletFirstNode returns Nodes memory to freestore
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
  virtual ~LinkedList( ) //Destructor
  {
    Node<T>* discard;
    while (top != NULL)
      {
	discard = top;
	top = top->getLink();
	delete discard;
      }
  }

  void topInsert(const T& theData)
  //Precondition: The pointer variable top points to
  //the top of a linked list
  //Postcondition: A new node containing theData
  //has been added at the head of the linked list
  {
    top = new Node<T>(theData,top);
  }

  void insert(Node<T>* afterMe, const T& theData)
  //Precondition: afterMe ponits to a node in a linked list.
  //Postcondition: a new node containig theData has
  //been added after the node pointed to by afterMe.
  {
      afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
  }

  void deleteNode(Node<T>* before)
  //Precondition: The pointer before points to a node that has
  //at least one node after it in the linked list.
  //Postcondition: The node after the node pointed to by before has
  //been removed from the linked list and its memory returned to
  //the freestore
  {
    Node<T> *discard;
    discard = before->getLink( );
    before->setLink(discard->getLink( ));
    delete discard;
  }

  void deletFirstNode( )
  //Precondition: The pointer top points to the first
  //node in a linked list with at least one node.
  //Postcondition: The node pointed to by top has been 
  //removed from the linked list and its memory returned
  //to the freestore
  {
    Node<T> *discard;
    discard = top;
    top = top->getLink( );
    delete discard;
  }

  Node<T>* search(const T& target)
  //Precondition: The pointer top points to the top of a linked list.
  //The pointer variable in the last node is NULL.
  //== is defined for type T.
  //If the list is empty, then top is NULL.
  //Returns a pointer that points to the first node that is equal to the target.
  //If no node equals the target, then the function returns NULL.
  {
    Node<T>* here = top;
    if (here == NULL) //if empty list
      {
      return NULL;
      }
    else
      {
	while (here->getData( ) != target && here->getLink( ) != NULL)
	  here = here->getLink( );

	if ( here->getData( ) == target)
	  return here;
	else
	  return NULL;
      }
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
