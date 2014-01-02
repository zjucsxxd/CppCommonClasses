// =======================================================

// HW1P2 Stack
// Your name: Jeff Bunce
// Compiler:  g++ 
// File type: header file stack.h

// Description: This is the header of my INTEGER stack class;
//              Please note again, it will only work with integers

//=======================================================
#include <vector>
typedef char stackElement; 

class stack
  { 

   private: // to be hidden from the client

    std::vector<stackElement> el;            // initialize an empty vector<stackElement>


   public: // prototypes to be used by the client

        // (empty) exception handling classes (to enhance readability!!)
	
        class Overflow{}; 
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(stackElement);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(stackElement&);

        // HOW TO CALL: provide variable to recieve the viewed (NOT popped) element
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(stackElement&);

      	// HOW TO CALL: no parameter; use as part of boolean expressions
        // PURPOSE: if empty, return true
	bool isEmpty();
      	
	// HOW TO CALL: no parameter; use as part of boolean expressions
        // PURPOSE: if full, returns true.
	bool isFull();

	// HOW TO CALL: no parameter; BEWARE! prints to stdout stream (terminal if not redirected)
        // PURPOSE: Prints every element of stack.  again, BEWARE! prints to stdout stream
	//          only use if you intend to output to the terminal or have appropriately
	//          redirected stdout 
        void displayAll();

	// HOW TO CALL: call without paramater
        // PURPOSE: easily empty the stack; ALL CONTENT WILL BE LOST
        void clearIt();
        
  };  

// Note: semicolon is needed at the end of the header file
