/*
*   Problem: Variable-Length String Manipulation
*
*   Write heap-based implementations for three required string functions:
*
*   append - This function takes a string and a character and appends the
*   character to the end of the string.
*
*   concatenate - This function takes two strings and appends the characters
*   of the second string onto the first.
*
*   characterAt - This function takes a string and a number and returns the
*   character at that position in the string (with the first character in the
*   string numbered zero).
*
*   Write the code with the assumption that characterAt will be called
*   frequently while the other two functions will be called reletively seldom.
*   The relative efficiency of the operations should reflect the calling
*   frequency.
*/

#include <iostream>
#include <string>

typedef char *arrayString;

char characterAt(arrayString s, int position);

int length(arrayString s);

void append(arrayString &s, char c);

void appendTester();

void concatenate(arrayString &s1, arrayString &s2);

void concatenateTester();

int main()
{
    appendTester();

    std::cout << std::endl;

    concatenateTester();
}

char characterAt(arrayString s, int position)
{
    return s[position];
}

int length(arrayString s)
{
    int count = 0;
    while (s[count] != 0)
    {
        count++;
    }
    return count;
}

void append(arrayString &s, char c)
{
    int oldLength = length(s);

    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++)
    {
        newS[i] = s[i];
    }

    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void appendTester()
{
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    append(a, '!');
    std::cout << a << '\n';

    arrayString b = new char[1];
    b[0] = 0;
    append(b, '!');
    std::cout << b << '\n';
}

void concatenate(arrayString &s1, arrayString &s2)
{
    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;

    arrayString newS = new char[s1_NewLength + 1];
    // copy s1 into beginning of newS
    for (int i = 0; i < s1_OldLength; i++)
    {
        newS[i] = s1[i];
    }
    // add s2 to end of newS
    for (int i = 0; i < s2_Length; i++)
    {
        newS[s1_OldLength + i] = s2[i];
    }
    // add the null character to end of newS
    newS[s1_NewLength] = 0;
    // deallocate s1 from heap
    delete[] s1;
    s1 = newS;
}

void concatenateTester()
{
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    concatenate(a, b);
    std::cout << a << '\n';

    std::cout << std::endl;

    arrayString c = new char[5];
    c[0] = 't'; c[1] = 'e'; c[2] = 's'; c[3] = 't'; c[4] = 0;
    arrayString d = new char[1];
    d[0] = 0;
    concatenate(d, c);
    std::cout << c << "----" << d << '\n';
    std::cout << (void *) c << "----" << (void *) d << '\n';
}
