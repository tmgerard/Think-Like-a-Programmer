/*
*   Exercise 4-2
*
*   For our dynamically allocated strings, create a function substring that
*   takes three parameters: an arrayString, a starting position integer, and
*   an integer length of characters. The function returns a pointer to a new
*   dynamically allocated string array. This string array contains the
*   characters in the original string, starting at the specified position
*   for the specified length. The original string is unaffected by the
*   operation. So if the original string abcdefg, the position was 3, and the
*   length was 4, then the new string would contain cdef.
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

arrayString substring(arrayString s, int start, int length);

void substringTester();

int main()
{
    appendTester();

    std::cout << std::endl;

    concatenateTester();

    std::cout << std::endl;

    substringTester();
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

arrayString substring(arrayString s, int start, int len)
{
    // add check to avoid calling length past end of string
    arrayString newS = new char[len + 1];
    // copy selected section into new string
    int count = 0;
    for (int i = start; i < start + len; i++)
    {
        newS[count] = s[i];
        count++;
    }
    newS[len] = 0;
    delete[] s;
    return newS;
}

void substringTester()
{
    arrayString a = new char[8];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 'i'; a[5] = 'n';
    a[6] = 'g'; a[7] = 0;
    std::cout << substring(a, 1, 4);
}

