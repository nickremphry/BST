//****************************************************************************************************
//
//      File:           StudentList.cpp
//
//      Student:        Michael Remphry
//
//      Assignment:     Program #9
//
//      Course Name:    Data Structures II
//
//      Course Number:  COSC 3100 - 10
//
//      Due:            April 23, 2019
//
//      This is a program to create a list of students using a linked list
//
//      Other files required:
//              1. Student.h
//              2. BST.h
//              3. Node.h
//
//****************************************************************************************************

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "Student.h"
#include "BST.h"

//****************************************************************************************************

void process(BST<Student> &);
char getChoice();
void buildList(BST<Student> &);
void displayStudents(Student);
void printStudents(BST<Student> &);
void listInformation(BST<Student> &);

void addStudent(BST<Student> &);
void searchStudent(BST<Student> &);
void updateStudent(BST<Student> &);
void deleteStudent(BST<Student> &);

//****************************************************************************************************

int main()
{
    BST<Student> studentList;

    buildList(studentList);
    process(studentList);
    
    return 0;
}

//****************************************************************************************************

void process(BST<Student> & studentList)
{
    char choice;
    
    do
    {
        choice = getChoice();

        switch(choice)
        {
            case 'A': addStudent(studentList);
                      break;
            case 'S': updateStudent(studentList);
                      break;
            case 'U': updateStudent(studentList);
                      break;
            case 'D': deleteStudent(studentList);
                      break;
            case 'P': printStudents(studentList);
                      break;
            case 'L': listInformation(studentList);
                      break;
            case 'Q': break;
        }
    } 
    while (choice != 'Q');
}

//****************************************************************************************************

char getChoice()
{
    char choice;
    bool valid;

    cout << "======== MENU ========\n"
         << " A: Add a Student\n"
         << " S: Search a Student\n"
         << " U: Update a Student\n"
         << " D: Delete a Student\n"
         << " P: Display all Students\n"
         << " L: List Information\n"
         << " Q: Quit\n\n"
         << " Enter your choice: ";

    do
    {
        cin >> choice;
        choice = toupper(choice);

        cout << endl;

        switch (choice)
        {
            case 'A':
            case 'S':
            case 'U':
            case 'D':
            case 'P':
            case 'L':
            case 'Q': valid = true;
                      break;
            default:  valid = false;
                      cout << "\aInvalid choice\n" << "Please try again: ";
                      break;
        }
    }
    while (!valid);

    return choice;
}

//****************************************************************************************************

void buildList(BST<Student> & studentList)
{
    Student student;
    ifstream studentData;

    studentData.open("studentFile.txt");

    while (studentData >> student.id)
    {
        studentData.ignore();
        studentData.getline(student.name, 50);
        studentData.getline(student.citystate, 50);
        studentData >> (student.phone);
        studentData >> (student.gender);
        studentData >> (student.year);
        studentData >> (student.credits);
        studentData >> (student.gpa);
        studentData >> (student.major);

        studentList.insert(student);
    }

    studentData.close();
}

//****************************************************************************************************

void displayStudent(Student student)
{
    cout << student;
}

//****************************************************************************************************

void printStudents(BST<Student> & studentList)
{
    cout << "==============================================================================" << endl;
    cout << "ID" << setw(5) << "Name" << setw(10) << "Major" << setw(5) << "GPA" << setw(5)
         << "Credits" << endl;

    studentList.inOrderTraversal(displayStudent);

    cout << endl;
}

//****************************************************************************************************

void listInformation(BST<Student> & studentList)
{
    int count = studentList.getCount();
    int height = studentList.getHt();

    cout << "Information about the student tree: " << endl;
    cout << "Students in the list: " << count << endl;
    cout << "Height of the list: " << height << endl;

    if (!studentList.isEmpty())
    {
        cout << "This list is not empty" << endl;
    }
    else
    {
        cout << "This list is empty" << endl;
    }

    if(!studentList.isFull())
    {
        cout << "This list is not full" << endl;
    }
    else
    {
        cout << "This list is full" << endl;
    }

    cout << endl;
}

//****************************************************************************************************

void addStudent(BST<Student> & studentList)
{
    Student student;

    cout << "What is the new student's ID?: ";
    cin >> student.id;
    cout << "What is the student's name: ";
    cin.ignore();
    cin.getline(student.name, 50);
    cout << "What is the student's citystate: ";
    cin.getline(student.citystate, 50);
    cout << "What is the student's phone: (Format: 1234567890)";
    cin >> student.phone;
    cout << "What is the student's gender: (enter 'M' or 'F')" << endl;
    cin >> student.gender;
    cout << "What year is the student: ";
    cin >> student.year;
    cout << "How many credits does the student have: ";
    cin >> student.credits;
    cout << "What is the student's GPA: ";
    cin >> student.gpa;
    cout << "What is the students major: (Enter abbriviated major)" << endl;
    cin >> student.major;

    studentList.insert(student);
}

//****************************************************************************************************

void searchStudent(BST<Student> & studentList)
{
    Student student;
    int id;

    cout << "Which student would you like to find? : ";
    cin >> id;

    student.id = id;

    if(!studentList.retrieve(student))
    {
        cout << "Could not find that student\n" << endl;
    }
    else
    {
        cout << "Here is that student: " << endl;
        cout << student << endl;
    }
}

//****************************************************************************************************

void updateStudent(BST<Student> & studentList)
{
    Student student;

    cout << "Which student would you like to update? : ";
    cin >> student.id;

    if(!studentList.update(student))
    {
        cout << "Could not find that student" << endl;
    }
    else
    {
        cout << "What is the new student's ID?: ";
    cin >> student.id;
    cout << "What is the student's name: ";
    cin.ignore();
    cin.getline(student.name, 50);
    cout << "What is the student's citystate: ";
    cin.getline(student.citystate, 50);
    cout << "What is the student's phone: (Format: 1234567890)";
    cin >> student.phone;
    cout << "What is the student's gender: (enter 'M' or 'F')" << endl;
    cin >> student.gender;
    cout << "What year is the student: ";
    cin >> student.year;
    cout << "How many credits does the student have: ";
    cin >> student.credits;
    cout << "What is the student's GPA: ";
    cin >> student.gpa;
    cout << "What is the students major: (Enter abbriviated major)" << endl;
    cin >> student.major;
    }
    
    cout << "\nHere is the updated student: " << endl;
    cout << student << endl;

}

//****************************************************************************************************

void deleteStudent(BST<Student> & studentList)
{
    Student student;
    int id;

    cout << "Which student would you like to delete? : ";
    cin >> id;

    student.id = id;

    if(!studentList.remove(student))
    {
        cout << "Could not remove that student\n" << endl;
    }
    else
    {
        cout << "Here is the removed student:\n" << endl;
        cout << student << endl;
    }
}

//****************************************************************************************************

