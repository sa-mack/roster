    //  student.cpp
#include "student.h"
using namespace std;


Student::Student() {
   this->studentID = " ";
   this->first = " ";
   this->last = " ";
   this->email = " ";
   this->age = 0;
   for (int i = 0; i < daysArraySize; i++) this->numOfDays[i] = 0;
   this->degreeProgram = DegreeProgram::SECURITY;
}


Student::Student(string studentID,string first,string last, string email, int age, int numOfDays[], DegreeProgram degreeProgram) {
   this->studentID = studentID;
   this->first = first;
   this->last = last;
   this->email = email;
   this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->numOfDays[i] = numOfDays[i];
   this->degreeProgram = degreeProgram;
  
}

string Student::getID() {return this->studentID;}
string Student::getFirst() {return this->first;}
string Student::getLast() {return this->last;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getNumOfDays() {return this->numOfDays;}
DegreeProgram Student::getDegreeProgram(){return this->degreeProgram;}


//requirement D2C: accessor and mutator usage
//requirement D2E: print method for Student class
void Student::print()
{
    cout << this->getID() << '\t';
    cout << this->getFirst() << '\t';
    cout << this->getLast() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getNumOfDays()[0] << ',';
    cout << this->getNumOfDays()[1] << ',';
    cout << this->getNumOfDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << endl;
}
