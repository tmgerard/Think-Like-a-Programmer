#ifndef SCITERATOR_H
#define SCITERATOR_H

#include "studentRecord.h"
#include "studentCollection.h"

class studentCollection;

class scIterator
{
    public:
        scIterator();
         // compiler raises error here
         // expected ')' before '*' token
        scIterator(studentCollection::studentNode* initial);
        void advance();
        bool pastEnd();
        studentRecord student();
    private:
        // compiler raises error here
        // 'studentNode' in 'class studentCollection' does not name a type
        studentCollection::studentNode* current;
};

#endif // SCITERATOR_H
