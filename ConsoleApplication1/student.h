#pragma once
#include <string>
#include "degree.h"

class Student
{
private:
    int studentId;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int numberOfDaysToCompleteEachCourse[1000];
    Degree degreeType;
public:
    // ctor
    Student(int studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDaysToCompleteEachCourse[], Degree degreeType);
    // Getters
    int getId();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getNumberOfDaysToCompleteEachCourse();
    Degree getDegree();
    // Setters
    void setId(int);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setAge(int);
    void setNumberofDaysToCompleteEachCourse(int, int);
    void setDegreeType(Degree);

};