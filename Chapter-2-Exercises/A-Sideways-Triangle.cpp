/*
*   Problem: A Sideways Triangle
*
*   Write a program that uses only two output statemetns, cout << "#" and
*   cout << "\n" to produce a pattern of hash symbols shaped like a sideways
*   triangle:
*
*   #
*   ##
*   ###
*   ####
*   ###
*   ##
*   #
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>

int main()
{
    for (int row = 1; row <= 7; row++)
    {
        for (int hashNum = 1; hashNum <= 4 - abs(4 - row); hashNum++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}
