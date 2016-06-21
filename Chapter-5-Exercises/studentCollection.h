#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include "studentRecord.h"

class studentCollection
{
private:
    struct studentNode
    {
        studentRecord studentData;
        studentNode* next;
    };
public:
    studentCollection();
    studentCollection(const studentCollection& original);
    ~studentCollection();
    studentCollection& operator=(const studentCollection& rhs);
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
private:
    typedef studentNode* studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

#endif // STUDENTCOLLECTION_H
