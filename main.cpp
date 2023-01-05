//  main.cpp
// requirement B: C++ project created with XCode
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;


int main() {
    //requirement F1: screen printout of course, language, student ID, student name
    cout << "Course = C867" << endl;
    cout << "Language Used = C++" << endl;
    cout << "WGU Student ID = 010535905" << endl;
    cout << "Name = Sarah MacKillop-Bird" << endl;
    cout << endl;
    cout << endl;

        // requirement A: personal data added to studentData Table
    const string studentData[] = {

        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Sarah,MacKillop-Bird,smackil@wgu.edu,32,47,33,55,SOFTWARE"
        };
    
    const int studentDataArraySize = 5;
    
        //requirement F2: creating an instance of the Roster class called classRoster
    Roster classRoster;
    
        //requirement F3: parse method calls add method to populate classRoster
    for (int i = 0; i < studentDataArraySize; i++) {
        classRoster.parse(studentData[i]);
    }
    
    //requirement F4: pseudocode converted into real code in order specified
    classRoster.printAll();
    classRoster.printInvalidEmails();

    //uses an accessor ("getter") as required for F4
    for (int i = 0; i < studentDataArraySize; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    classRoster.remove("A3");
}
