/*
*   Problem: Class Roster
*
*   Design a class or set of classes for use in a program that maintains a
*   roster. For each student, store the student's name, ID, and final grade
*   score in the range 0 - 100. The program will allow student records to be
*   added or removed; display the record of a particular student, identified
*   by ID, with the grade displayed as a number and as a letter; and display
*   the average score for the class. The appropriate letter grade for a
*   particular score is shown in table 5-1.
*
*   Table 5-1: Letter Grades
*   Score Range     Letter Grade
*   93-100          A
*   90-92           A-
*   87-89           B+
*   83-86           B
*   80-82           B-
*   77-79           C+
*   73-76           C
*   70-72           C-
*   67-69           D+
*   60-66           D
*   0-59            F
*/

#include <iostream>
#include <string>
#include "studentRecord.h"

int main()
{
    studentRecord Tom(97, 1, "Tom Gerard");

    std::cout << Tom.name() << '\t' << Tom.studentID() << '\t'
              << Tom.grade() << '\t' << Tom.letterGrade() << std::endl;
}
