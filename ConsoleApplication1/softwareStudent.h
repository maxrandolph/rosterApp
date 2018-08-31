#pragma once
#include "student.h"

class SoftwareStudent : public Student
{
private:
    std::string s_studentId;
    std::string s_firstName;
    std::string s_lastName;
    std::string s_emailAddress;
    int s_age;
    int* numberofDaysToCompleteEachCourse;
public:
    SoftwareStudent();
    SoftwareStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3]);
    ~SoftwareStudent();
    void print();
    Degree getDegreeProgram();
};
