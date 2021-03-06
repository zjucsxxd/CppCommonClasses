//Program to demonstrate use of the Queue template class.
#include <iostream>
#include <string>
#include "Queue.C"
using namespace std;
int main( )
{
  char next, ans;

  Queue<char> test;
  do
    {
      Queue<char> q;
      cout << "Enter a line of text:\n";
      cin.get(next);
      while (next != '\n')
	{
	  q.add(next);
	  cin.get(next);
	}
      /////////////
      test = q;
      //////////////
      cout << "You entered:\n";
      while ( ! q.isEmpty( ) )
	cout << q.remove( );
      cout << endl;

      cout << "Again?(y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');


  while (! test.isEmpty( ))
      cout << test.remove( );
  cout << "\n";

  return 0;
}
