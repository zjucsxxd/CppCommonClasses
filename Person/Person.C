#ifndef PERSON_C
#define PERSON_C

#include "Person.h"

using namespace std;

Person::Person()
{
    cout << "Enter your first name\n";
    cin >> firstName_;
    cout << "Enter your last name\n";
    cin >> lastName_;
    fullName_ = firstName_ + " " + lastName_;
}

Person::Person(string FirstName, string LastName)
{
    firstName_ = FirstName;
    lastName_ = LastName;
}

string Person::getName()
{
    return fullName_;
}

string Person::getFirstName()
{
    return firstName_;
}

string Person::getLastName()
{
    return lastName_;
}

#endif //PERSON_C
