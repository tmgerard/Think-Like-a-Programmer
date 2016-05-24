/*
*   Problem: Half of a Square
*
*   Write a program that uses only two output statemetns, cout << "#" and
*   cout << "\n" to produce a pattern of hash symbols shaped like half of a
*   perfect 5 x 5 square (or a right triangle):
*
*   #####
*   ####
*   ###
*   ##
*   #
*/

#include <iostream>

int main()
{
    for(int row = 1; row <= 5; row++)
    {
        for (int hashNum = 1; hashNum <= 6 - row; hashNum++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}
