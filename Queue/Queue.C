/**
   \class Queue  
 
   A simple queue with a simple interface.

   \author Originally based on code from "Data Structures for Game Programmers"
   \author Adapted by Jeff Bunce
*/

#ifndef QUEUE_C
#define QUEUE_C
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
class Queue
{
public:

  /**
     Default Constructor

     Initializes the object to an empty queue.
  */
  Queue( ) : front(NULL), back(NULL)
  {
    //Intentionally Empty
  }

  /**
     Copy Constructor

     Initializes the object to be an exact copy of an existing queue.
     @param existingQueue const Queue<T>&
  */
  Queue(const Queue<T>& existingQueue)
  {
    //uses cstddef
    if (existingQueue.isEmpty( ))
      front = back = NULL;
    else
      {
        Node<T> *temp = existingQueue.front;//temp moves
        //through the nodes from front to back of aQueue.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
	//node or NULL if there is no second node.

        while (temp != NULL)
	  {
            back->setLink(new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );
	  }
        //back->link == NULL
      }
  }  

  /**
     Overloading = operator

     @param rightSide const Queue<T>&
  */
  Queue<T>& operator =(const Queue<T>& rightSide)
  {
    if (front == rightSide.front)//if the queues are the same
      return *this;
    else //send left side back to freestore
      {
        //T next;
        while (! isEmpty( ))
	  remove( );
	//next = remove( );//remove calls delete.
      }

    if (rightSide.isEmpty( ))
      {
        front = back = NULL;
        return *this;
      }
    else
      {
        Node<T> *temp = rightSide.front;//temp moves 
	//through the nodes from front to back of rightSide.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
	//node or NULL if there is no second node.

        while (temp != NULL)
	  {
            back->setLink(
			  new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );
	  }
        //back->link == NULL;

        return *this;
      }
  }


  /**
     A (virtual) Destructor
     
  */
  virtual ~Queue( ) //Destructor
  {
    //T next;
    while (! isEmpty( ))
      remove( );
      //next = remove( );//remove calls delete.
  }

  void add(T item)
  //Postcondition: item has been added to the back of the queue.
  {
    if (isEmpty( ))
      front = back = new Node<T>(item, NULL);//sets both
    //front and back to point to the only node

    else
      {
	back->setLink(new Node<T>(item, NULL));
	back = back->getLink( );
      }
  }
  
  /** 
      Remove the element at the front of the queue.

      @return returns the removed element.
      \warning ALWAYS test that an element exists before calling remove()
      \pre An element must exist
      \post The removed element will no longer exist in the queue
      @see isEmtpy()
  */
  T remove( )
  {
    if (isEmpty( ))
      {
	cerr << "Error: Removing from empty queue => Exiting program\n";
	exit(1);
      }

    T result = front->getData( );

    Node<T> *discard;
    discard = front;
    front = front->getLink( );
    if (front == NULL) //if you removed the last node
      back = NULL;

    delete discard;

    return result;
  }

  /**
     Check that the queue is (or isn't empty)
     
     @return returns true if the queue is empty
  */
  bool isEmpty( ) const
  //Returns true if the queue is empty. Returns false otherwise.
  {
    return (back == NULL);
  }

private:
  Node<T> *front;/**< Points to the head of a linked list. */
  Node<T> *back;/**<Points to the node at the other end of the linked list. */
};

#endif //STACK_C
