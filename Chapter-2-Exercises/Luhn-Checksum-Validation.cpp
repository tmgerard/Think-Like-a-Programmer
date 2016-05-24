/*
*   Problem: Luhn Checksum Validation
*
*   The Luhn formula is a widely used system for validating identification
*   numbers. Using the original number, double the value of every other digit.
*   Then add the values of the individual digits together (if a doubled value
*   now has two digits, add the digits individually). The Identification number
*   is valid if the sum is divisible by 10.
*
*   Write a program that takes an identification number of arbitrary length and
*   determines wheter the number is valid under the Luhn formula. The program
*   must process each character before reading the next one.
*/

#include <iostream>

int doubleDigitValue(int digit);

int main()
{
    char digit;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;

    std::cout << "Enter a number: ";
    digit = std::cin.get();

    while(digit != 10)
    {

        if(position % 2 == 0)
        {
            oddLengthChecksum += doubleDigitValue(digit - '0');
            evenLengthChecksum += digit - '0';
        }
        else
        {
            oddLengthChecksum += digit - '0';
            evenLengthChecksum += doubleDigitValue(digit - '0');
        }
        std::cout << digit << " " << evenLengthChecksum << " " << oddLengthChecksum << '\n';
        digit = std::cin.get();
        position++;
    }

    int checksum;
    if ((position - 1) % 2 == 0)
    {
        checksum = evenLengthChecksum;
    }
    else
    {
        checksum = oddLengthChecksum;
    }

    std::cout << "Checksum is " << checksum << ".\n";

    if(checksum % 10 == 0)
    {
        std::cout << "Checksum is divisible by 10. Valid.\n";
    }
    else
    {
        std::cout << "Checksum is not divisible by 10. Invalid.\n";
    }

    return 0;
}

int doubleDigitValue(int digit)
{
    int doubledDigit = digit * 2;
    int sum;
    if (doubledDigit >= 10) sum = 1 + doubledDigit % 10;
    else sum = doubledDigit;
    return sum;
}
