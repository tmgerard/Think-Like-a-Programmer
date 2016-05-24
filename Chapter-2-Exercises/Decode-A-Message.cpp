/*
*   Problem: Decode a Message
*
*   A message has been encoded as a text stream that is read character by
*   character. The stream contains a series of comma-delimited integers, each
*   a positive number capable of being represented by a C++ int. However, the
*   character represented by a particular integer depends on the current
*   decoding mode. There are three modes: uppercase, lowercase, and
*   punctuation.
*
*   In uppercase mode, each integer represents an uppercase letter: The
*   integer modulo 27 indicates the letter of the alphabet (where 1 = A
*   and so on). So an input value of 143 in uppercase mode would yeild the
*   letter H because 143 modulo 27 is 8 and H is the eighth letter in the
*   alphabet.
*
*   The lowercase mode works the same but with lowercase lettters; the
*   remainder of dividing the integer by 27 represents the lowercase letter
*   (1 = a and so on). So an input value of 56 in lowercase mode would yeild
*   the letter b because 57 modulo 27 is 2 and b is the second letter in the
*   alphabet.
*
*   In punctuation mode, the integer is instead considered a modulo 9, with
*   the interpretation given by Table 2-3 below. So 19 would yeild an
*   exclamation point because 19 modulo 9 is 1.
*
*   At the beginning of each message, the decoding mode is uppercase letters.
*   Each time a modulo operation (by 27 or 9, depending on the mode) results
*   in 0, the decoding mode switches. If the current mode is uppercase, the
*   mode switches to lowercase letters. If the current mode is lowercase, the
*   mode switches to punctuations, and if it is punctuation, it switches back
*   to uppercase.
*
*   Table 2-3: Punctuation Decoding Mode
*   Number      Symbol
*   1           !
*   2           ?
*   3           ,
*   4           .
*   5           (space)
*   6           ;
*   7           "
*   8           '
*/

#include <iostream>

int main()
{
    char outputCharacter;
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
    modeType mode = UPPERCASE;
    char digitChar;
    do
    {
        digitChar = std::cin.get();
        int number = (digitChar - '0');
        digitChar = std::cin.get();
        while((digitChar != 10) && (digitChar != ','))
        {
            number = number * 10 + (digitChar - '0');
            digitChar = std::cin.get();
        }
        switch(mode)
        {
        case UPPERCASE:
            number = number % 27;
            outputCharacter = number + 'A' - 1;
            if (number == 0)
            {
                mode = LOWERCASE;
                continue;
            }
            break;
        case LOWERCASE:
            number = number % 27;
            outputCharacter = number + 'a' - 1;
            if (number == 0)
            {
                mode = PUNCTUATION;
                continue;
            }
            break;
        case PUNCTUATION:
            number = number % 9;
            switch(number)
            {
                case 1: outputCharacter = '!'; break;
                case 2: outputCharacter = '?'; break;
                case 3: outputCharacter = ','; break;
                case 4: outputCharacter = '.'; break;
                case 5: outputCharacter = ' '; break;
                case 6: outputCharacter = ';'; break;
                case 7: outputCharacter = '"'; break;
                case 8: outputCharacter = '\''; break;
            }
            if (number == 0)
            {
                mode = UPPERCASE;
                continue;
            }
            break;
        }
        std::cout << outputCharacter;
    } while(digitChar != 10);
    std::cout << '\n';
}
