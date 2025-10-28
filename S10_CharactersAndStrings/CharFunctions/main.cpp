// Section 10
// Character Classification and Conversion using <cctype>
//
// This program demonstrates the use of character-based functions
// from the C++ standard library header <cctype>.
//
// These functions allow you to test and convert individual characters,
// which is helpful when parsing or processing text input.

#include <iostream>
#include <cctype>  // for isalpha, isdigit, isspace, ispunct, toupper, etc.

using namespace std;

int main() {

    // A sample mixed-character string to analyze
    char str[] {"1234'5sddd'fdffg\n\t&^%23**~Frank Mary~     @!()-+=%^?<>;:"};

    int num_letters {};
    int num_digits {};
    int num_whitespace {};
    int num_punctuation {};
    int num_others {};

    // Loop through each character and categorize
    for (char c : str) {
        if (isalpha(c))
            num_letters++;
        else if (isdigit(c))
            num_digits++;
        else if (isspace(c))
            num_whitespace++;
        else if (ispunct(c))
            num_punctuation++;
        else
            num_others++;
    }

    // Display categorized counts
    cout << "Character Type Counts" << endl;
    cout << "----------------------" << endl;
    cout << "Letters      : " << num_letters << endl;
    cout << "Digits       : " << num_digits << endl;
    cout << "Whitespace   : " << num_whitespace << endl;
    cout << "Punctuation  : " << num_punctuation << endl;
    cout << "Others       : " << num_others << endl;

    cout << "\n----------------------------------------" << endl;
    cout << "Character Case Conversion Example" << endl;
    cout << "----------------------------------------" << endl;

    // Another example: converting characters to uppercase
    char str1[] {"This is a test - 1 2 3"};
    cout << "Original: " << str1 << endl;
    cout << "Uppercase: ";

    for (char c : str1) {
        cout << static_cast<char>(toupper(c));  // convert each char to uppercase
    }

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES, TIPS, AND SUMMARY
=====================================================================

1) Overview:
------------
The <cctype> header provides functions for character classification
and transformation. These functions are particularly useful for analyzing
or sanitizing text data.

Common examples:
- Counting letters, digits, or spaces.
- Converting lowercase to uppercase or vice versa.
- Ignoring non-printable or punctuation characters when parsing.

---------------------------------------------------------------------

2) Common Functions from <cctype>:
----------------------------------
Function           | Purpose
-------------------|-----------------------------------------------
isalpha(c)         | Checks if c is a letter (A-Z or a-z)
isdigit(c)         | Checks if c is a digit (0-9)
isspace(c)         | Checks for whitespace (space, tab, newline, etc.)
ispunct(c)         | Checks for punctuation (!, ., @, #, etc.)
isalnum(c)         | Checks if c is alphanumeric (letter or digit)
isupper(c)         | Checks if c is uppercase
islower(c)         | Checks if c is lowercase
toupper(c)         | Converts character to uppercase
tolower(c)         | Converts character to lowercase

---------------------------------------------------------------------

3) Example Explanation:
------------------------
Input string:
"1234'5sddd'fdffg\n\t&^%23**~Frank Mary~     @!()-+=%^?<>;:"

The program:
- Loops over each character.
- Uses `isalpha`, `isdigit`, etc., to count character types.
- Then prints totals for each category.

Sample Output:
Letters      : 9
Digits       : 6
Whitespace   : 6
Punctuation  : 14
Others       : 2

---------------------------------------------------------------------

4) toupper() and tolower():
---------------------------
- Used for case conversion.
- Requires `static_cast<char>()` to convert the `int` result back to char.
- Safe for alphabetic characters; behavior is undefined for non-printable values.

Example:
```cpp
char c = 'a';
cout << toupper(c);   // prints 'A'

Practical Use Cases:

-Input sanitization: reject invalid characters.
-Text analytics: counting occurrences of letters or punctuation.
-Building tokenizers and parsers.
-Transforming text (e.g., case-insensitive comparisons).

Key Tips:

Always cast toupper/tolower results back to char.

Avoid using these functions with EOF or non-ASCII data unless localized.

Prefer using std::string and range-based loops for clarity.

Summary:

The <cctype> library provides simple, efficient tools for character-level analysis.

Combined with loops, it helps you understand and manipulate text data at a low level.

Great for early learning, input validation, and understanding how C++ handles characters.
*/