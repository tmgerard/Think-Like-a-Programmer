/*
*   Exercise 5-1
*
*   Let's try implementing a class using the basic framework. Consider a class to
*   store the data for an automobile. We'll have three pieces of data: a manufacturer
*   name and model name, both strings, and a model year, an integer. Create a class
*   with get/set methods for each data member. Make sure you make good decisions
*   concerning details like member names. It's not important that you follow my
*   particular naming conventions. What's important is that you think about the
*   choices you make and are consistent in your decisions
*
*   Exercise 5-2
*
*   For our automobile class from the previous exercise, add a support method that
*   returns a complete description of the automobile object as a formatted string,
*   such as, "1957 Chevrolet Impala". Add a second support method that returns
*   the age of the automobile in years.
*/

#include <iostream>
#include "Automobile.h"

int main()
{
    Automobile jeep("Jeep", "Cherokee", 1993);

    jeep.getDescription();

    std::cout << "Car age = " << jeep.getAge() << "." << std::endl;

    return 0;
}
