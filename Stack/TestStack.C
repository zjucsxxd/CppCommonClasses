//Program to demonstrate use of the Stack template class.
#include <iostream>
#include <string>
#include "Stack.C"
using std::cin;
using std::cout;
using std::endl;

int main( )
{

  //char example of Stack
  char next, ans;
    do
      {
        Stack<char> s;
        cout << "Enter a line of text:\n";
        cin.get(next);

        while (next != '\n')
	  {
            s.push(next);
            cin.get(next);
	  }
        cout << "Written backward that is:\n";

        while ( ! s.isEmpty( ) )
	  cout << s.pop( );

        cout << endl;
        cout << "Again?(y/n): ";
        cin >> ans;
        cin.ignore(10000, '\n');
      }while (ans != 'n' && ans != 'N');


    //int example of Stack with dynamic allocation and in-scope deletion
    Stack<int> * ptr;
    ptr = new Stack<int>;
    ptr->push(100);
    ptr->push(3);
    ptr->push(14);

    cout << "numStack[2] = " << ptr->pop( ) << "\n";
    cout << "numStack[1] = " << ptr->pop( ) << "\n";
    cout << "numStack[0] = " << ptr->pop( ) << "\n";
    delete ptr;
    ptr = NULL;


    //String example of Stack
    Stack<string> stringStack;
    stringStack.push("WASD");
    stringStack.push("Dvorak");
    stringStack.push("QWERTY");

    int lineNum = 1;
    while ( ! stringStack.isEmpty( ))
      {
	cout << "Line " << lineNum << ": " << stringStack.pop( ) << "\n";
	++lineNum;
      }

    return 0;
}

