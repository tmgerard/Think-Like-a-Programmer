/*
*   Problem: The First Student
*
*   At a particular school, each class has a designated "first student" who is
*   responsible for maintaining order in the classroom if the teacher has to
*   leave the room. Originally, this title was bestowed upon the student with the
*   highest grade, but now some teachers thing the first student should be the
*   student with the greatest seniority, which means the lowest student ID number,
*   as they are assigned sequentially. Another faction of teachers thinks the
*   first student tradition is silly and intends to protest by simply choosing the
*   student whose name appears first in the alphabetical class roll. Our task is to
*   modify the student collection class, adding a method to retrieve the first
*   student from the collection, while accommodating the selection criteria of the
*   various teacher groups.
*/

#include <iostream>
#include <string.h>
#include "studentCollection.h"
#include "studentRecord.h"

int main()
{
    // create some student records
    studentRecord Tom(97, 1, "Tom");
    studentRecord Holly(98, 2, "Holly");
    studentRecord Sophie(100, 3, "Sophie");
    studentRecord Wrigley(93, 4, "Wrigley");

    // create collection and add records
    studentCollection Collection;
    Collection.addRecord(Tom);
    Collection.addRecord(Holly);
    Collection.addRecord(Sophie);
    Collection.addRecord(Wrigley);

    // change the policy and output results
    Collection.setFirstStudentPolicy(higherGrade);
    std::cout << "First Student by Highest Grade" << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl << std::endl;

    Collection.setFirstStudentPolicy(lowerStudentNumber);
    std::cout << "First Student by Lowest Student Number" << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl << std::endl;

    Collection.setFirstStudentPolicy(nameComesFirst);
    std::cout << "First Student by Name" << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl << std::endl;

    return 0;
}
