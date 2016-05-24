/*
*   Exercise 2-1
*
*   Using only single-character output statements that output a hash mark,
*   a space, or an end-of-line symbol, write a program that outputs the
*   following shape:
*
*   ########
*    ######
*     ####
*      ##
*/

#include <iostream>
#include <stdlib.h>

int main()
{
    for(int row = 1; row <= 4; row++)
    {
        for (int space = 1; space <= (row - 1); space ++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= 8 - 2 * (row - 1); hashNum++)
        {
            std::cout << '#';
        }
        std::cout << "\n";
    }

    return 0;
}
