#pragma once
#include "student.h"

class SecurityStudent : public Student
{
private:
    std::string s_studentId;
    std::string s_firstName;
    std::string s_lastName;
    std::string s_emailAddress;
    int s_age;
    int* numberofDaysToCompleteEachCourse;
public:
    SecurityStudent();
    SecurityStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3]);
    ~SecurityStudent();
    void print();
    Degree getDegreeProgram();
};
