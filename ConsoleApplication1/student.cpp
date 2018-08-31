#include "student.h"
// Ctor
Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[3])
{
    s_studentId = studentId;
    s_firstName = firstName;
    s_lastName = lastName;
    s_emailAddress = emailAddress;
    s_age = age;
    s_numberOfDaysToCompleteEachCourse[3] = *numberOfDaysToCompleteEachCourse;
}
Student::Student()
{
}
// Dtor
Student::~Student()
{

}

// Getters
std::string Student::getId()
{
    return s_studentId;
}

std::string Student::getFirstName()
{
    return s_firstName;
}

std::string Student::getLastName()
{
    return s_lastName;
}

std::string Student::getEmailAddress()
{
    return s_emailAddress;
}

int Student::getAge()
{
    return s_age;
}

int * Student::getNumberOfDaysToCompleteEachCourse()
{
    return s_numberOfDaysToCompleteEachCourse;
}

Degree Student::getDegreeProgram()
{
    return s_degreeType;
}
// Setters
void Student::setId(std::string value)
{
    s_studentId = value;
}

void Student::setFirstName(std::string value)
{
    s_firstName = value;
}

void Student::setLastName(std::string value)
{
    s_lastName = value;
}

void Student::setAge(int value)
{
    s_age = value;
}

void Student::setNumberofDaysToCompleteEachCourse(int value, int courseIndex)
{
    s_numberOfDaysToCompleteEachCourse[courseIndex] = value;
}

void Student::setDegreeType(Degree)
{
}

void Student::print()
{
}

