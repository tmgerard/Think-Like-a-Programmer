#include <string.h>
#include "studentCollection.h"
#include "studentRecord.h"

bool higherGrade(studentRecord r1, studentRecord r2)
{
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2)
{
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2)
{
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}


studentCollection::studentCollection()
{
    _listHead = NULL;
    _currentPolicy = NULL;
}

studentCollection::studentCollection(const studentCollection& original)
{
    _listHead = copiedList(original._listHead);
}

studentCollection::~studentCollection()
{
    deleteList(_listHead);
}
void studentCollection::addRecord(studentRecord newStudent)
{
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum)
{
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum)
    {
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL)
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    else
    {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum)
{
    studentNode* loopPtr = _listHead;
    studentNode* trailing = NULL;

    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum)
    {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL) return;

    if (trailing == NULL)
    {
        _listHead = _listHead->next;
    }
    else
    {
        trailing->next = loopPtr->next;
    }

    delete loopPtr;
}

void studentCollection::setFirstStudentPolicy(firstStudentPolicy f)
{
    _currentPolicy = f;
}

studentRecord studentCollection::firstStudent()
{
    if (_listHead == NULL || _currentPolicy == NULL)
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    studentNode* loopPtr = _listHead;
    studentRecord first = loopPtr->studentData;
    loopPtr = loopPtr->next;
    while (loopPtr != NULL)
    {
        if (_currentPolicy(loopPtr->studentData, first))
        {
            first = loopPtr->studentData;
        }
        loopPtr = loopPtr->next;
    }
    return first;
}

void studentCollection::deleteList(studentList &listPtr)
{
    while (listPtr != NULL)
    {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection::studentList studentCollection::copiedList(const studentList original)
{
    if (original == NULL)
    {
        return NULL;
    }

    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode* oldLoopPtr = original->next;
    studentNode* newLoopPtr = newList;

    while (oldLoopPtr != NULL)
    {

        newLoopPtr->next = new studentNode;
        newLoopPtr = newList->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

studentCollection& studentCollection::operator=(const studentCollection& rhs)
{
    if (this != &rhs)
    {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}
