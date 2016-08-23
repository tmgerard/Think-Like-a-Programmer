/*
*   Exercise 3-4
*
*   Here's a variation on the array of const values. Write a program for
*   creating a substitution cipher problem. In a substitution cipher problem,
*   all messages are made of uppercase letters and punctuation. The original
*   message is called the plaintext, and you create the ciphertext by
*   substituting each letter with another letter (for example, each C could
*   become an X). For this problem, hard-code a cons array of 26 char elements
*   for the cipher, and have your program read a plaintext message and output
*   the equivalent ciphertext.
*/

#include <iostream>
#include <string>
#include <locale>

std::string encode(std::string plaintext, const char cipher[]);

int main()
{

    const char cipher[26] = {'B', 'C', 'M', 'E', 'F', 'G', 'H', 'S', 'J',
                             'K', 'L', 'D', 'N', 'O', 'W', 'Q', 'R', 'I',
                             'Z', 'U', 'V', 'Q' , 'X', 'Y', 'T', 'A'};

    std::string plaintext = "This is just a test.";

    std::string ciphertext = encode(plaintext, cipher);

    std::cout << ciphertext;

    return 0;
}

std::string encode(std::string plaintext, const char cipher[])
{
    // convert string to uppercase and encode message
    std::locale loc;
    for (std::string::size_type i = 0; i < plaintext.length(); ++i)
    {
        plaintext[i] = std::toupper(plaintext[i], loc);

        if ((plaintext[i] > 64) && (plaintext[i] < 96))
        {
            plaintext[i] = cipher[plaintext[i] - 65];
        }
    }

    return plaintext;
}
