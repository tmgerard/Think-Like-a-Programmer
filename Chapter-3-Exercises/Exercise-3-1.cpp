/*
*   Exercise 3-1
*
*   Are you disappointed we didn't do more with sorting? I'm here to help.
*   To make sure you are comfortable with qsort, write code that uses the
*   function to sort an array of our student struct. First have it sort by
*   grade, and then try it again using the student ID.
*/

#include<iostream>
#include<stdlib.h>
#include<string>

struct student
{
    int grade;
    int studentID;
    std::string name;
};

// forward declare compare function for qsort by grade
int compareGrades(const void* A, const void* B);

// forward declare compare function for qsort by ID
int compareID(const void* A, const void* B);

int main()
{
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    // print unsorted array to console
    std::cout << "Initial Array\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].grade << '\t'
                  << studentArray[i].studentID << '\t'
                  << studentArray[i].name << '\n';
    }

    std::cout << '\n';

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);

    // print sorted array to console
    std::cout << "Sorted by grade\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].grade << '\t'
                  << studentArray[i].studentID << '\t'
                  << studentArray[i].name << '\n';
    }

    std::cout << '\n';

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareID);

    // print sorted array to console
    std::cout << "Sorted by student ID\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].grade << '\t'
                  << studentArray[i].studentID << '\t'
                  << studentArray[i].name << '\n';
    }

    return 0;
}

// compare function for qsort by grade
int compareGrades(const void* A, const void* B)
{
    student* studentA = (student*)(A);
    student* studentB = (student*)(B);
    return (studentA->grade - studentB->grade);
}

// compare function for qsort by ID
int compareID(const void* A, const void* B)
{
    student* studentA = (student*)(A);
    student* studentB = (student*)(B);
    return (studentA->studentID - studentB->studentID);
}
