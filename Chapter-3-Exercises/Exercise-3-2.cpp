/*
*   Exercise 3-2
*
*   Rewrite the code that finds the agent with the best monthly sales average
*   so that it finds the agent with the highest median sales. As stated
*   earlier, the median of a set of values is the "one in the middle," such
*   that half of the other values are higher and half of the other values are
*   lower. If there is an even number of values, the median is the simple
*   average of the two values in the middle. For example, in the set
*   10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9. The average of
*   7 and 9 is 8, so 8 is the median.
*/

#include<iostream>
#include<stdlib.h>

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

// compare function for qsort
int compare(const void* A, const void* B);

// calculate average of values in array
double arrayAverage(int intArray[], int ARRAY_SIZE);

// calculate median of array
double arrayMedian(int intArray[], int ARRAY_SIZE);

// output the contents of a multidimensional array to the console window
template<typename T, int ROWS, int COLUMNS>
void printMultArray(T(&theArray)[ROWS][COLUMNS]);

int main()
{

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    std::cout << "Raw sales array\n";
    printMultArray(sales);

    // find highest average value calculated from the agent arrays
    double highestAverage = arrayAverage(sales[0], 12);
    for (int agent = 1; agent < NUM_AGENTS; agent++)
    {
        double agentAverage = arrayAverage(sales[agent], 12);
        if (agentAverage > highestAverage)
        {
            highestAverage = agentAverage;
        }
    }

    std::cout << "\nHighest monthly average: " << highestAverage << '\n';

    // sort each agent array
    for (int agent = 0; agent < NUM_AGENTS; agent++)
    {
        qsort(sales[agent], NUM_MONTHS, sizeof(int), compare);
    }

    std::cout << '\n';
    std::cout << "Sorted Sales Array\n";

    printMultArray(sales);

    double highestMedian = arrayMedian(sales[0], 12);
    for (int agent = 1; agent < NUM_AGENTS; agent++)
    {
        double agentMedian = arrayMedian(sales[agent], 12);
        if (agentMedian > highestMedian)
        {
            highestMedian = agentMedian;
        }
    }

    std::cout << "\nHighest monthly median sales: " << highestMedian << '\n';

    return 0;
}

// compare function for qsort
int compare(const void* A, const void* B)
{
    int* pA = (int*) A;
    int* pB = (int*) B;
    return *pA - *pB;
}

// calculate average of values in array
double arrayAverage(int intArray[], int ARRAY_SIZE)
{
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += intArray[i];
    }
    double average = sum / ARRAY_SIZE;
    return average;
}

// calculate median of array
double arrayMedian(int intArray[], int ARRAY_SIZE)
{
    if (ARRAY_SIZE % 2 == 0)
    {
        int indexOne = ARRAY_SIZE / 2;
        int indexTwo = indexOne + 1;

        return (intArray[indexOne - 1] + intArray[indexTwo - 1]) / 2.0;
    }

    int index = (ARRAY_SIZE / 2) + 1;
    return intArray[index - 1];
}

// output the contents of a multidimensional array to the console window
template<typename T, int ROWS, int COLUMNS>
void printMultArray(T (&theArray)[ROWS][COLUMNS])
{
    for (int agent = 0; agent < ROWS; agent++)
    {
        std::cout << "Agent " << agent + 1 << ": ";
        for (int month = 0; month < COLUMNS; month++)
        {
            std::cout << theArray[agent][month] << ' ';
        }
        std::cout << '\n';
    }
}

