//roster.h
#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

static const int numStudents = 5;

class Roster {
public:
    int lastIndex = -1;
    //requirement E1: creating an array of pointers to hold the data from the studentData table
    Student* classRosterArray[numStudents];
    void parse(string row);
    void add(string sID,
             string sFirst,
             string sLast,
             string sEmail,
             int sAge,
             int numDays1,
             int numDays2,
             int numDays3,
             DegreeProgram dp);
    void printAll();
    void printByDegreeProgram(DegreeProgram dp);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void remove(string studentID);
    ~Roster();
};
