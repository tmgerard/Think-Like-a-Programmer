#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include<string>

class studentRecord
{
public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    int grade();
    bool isValidGrade(int grade);
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);
    std::string letterGrade();
private:
    int _grade;
    int _studentID;
    std::string _name;
};

#endif // STUDENTRECORD_H
