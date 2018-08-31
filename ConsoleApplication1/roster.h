#pragma once
#include <string>
#include <vector>
#include "student.h"
class Roster
{
public:
    Roster();
    ~Roster();

    Student* GenerateStudent(std::string studentData);
    std::vector<Student*> classRosterArray;

    int findStudentIndex(std::string studentID);

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degreeProgram);
    std::vector<Student*> getClassRosterArray();
private:

};

