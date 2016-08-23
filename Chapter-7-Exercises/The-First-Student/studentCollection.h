#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include "studentRecord.h"

typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2);

bool higherGrade(studentRecord r1, studentRecord r2);
bool lowerStudentNumber(studentRecord r1, studentRecord r2);
bool nameComesFirst(studentRecord r1, studentRecord r2);


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
    void setFirstStudentPolicy(firstStudentPolicy f);
    studentRecord firstStudent();
private:
    firstStudentPolicy _currentPolicy;
    typedef studentNode* studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};



#endif // STUDENTCOLLECTION_H
