#ifndef SCITERATOR_H
#define SCITERATOR_H

#include "../Chapter-7-Exercises/studentRecord2.h"
#include "../Chapter-7-Exercises/studentCollection2.h"

class studentCollection;

class scIterator
{
    public:
        scIterator();
        scIterator(studentCollection::studentNode* initial);
        void advance();
        bool pastEnd();
        studentRecord student();
    private:
        studentCollection::studentNode* current;
};

#endif // SCITERATOR_H
