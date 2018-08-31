
#include "networkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent()
{
}

NetworkStudent::NetworkStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3])
    :Student(studentId, firstName, lastName, emailAddress, age, numberOfDaysToCompleteEachCourse)
{
    s_degreeType = NETWORKING;
}

NetworkStudent::~NetworkStudent()
{
}

Degree NetworkStudent::getDegreeProgram()
{
    return s_degreeType;
}

void NetworkStudent::print()
{
    std::cout << "my name is is: " << s_firstName << " " << s_lastName
        << "\nI am " << s_age << " years old.";
}
