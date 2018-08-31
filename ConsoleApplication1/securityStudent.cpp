#include "SecurityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent()
{
}

SecurityStudent::SecurityStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3])
    :Student(studentId, firstName, lastName, emailAddress, age, numberOfDaysToCompleteEachCourse)
{
    setDegreeType(SECURITY);
}

SecurityStudent::~SecurityStudent()
{
}

Degree SecurityStudent::getDegreeProgram()
{
    return s_degreeType;
}

void SecurityStudent::print()
{
    int *daysToComplete = getNumberOfDaysToCompleteEachCourse();
    std::cout << "\tFirst Name: " << getFirstName()
        << "\tLast Name: " << getLastName()
        << "\tAge: " << getAge()
        << "\tdaysInCourse: {" << daysToComplete[0] << "," << daysToComplete[1] << "," << daysToComplete[2] << "}"
        << "\tDegree Program: " << static_cast<int>(getDegreeProgram()) << "\n";
}
