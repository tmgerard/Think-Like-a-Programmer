/*
*   Exercise 2-2
*
*   Using only single-character output statements that output a hash mark,
*   a space, or an end-of-line symbol, write a program that outputs the
*   following shape:
*
*      ##
*     ####
*    ######
*   ########
*   ########
*    ######
*     ####
*      ##
*/

#include <iostream>

int main()
{
    // upper half
    for(int row = 1; row <= 4; row++)
    {
        for(int space = 1; space <= 3 - (row - 1); space++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= 2 + 2 * (row - 1); hashNum++)
        {
            std::cout << '#';
        }
        std::cout << '\n';
    }

    // lower half
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
        std::cout << '\n';
    }

    return 0;
}
