/*
Originally Lab9 in cs211, this class has been converted to a template so it's more useful
  *Implementation and Interface are in same file for MSVC compatibilty*
  Jeff Bunce
  05/22/2013
*/


#include <iostream>
#include <fstream>
#include<string>

using namespace std;

template<class T>
class Node
{
public:
  Node(T theData, Node<T>* theLink) : data(theData), link(theLink) {}
  Node <T>* getLink( ) const { return link; }
  const T getData( ) const { return data; }
  void setLink(Node<T>* pointer) { link = pointer; }
private:
  T data;
  Node<T>* link;
};

template<class T>
class LL
{
private:
  Node<T>* top;
public:
  LL( ); //initializes the object to an empty list.
  LL(T data); //initializes the object to a single item in the list.
  LL(const LL& source); //copy constructor
  virtual ~LL( );
    void insertDataFromFile( );
    void print ( );
  bool search (T target);
    void insertAfterFirst (T item);
  void insertBeforeFirst (T item);
    void insertAfterLast (T item);
    void insertBeforeLast (T item);
    void remove (T target);
  void copy (Node<T>* atop, Node<T> btop);
  void destroy(Node<T>*&);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
template<class T>
LL<T>::LL() : top(NULL)
{
  //Intentionally blank.
}
//--------------------------------------------
//--------------------------------------------
// the optional constructor
template<class T>
LL<T>::LL(T data)
{
  top = new Node<T>(data);
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
template<class T>
LL<T>::LL(const LL& source)
{
  top->setLink(NULL);
  copy(source->top, top);//TODO TEST THIS
}

//--------------------------------------------
//--------------------------------------------
// the destructor
template<class T>
LL<T>::~LL()
{
    destroy( top ); //destroy from the top
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the
// insert functions to insert the node into the linked list
template<class T>
void LL<T>::insertDataFromFile() 
{
  string fileName;
  cout << "Enter the name of the file you'd like to read\n";
  cin >> fileName;
    ifstream fileIn;
    fileIn.open(fileName.data());
    if ( ! fileIn.is_open() )
    {
        cerr << "Failed to open transaction file " << fileName << "\n";
        return;
    }
    T data;
    while ( fileIn >> data )
    {
        insertAfterLast( data );
    }
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
template<class T>
void LL<T>::print( )
{
    //if no nodes exist
  if ( top == NULL )
    {
        return;
    }

    //if nodes exist
    int count = 0;
    Node<T>* p = top;
    while ( p != NULL )
    {
      cout << count << ": " << p->getData( ) << "\n";
      p = p->getLink( );
      ++count;
    }
}
//--------------------------------------------
//--------------------------------------------
// search for a particular node in the list.  Finds the first element
// which contains the data you're looking for.
template<class T>
bool LL<T>::search ( T data )
{
  Node<T>*  p = top;
    while ( p != NULL )
    {
      if ( p->getData( ) == data)
        {
            return true;
        }
      p = p->getLink( );
    }
    return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node.
template<class T>
void LL<T>::insertAfterFirst ( T data )
{
    //if no nodes exist
  if ( top == NULL )
    {
        insertBeforeFirst(data);
        return;
    }
    //if nodes exist
  Node<T>* newNode = new Node<T>(data, NULL);
      newNode->setLink(top->getLink( )); 
      top->setLink(newNode);
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node.
template<class T>
void LL<T>::insertBeforeFirst( T data )
{
  Node<T>* p = new Node<T>(data, NULL);
      p->setLink(top->getLink( ));
      top->setLink(p);
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node.
template<class T>
void LL<T>::insertAfterLast( T data )
{
    //if no nodes exist
    if ( top == NULL )
    {
        insertBeforeFirst(data);
        return;
    }
    //if nodes exist
    Node<T>* p = top;
    while ( p->getLink( ) != NULL )
    {
      p = p->getLink( );
    }
    Node<T>* q = new Node<T>(data, NULL);
    p->setLink(q);
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node.
template<class T>
void LL<T>::insertBeforeLast (T data)
{
    //if ZERO nodes exist
  if (top == NULL)
    {
        insertBeforeFirst(data);
        return;
    }
  //if ONE node exists
  if (top->getLink( ) == NULL)
    {
      insertBeforeFirst(data);
      return;
    }
    //if MORE THAN ONE node exists
  Node<T>* p = top;
  Node<T>* q = top;
        while (p->getLink( ) != NULL)
        {
            q = p;
            p = p->getLink( );
        }
        Node<T> n = new Node<T>(data, NULL);
	q->setLink(n);
	n->setLink(p);
}
//--------------------------------------------
//--------------------------------------------
// removes the first node that matches the argument
template<class T>
void LL<T>::remove (T data)
{
    if ( search(data) == false )
    {
        return; //cannot remove an element that doesn't exist
    }

    Node<T>* p = top;
    Node<T>* q = top;
    //for one node
    if ( p->getLink( ) == NULL )
    {
        destroy( top );
    }

    //if first node is deleted and more than one node exists
    if ( p->getLink()->getData() == data )
    {
      top->setLink(top->getLink( ));
        delete p;
    }
    //for 2 or more nodes
	while ( p->getData() != data )
    {
        q = p;
	p->setLink(p->getLink( ));
    }
      q->setLink(p->getLink( ));
    delete p;
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
    template<class T>
      void LL<T>::copy(Node<T>* atop, Node<T> btop)
{
  Node<T>* a = atop;
  Node<T>* b = btop;
    while (a != NULL)
    {
        //ADD new node to btop when b points to NULL
        if ( b == NULL )
        {
	  Node<T> newNode = new Node<T>(a->getData( ));
	  Node<T>* n = *newNode;
            btop = n;
            b = btop;
        }
        //when nodes exist in bList
        else
        {
	  Node<T> newNode = new Node<T>(a->getData( ));
	  Node<T>* n = *newNode;
	  b->setLink(n);
	  b->setLink(b->getLink( ));
        }
	a->setLink(a->getLink( ));
    }
}
//--------------------------------------------
// deallocate the nodes in a linked list
    template<class T>
      void LL<T>::destroy(Node<T>*& top)
{
  Node<T>* p = top;
  Node<T>* q = NULL;
    while (p != NULL)
    {
      q->setLink(p->getLink( ));
        delete p;
        p = q;
    }
    top = NULL;
}

//--------------------------------------------
