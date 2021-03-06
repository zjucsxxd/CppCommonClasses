//Program to demonstrate use of the LinkedList template class.
#include <iostream>
#include <string>
#include "LL.C"
using std::cin;
using std::cout;
using std::endl;

int main ()
{
  LL<int> list1;
  list1.insertDataFromFile();
  cout << "\n\n------------Printing list 2--------------\n\n";
  list1.print();
  list1.insertAfterFirst (543125);
  list1.insertBeforeFirst (54123);
  list1.insertAfterLast (63421);
  list1.insertBeforeLast (66641);
  cout << "\n\n------------Printing list 2--------------\n\n";
  list1.print();
  bool  found = list1.search (12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;
  list1.remove (54321);
  cout << "\n\n------------Printing list 1--------------\n\n";
  list1.print();

  cout << "\n\n------------Copying List 1 into list 2--------------\n\n";
  LL<int> list2(list1);
  cout << "\n\n------------Printing list 2--------------\n\n";
  list2.print();
  return 0;

}
