/*
*   Exercise 3-3
*
*   Write a bool function that is passed an array and the number of elements
*   in that array and determines wheter the data in the array is sorted. This
*   should require only one pass!
*/

#include <iostream>

bool isSorted(int intArray[], int SIZE);

int main()
{
    int one[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        std::cout << one[i] << " ";
    }
    std::cout << std::endl;

    if (isSorted(one, 5))
    {
        std::cout << "Sorted\n\n";
    }
    else
    {
        std::cout << "Not Sorted\n\n";
    }

    std::cout << std::endl;

    int two[4] = {2, 3, 1, 4};

    for (int i = 0; i < 4; i++)
    {
        std::cout << two[i] << " ";
    }
    std::cout << std::endl;

    if (isSorted(two, 4))
    {
        std::cout << "Sorted\n\n";
    }
    else
    {
        std::cout << "Not Sorted\n\n";
    }

    std::cout << std::endl;

    int three[4] = {1, 1, 2, 2};

    for (int i = 0; i < 4; i++)
    {
        std::cout << three[i] << " ";
    }
    std::cout << std::endl;

    if (isSorted(three, 4))
    {
        std::cout << "Sorted\n\n";
    }
    else
    {
        std::cout << "Not Sorted\n\n";
    }

}

bool isSorted(int intArray[], int SIZE)
{
    int current = intArray[0];
    for (int index = 1; index < SIZE; index++)
    {
        if (current > intArray[index])
        {
            return false;
        }
        current = intArray[index];
    }
    return true;
}
