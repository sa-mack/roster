// roster.cpp
#include "roster.h"

using namespace std;

//requirement E2A: parsing the data from studentData table
void Roster::parse(string studentdata) {
    
        size_t rhs = studentdata.find(",");
        string sID = studentdata.substr(0, rhs);

        size_t lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        string sFirst = studentdata.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        string sLast = studentdata.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        string sEmail = studentdata.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        int sAge = stoi(studentdata.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        int sDay1 = stoi(studentdata.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        int sDay2 = stoi(studentdata.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        int sDay3 = stoi(studentdata.substr(lhs, rhs - lhs));
        
    DegreeProgram degreeProgram;
    
        char lastChar = studentdata.at(studentdata.length()-1);
        if (lastChar == 'E') degreeProgram = SOFTWARE;
        else if (lastChar == 'Y') degreeProgram = SECURITY;
        else degreeProgram = NETWORK;
        
        add(sID, sFirst, sLast, sEmail, sAge, sDay1, sDay2, sDay3, degreeProgram);

};
//requirement E3A: add function
void Roster::add(string studentID,
                 string first,
                 string last,
                 string email,
                 int age,
                 int numDays1,
                 int numDays2,
                 int numDays3,
                 DegreeProgram dp)

{
    int daysArray [] = {numDays1, numDays2, numDays3};
    //requirement E2: creating a new student object for each student in classRosterArray
    //requirement E2B: each student object is added to classRosterArray
    classRosterArray[++lastIndex] = new Student (studentID, first, last, email, age, daysArray, dp);
}
    //requirement E3C: printAll function
void Roster::printAll() {
    
    cout << "Displaying all students in the format of:" << endl;
    
    cout << "Student ID | First Name | Last Name | Age | Days Left in Courses | Degree Program" << endl;
    cout << endl;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        
        Roster::classRosterArray[i]->print();
    }
    cout << endl;
}
    //requirement E3F: printByDegreeProgram function
void Roster::printByDegreeProgram(DegreeProgram dp) {
    cout << "Displaying all students in the Software program:" << endl;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == 2) classRosterArray[i]->print();
    }
    cout << endl;
}
    //requirement E3E: printInvalidEmails function
void Roster::printInvalidEmails() {
    bool isInvalid = false;
    cout << "Displaying invalid emails:" << endl;
    cout << endl;
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = (classRosterArray[i]->getEmail());
        string sID = (classRosterArray[i]->getID());
        if (email.find(" ") != string::npos || (email.find(".") == string::npos || (email.find("@") == string::npos))) {
            isInvalid = true;
            cout << classRosterArray[i]->getFirst() << " " << classRosterArray[i]->getLast() << " is using an invalid email: " << email << endl;
        }

    } if (!isInvalid) cout << "No invalid emails found." << endl;
    cout << endl;
}
    //requirement E3D: printAverageDaysInCourse function
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==studentID)
        {
            cout << "Average days left in courses for student " << studentID << ": ";
            cout << (classRosterArray[i]->getNumOfDays()[0]+
                     classRosterArray[i]->getNumOfDays()[1]+
                     classRosterArray[i]->getNumOfDays()[2])/3 << endl;
        }
    }
}
//requirement E3B: remove function
void Roster::remove(string studentID) {
    bool idExists = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getID() == studentID) {
            idExists = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (idExists) {
        cout << studentID << " has been removed from roster." << endl;
    }
    else cout << studentID << " not found on roster." << endl;

}
    //requirement F5: Roster destructor
Roster::~Roster() {
    
}
