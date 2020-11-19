//****************************************************************************************************
//
//      File:           Student.h
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
//      This is a template for a binary search tree
//
//      Other files required:
//              1. Node.h
//              2. BST.h
//              3. StudentList.cpp
//
//****************************************************************************************************

#include <iomanip>

#ifndef STUDENT_H
#define STUDENT_H

//****************************************************************************************************

struct Student
{
    int id;
    char name[50];
    char citystate[50];
    char phone[12];
    char gender;
    int year;
    int credits;
    float gpa;
    char major[6];

    Student();
    friend ostream & operator << (ostream & out, const Student & data);
    bool operator == (const Student & rhs) const;
    bool operator == (int value) const;
    bool operator != (const Student & rhs) const;
    bool operator != (int value) const;
    bool operator < (const Student & rhs) const;
    bool operator < (int value) const;
    bool operator > (const Student & rhs) const;
    bool operator > (int value) const;
    bool operator <= (const Student & rhs) const;
    bool operator <= (int value) const;
    bool operator >= (const Student & rhs) const;
    bool operator >= (int value) const;
    int operator % (int value) const;
    Student & operator = (int value);
};

//****************************************************************************************************

Student::Student()
{
    id = 0;
}

//****************************************************************************************************

ostream & operator << (ostream & out, const Student & rhs)
{
    out << rhs.id << " " << rhs.name << " " << rhs.major << " " << rhs.gpa << " " 
        << rhs.credits << endl;

    return out;
}

//****************************************************************************************************

bool Student::operator == (const Student & rhs) const
{
    return (this->id == rhs.id);
}

//****************************************************************************************************

bool Student::operator == (int value) const
{
    return (this->id == value);
}

//****************************************************************************************************

bool Student::operator != (const Student & rhs) const
{
    return (this->id != rhs.id);
}

//****************************************************************************************************

bool Student::operator != (int value) const
{
    return (this->id != value);
}

//****************************************************************************************************

bool Student::operator < (const Student & rhs) const
{
    return (this->id < rhs.id);
}

//****************************************************************************************************

bool Student::operator < (int value) const
{
    return (this->id < value);
}

//****************************************************************************************************

bool Student::operator > (const Student & rhs) const
{
    return (this->id > rhs.id);
}

//****************************************************************************************************

bool Student::operator > (int value) const
{
    return (this->id > value);
}

//****************************************************************************************************

bool Student::operator <= (const Student & rhs) const
{
    return (this->id <= rhs.id);
}

//****************************************************************************************************

bool Student::operator <= (int value) const
{
    return (this->id <= value);
}

//****************************************************************************************************

bool Student::operator >= (const Student & rhs) const
{
    return (this->id >= rhs.id);
}

//****************************************************************************************************

bool Student::operator >= (int value) const
{
    return (this->id >= value);
}

//****************************************************************************************************

int Student::operator % (int value) const
{
    return (this->id % value);
}

//****************************************************************************************************

Student & Student::operator = (int value)
{
    this->id = value;
    return * this;
}

//****************************************************************************************************

#endif