#include "../Chapter-7-Exercises/scIterator.h"
#include "../Chapter-7-Exercises/studentCollection2.h"
#include "../Chapter-7-Exercises/studentRecord2.h"

scIterator::scIterator()
{
    current = NULL;
}
scIterator::scIterator(studentCollection::studentNode* initial)
{
    current = initial;
}

void scIterator::advance()
{
    if (current != NULL)
    {
        current = current->next;
    }
}

bool scIterator::pastEnd()
{
    return current == NULL;
}

studentRecord scIterator::student()
{
    if (current == NULL)
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    else
    {
        return current->studentData;
    }
}
