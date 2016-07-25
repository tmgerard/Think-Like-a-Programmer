/*
*   Exercise 6.1
*
*   Write a function to compute the sum of just the positive numbers in an array
*   of integers. First, solve the problem using iteration. Then, using the tecnique
*   shown in this chapter, convert your iterative function to a recursive function.
*/

#include <iostream>

int IterativePositiveSum(int numArray[], int arraySize);
int RecursivePositiveSum(int numArray[], int arraySize);

int main()
{
    int numbers[] = {1, -1, 1, -1, 1, 1, -1};

    std::cout << "Iterative Sum = " << IterativePositiveSum(numbers, 7) << std::endl;

    std::cout << "Recursive Sum = " << RecursivePositiveSum(numbers, 7) << std::endl;

    return 0;
}

int IterativePositiveSum(int numArray[], int arraySize)
{
    int result = 0;
    for(int i = 0; i < arraySize; i++)
    {
        if (numArray[i] > 0)
        {
            result += numArray[i];
        }
    }
    return result;
}

int RecursivePositiveSum(int numArray[], int arraySize)
{
    if (arraySize == 0) return 0;
    int lastNum = 0;
    if (numArray[arraySize - 1] > 0) lastNum = numArray[arraySize - 1];
    int allButLastSum = RecursivePositiveSum(numArray, arraySize - 1);
    return lastNum + allButLastSum;
}
