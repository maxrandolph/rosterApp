#include "student.h"
// Ctor
Student::Student(int studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[], Degree degreeType)
{
}
// Getters
int Student::getId()
{
    return studentId;
}

std::string Student::getFirstName()
{
    return firstName;
}

std::string Student::getLastName()
{
    return lastName;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

int * Student::getNumberOfDaysToCompleteEachCourse()
{
    return numberOfDaysToCompleteEachCourse;
}

Degree Student::getDegree()
{
    return degreeType;
}
// Setters
void Student::setId(int value)
{
    studentId = value;
}

void Student::setFirstName(std::string value)
{
    firstName = value;
}

void Student::setLastName(std::string value)
{
    lastName = value;
}

void Student::setAge(int value)
{
    age = value;
}

void Student::setNumberofDaysToCompleteEachCourse(int value, int courseIndex)
{
    numberOfDaysToCompleteEachCourse[courseIndex] = value;
}

void Student::setDegreeType(Degree value)
{
    degreeType = value;
}
