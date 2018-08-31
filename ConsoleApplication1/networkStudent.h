#pragma once
#include "student.h"

class NetworkStudent : public Student
{
private:
    std::string s_studentId;
    std::string s_firstName;
    std::string s_lastName;
    std::string s_emailAddress;
    int s_age;
    int* numberofDaysToCompleteEachCourse;
public:
    NetworkStudent();
    NetworkStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3]);
    ~NetworkStudent();
    void print();
    Degree getDegreeProgram();
};
