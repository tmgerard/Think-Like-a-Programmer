/*
*   Exercise 2-2
*
*   Using only single-character output statements that output a hash mark,
*   a space, or an end-of-line symbol, write a program that outputs the
*   following shape:
*
*   #            #
*    ##        ##
*     ###    ###
*      ########
*      ########
*     ###    ###
*    ##        ##
*   #            #
*/

#include <iostream>

int main()
{
    // Top half
    for (int row = 1; row <= 4; row++)
    {
        for (int space = 1; space <= (row - 1); space++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= row; hashNum++)
        {
            std::cout << '#';
        }

        for (int space = 1; space <= 14 - 2 * ((row - 1) + row); space++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= row; hashNum++)
        {
            std::cout << '#';
        }
        std::cout << '\n';
    }

    // Bottom half
    for (int row = 1; row <= 4; row++)
    {
        for (int space = 1; space <= (4 - row); space++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= (5 - row); hashNum++)
        {
            std::cout << '#';
        }

        for (int space = 1; space <=  14 - 2 * ((4 - row) + (5 - row)); space++)
        {
            std::cout << ' ';
        }

        for (int hashNum = 1; hashNum <= (5 - row); hashNum++)
        {
            std::cout << '#';
        }
        std::cout << '\n';
    }
}
