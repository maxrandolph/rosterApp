#pragma once
#include <string>
#include "degree.h"

class Student
{
public:
    // Members
    std::string s_studentId;
    std::string s_firstName;
    std::string s_lastName;
    std::string s_emailAddress;
    int s_age;
    int s_numberOfDaysToCompleteEachCourse[3];
    Degree s_degreeType;

    // ctor
    Student(std::string, std::string, std::string, std::string, int, int[3]);
    Student();
    // dtor
    ~Student();
    // Getters
    std::string getId();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getNumberOfDaysToCompleteEachCourse();
    virtual Degree getDegreeProgram();
    // Setters
    void setId(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setAge(int);
    void setNumberofDaysToCompleteEachCourse(int, int);
    virtual void setDegreeType(Degree);
    // Functions
    virtual void print();
};