#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include "roster.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    // Array of student pointers.

    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Maximilian,Randolph,mrand42@wgu.edu,23,5,10,15,SOFTWARE" };

    Roster* mainRoster = new Roster();

    // initialize array with input data. 5 is the default starting quantity.
    for (int i = 0; i < 5; i++)
    {
        Student * tempStudent = mainRoster->GenerateStudent(studentData[i]);
        int * courseDays = tempStudent->getNumberOfDaysToCompleteEachCourse();

        mainRoster->add(tempStudent->getId(), tempStudent->getFirstName(), tempStudent->getLastName(),
            tempStudent->getEmailAddress(), tempStudent->getAge(), courseDays[0], courseDays[1], courseDays[2], tempStudent->getDegreeProgram());

    }
    mainRoster->printAll();
    mainRoster->printInvalidEmails();
    //loop through classRosterArray and for each element:
    for (std::vector<int>::size_type i = 0; i != mainRoster->classRosterArray.size(); i++)
    {
        mainRoster->printDaysInCourse(mainRoster->classRosterArray[i]->getId());
    }

    mainRoster->printByDegreeProgram(SOFTWARE);
    mainRoster->remove("A3");
    mainRoster->remove("A3");
    mainRoster->printAll();
}

Roster::Roster()
{
    std::vector<Student*> classRosterArray;
    
}

/// Generate a student and return the pointer to new student.
Student* Roster::GenerateStudent(std::string studentData)
{
    Student* newStudent = new Student();
    size_t pos = 0;
    std::string t;
    int i = 0;
    // Iterate through the comma-delimited string fand assign values based on index.
    while ((pos = studentData.find(',')) != std::string::npos) {
        t = studentData.substr(0, pos);
        switch (i)
        {
        case 0:
            newStudent->setId(t);
            break;
        case 1:
            newStudent->setFirstName(t);
            break;
        case 2:
            newStudent->setLastName(t);
        case 3:
            newStudent->setEmailAddress(t);
            break;
        case 4:
            newStudent->setAge(std::stoi(t));
            break;
        case 5:
            newStudent->setNumberofDaysToCompleteEachCourse(std::stoi(t), 0);
            break;
        case 6:
            newStudent->setNumberofDaysToCompleteEachCourse(std::stoi(t), 1);
            break;
        case 7:
            newStudent->setNumberofDaysToCompleteEachCourse(std::stoi(t), 2);
            break;
        default:
            break;
        }
        studentData.erase(0, pos + 1);
        i++;
    }
    // At this point, studentData only equals the remaining value which is equal to the degree type.
    if (studentData == "NETWORK")
    {
        NetworkStudent* newChild = new NetworkStudent(newStudent->getId(), newStudent->getFirstName(), newStudent->getLastName(), newStudent->getEmailAddress(), newStudent->getAge(), newStudent->getNumberOfDaysToCompleteEachCourse());
        return newChild;
    }
    else if (studentData == "SOFTWARE")
    {
        SoftwareStudent* newChild = new SoftwareStudent(newStudent->getId(), newStudent->getFirstName(), newStudent->getLastName(), newStudent->getEmailAddress(), newStudent->getAge(), newStudent->getNumberOfDaysToCompleteEachCourse());
        return newChild;
    }
    else if (studentData == "SECURITY")
    {
        SecurityStudent* newChild = new SecurityStudent(newStudent->getId(), newStudent->getFirstName(), newStudent->getLastName(), newStudent->getEmailAddress(), newStudent->getAge(), newStudent->getNumberOfDaysToCompleteEachCourse());
        return newChild;
    }
    return newStudent;
}
/// Adds student to the roster array.
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
    int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    if (degreeProgram == NETWORKING)
    {
        NetworkStudent* newChild = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete);
        classRosterArray.push_back(newChild);
    }
    else if (degreeProgram == SOFTWARE)
    {
        SoftwareStudent* newChild = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete);
        classRosterArray.push_back(newChild);
    }
    else if (degreeProgram == SECURITY)
    {
        SecurityStudent* newChild = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete);
        classRosterArray.push_back(newChild);
    }
}
/// Removes student with studentID parameter from roster array.
void Roster::remove(std::string studentID)
{
    int studentIndex = findStudentIndex(studentID);
    if (studentIndex != -1)
    {
        classRosterArray.erase(classRosterArray.begin() + studentIndex);
        return;
    }
    else
    {
        std::cout << "Student with ID: " << studentID << " was not found in the roster.";
        return;
    }
}
/// Print tab delimited representation of current student roster.
void Roster::printAll()
{
    for (std::vector<int>::size_type i = 0; i != classRosterArray.size(); i++)
    {
        classRosterArray[i]->print();
    }
}
/// Print average course time for the student assigned the passed studentId.
void Roster::printDaysInCourse(std::string studentID)
{
    int studentIndex = findStudentIndex(studentID);
    if (studentIndex != -1)
    {
        int *daysToComplete = classRosterArray[studentIndex]->getNumberOfDaysToCompleteEachCourse();
        std::cout << (daysToComplete[0] + daysToComplete[1] + daysToComplete[2]) / 3 << "\n";
    }
}
/// Print emails deemed "invalid" as in having either no @ symbol or spaces.
void Roster::printInvalidEmails()
{
    std::cout << "\nInvalid emails:\n";
    std::string emailToCheck;
    for (std::vector<int>::size_type i = 0; i != classRosterArray.size(); i++)
    {
        emailToCheck = classRosterArray[i]->getEmailAddress();
        if (emailToCheck.find('@') == std::string::npos || emailToCheck.find(' ') != std::string::npos)
        {
            std::cout << emailToCheck << "\n";
        }
    }
}
/// Print student information by degree type.
void Roster::printByDegreeProgram(Degree degreeProgram)
{
    for (std::vector<int>::size_type i = 0; i != classRosterArray.size(); i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
}
std::vector<Student*> Roster::getClassRosterArray()
{
    return classRosterArray;
}
/// Returns the index of the student with the passed id. If no match is found, return -1.
int Roster::findStudentIndex(std::string studentID)
{
    for (std::vector<int>::size_type i = 0; i != classRosterArray.size(); i++)
    {
        if (classRosterArray[i]->getId() == studentID)
        {
            return i;
        }
    }
    return -1;
}
