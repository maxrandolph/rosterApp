
#include "networkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent()
{
}

NetworkStudent::NetworkStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3])
    :Student(studentId, firstName, lastName, emailAddress, age, numberOfDaysToCompleteEachCourse)
{
    setDegreeType(NETWORKING);
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
    int *daysToComplete = getNumberOfDaysToCompleteEachCourse();
    std::cout << "\tFirst Name: " << getFirstName()
        << "\tLast Name: " << getLastName()
        << "\tAge: " << getAge()
        << "\tdaysInCourse: {" << daysToComplete[0] << "," << daysToComplete[1] << "," << daysToComplete[2] << "}"
        << "\tDegree Program: " << static_cast<int>(getDegreeProgram()) << "\n";
}
