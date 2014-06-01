#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
//using namespace std;  //DO NOT INCLUDE "using" DIRECTIVE IN HEADERS

class Person
{
public: //interface pieces are public
    Person();
    Person(std::string newFirstName, std::string newLastName);
    std::string getName();
    std::string getFirstName();
    std::string getLastName();
private: //member variables and helper functions belong below private:
    std::string firstName_; //private class variables are often denoted with an _
                            //in c++
    std::string lastName_;
    std::string fullName_;
};

#endif // PERSON_H

/*
  IMMUTABLE
  */
