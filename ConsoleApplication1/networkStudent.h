#pragma once
#include "student.h"

class NetworkStudent : private Student
{
public:
    NetworkStudent();
    NetworkStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3]);
    ~NetworkStudent();
    void print();
    Degree getDegreeProgram();
};
