//  student.h
#pragma once
#include <iostream>
#include "degree.h"
#include <string>
using namespace std;

const static int daysArraySize = 3;
    //requirement D1: creating a Student class
class Student {
private:
    string studentID;
    string first;
    string last;
    string email;
    int age;
    DegreeProgram degreeProgram;
    int numOfDays [daysArraySize];
public:
    //requirement D2D: constructor for student class with each input parameter from data table
    Student();
    Student(string studentID, string first, string last, string email, int age, int numOfDays[], DegreeProgram degreeProgram);
    //requirement D2A: creating accessor functions ("getters") for each instance variable
    string getID();
    string getFirst();
    string getLast();
    string getEmail();
    int getAge();
    int* getNumOfDays();
    DegreeProgram getDegreeProgram();
    
        //requirement D2B: creating mutator ("setter") functions for each instance variable
    void setID(string studentID);
    void setFirst(string first);
    void setLast(string last);
    void setEmail(string email);
    void setAge (int age);
    void setNumOfDays(int numOfDays[]);
    void setDegreeProgram(DegreeProgram dp);
    
    void print();
    
    ~Student();
};
