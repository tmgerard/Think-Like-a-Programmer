/*
*   Problem: Computing the Sum of an Array of Integers
*
*   Write a recursive function that is given an array of integers and the size
*   of the array as parameters. The function returns the sum of the integers
*   in the array.
*/

#include<iostream>

int iterativeArraySum(int integers[], int size);

int arraySumDelegate(int integers[], int size);

int arraySumRecursive(int integers[], int size);

int main()
{
    int size = 10;
    int numbers[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Iterative Approach" << std::endl;
    std::cout << "sum = " << iterativeArraySum(numbers, size) << std::endl << std::endl;

    std::cout << "Dispatcher Function" << std::endl;
    std::cout << "sum = " << arraySumDelegate(numbers, size) << std::endl << std::endl;

    std::cout << "Recursive Approach" << std::endl;
    std::cout << "sum = " << arraySumRecursive(numbers, size) << std::endl << std::endl;

    return 0;
}

int iterativeArraySum(int integers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += integers[i];
    }
    return sum;
}

int arraySumDelegate(int integers[], int size)
{
    if (size == 0) return 0;
    int lastNumber = integers[size - 1];
    int allButLastSum = iterativeArraySum(integers, size - 1);
    return lastNumber + allButLastSum;
}

int arraySumRecursive(int integers[], int size)
{
    if (size == 0) return 0;
    int lastNumber = integers[size - 1];
    int allButLastSum = arraySumRecursive(integers, size - 1);
    return lastNumber + allButLastSum;
}
