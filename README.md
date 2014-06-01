CppCommonClasses
==================

I need to author my own Data Structures for Uni.  Here they are as a work in progress; incomplete and imperfect.

**I plan on deriving them from a common Container class to simplify and standardize their design.
	**Tree ADS will be derived from a common Tree class, excluding multiway trees
		**Dgraph method MST (Minimum Spanning Tree) will return a Tree object

**They will only be unmarked as INCOMPLETE when they are a TEMPLATE or are COMPLETE.


    MISC ADS:
    
	ArrayList           (like C++ vector, Java ArrayList)       NOT A PRIORITY
	BigInteger          (For arbitrary length integers)         INCOMPLETE
	BitVector64         (compact 64 bit storage for bools)      INCOMPLETE

    LL-BASED ADS:
	
	DLL                 (Doubly Linked List)                    INCOMPLETE
	LL                  (Singly Linked List)                    TEMPLATE
	Stack               (Basic Stack)                           INCOMPLETE
	Queue               (Basic Queue)                           TEMPLATE*

    TREE ADS:
	
	BST                 (AVL Binary Search Tree)                ********MEMLEAKS*********
	HeapTree            (Basic HeapTree)                        NOT STARTED!!
	PriorityQueue       (Derived from HeapTree)                 NOT STARTED!!

    GRAPH ADS:
    
	DGraph              (Directed Graph)                        INCOMPLETE

    NEED TO LEARN AND IMPLMENT:

	Tries               (Don't know. Yet.)                      NOT STARTED!!
	HashTable           (Don't know. Yet.)                      NOT STARTED!!

	**POSSIBLE ADDITIONS:
	
	Mnary Trees (B Trees?)



*Known Issues:
-------------

Queue
  - Exits program if programmer attempts to remove an element from existing queue.  Currently, 
    careful use of isEmpty() must be used.  I really don't like how easy it is to misuse this
    ADS.