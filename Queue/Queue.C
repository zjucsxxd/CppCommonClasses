/*
This is a TEMPLATE Queue class using a linked list style implementation
*Interface and Implementation in SAME file for MSVC compatibility*
  By Jeff Bunce
  05/22/2013
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


  Queue( ) : front(NULL), back(NULL) //Initializes the object to an empty queue.
  {
    //Intentionally Empty
  }

  Queue(const Queue<T>& aQueue)//Copy Constructor
  {
    //uses cstddef
    if (aQueue.isEmpty( ))
      front = back = NULL;
    else
      {
        Node<T> *temp = aQueue.front;//temp moves
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

    Queue<T>& operator =(const Queue<T>& rightSide) //overloading =
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
  

  T remove( )
  //Precondition: The queue is not empty.
  //Returns the item at the front of the queue
  //and removes that item from the queue.
  {
    if (isEmpty( ))
      {
        cout << "Error:Removing an item from an empty queue.\n";
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


  bool isEmpty( ) const
  //Returns true if the queue is empty. Returns false otherwise.
  {
    return (back == NULL);
  }
private:
  Node<T> *front;//Points to the head of a linked list. 
  //Items are removed at the head
  Node<T> *back;//Points to the node at the other end of the linked list.
  //Items are added at this end.
};

#endif //STACK_C
