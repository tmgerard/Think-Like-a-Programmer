/*
*   Problem: Tracking an Unknown Quantity of Student Records
*
*   In this problem, you will write a class with methods to store and
*   manipulate a collection of student records. A student record contains
*   a student number and a grade, both integers, and a string for the student
*   name. The following functions are to be implemented:
*
*   addRecord - This method takes a student number, name, and grade and adds
*   a new record with this data to the collection.
*
*   recordWithNumber - This function takes a student number and retrieves the
*   record with that student number from the collection.
*
*   removeRecord - This function takes a student number and removes the record
*   with that student number from the collection.
*
*   The collection can be of any size. The addRecord operation is expected to
*   be called frequently, so it must be implemented efficiently.
*/

#include <iostream>
#include "studentRecord.h"
#include "studentCollection.h"

int main()
{
    studentCollection s;

    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");

    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);

    std::cout << "Student 2: " << s.recordWithNumber(4875).name() << " " << std::endl;
    std::cout << "Removing student 2" << std::endl;

    s.removeRecord(4875);

    std::cout << "Student 2: " << s.recordWithNumber(4875).name() << " " << std::endl;

    return 0;
}
