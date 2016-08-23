/*
*   Problem: Efficient Traversal
*
*   A programming project will use your studentCollection class. The client code
*   needs the ability to traverse all of the students in the collection. Obviously,
*   to maintain information hiding, the client code cannot be given direct access
*   to the list, but it's a requirement that the traversals are efficient.
*/

#include <iostream>
#include <string.h>
#include "studentCollection.h"
#include "studentRecord.h"
#include "scIterator.h"

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

    scIterator iter;
    int gradeTotal = 0;
    int numRecords = 0;

    iter = Collection.firstItemIterator();
    while (!iter.pastEnd())
    {
        numRecords++;
        gradeTotal += iter.student().grade();
        iter.advance();
    }

    double average = (double) gradeTotal / numRecords;

    std::cout << "Average grade is " << average << std::endl;

    return 0;
}
