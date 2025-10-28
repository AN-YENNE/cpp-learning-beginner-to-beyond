// Section 10 Working with C-Style Strings
//
// This example demonstrates how to work with traditional C-style strings
// in C++. These are character arrays terminated by a null character '\0'.
// You will see examples of reading strings, concatenating them,
// comparing them, and converting character cases using functions
// from <cstring> and <cctype>.

#include <iostream>
#include <cstring>   // for C-style string functions like strcpy, strcat, strlen, strcmp
#include <cctype>    // for character-based functions like toupper, isalpha

using namespace std;

int main() {
    // Character arrays for names
    char first_name[20];
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

    // Demonstrating uninitialized memory — may print garbage
    cout << "Initial value of first_name (uninitialized): " << first_name << endl;

    // ----------------------------------------------------------------
    // 1) Input first and last names separately
    // ----------------------------------------------------------------
//    cout << "Please enter your first name: ";
//    cin >> first_name;
//
//    cout << "Please enter your last name: ";
//    cin >> last_name;
//    cout << "------------------------------------" << endl;
//
//    cout << "Hello, " << first_name << "! Your first name has " << strlen(first_name) << " characters." << endl;
//    cout << "Your last name, " << last_name << ", has " << strlen(last_name) << " characters." << endl;
//
//    // Build full_name using strcpy() and strcat()
//    strcpy(full_name, first_name);     // copy first_name into full_name
//    strcat(full_name, " ");            // add a space
//    strcat(full_name, last_name);      // append last_name
//
//    cout << "Your full name is: " << full_name << endl;

    // ----------------------------------------------------------------
    // 2) Demonstrating input issues with cin vs getline()
    // ----------------------------------------------------------------
//    cout << "------------------------------------" << endl;
//    cout << "Enter your full name: ";
//    cin >> full_name;  // reads only until first space
//    cout << "Your full name (cin >>): " << full_name << endl;
//
//    cout << "\nEnter your full name again (using getline): ";
//    cin.getline(full_name, 50);  // reads full line including spaces
//    cout << "Your full name (getline): " << full_name << endl;

    // ----------------------------------------------------------------
    // 3) Copying and comparing strings
    // ----------------------------------------------------------------
//    cout << "------------------------------------" << endl;
//    strcpy(temp, full_name);
//    if (strcmp(temp, full_name) == 0)
//        cout << temp << " and " << full_name << " are identical." << endl;
//    else
//        cout << temp << " and " << full_name << " are different." << endl;

    // ----------------------------------------------------------------
    // 4) Converting to uppercase
    // ----------------------------------------------------------------
//    cout << "------------------------------------" << endl;
//    for (size_t i{0}; i < strlen(full_name); ++i) {
//        if (isalpha(full_name[i]))   // convert only alphabetic characters
//            full_name[i] = toupper(full_name[i]);
//    }
//    cout << "Your name in uppercase: " << full_name << endl;

    // ----------------------------------------------------------------
    // 5) Comparing again after case conversion
    // ----------------------------------------------------------------
//    cout << "------------------------------------" << endl;
//    if (strcmp(temp, full_name) == 0)
//        cout << temp << " and " << full_name << " are identical." << endl;
//    else
//        cout << temp << " and " << full_name << " are different." << endl;
//
//    cout << "Comparison result (temp vs full_name): " << strcmp(temp, full_name) << endl;
//    cout << "Comparison result (full_name vs temp): " << strcmp(full_name, temp) << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON C-STYLE STRINGS
=====================================================================

1. Overview:
------------
C-style strings are character arrays terminated by the null character '\0'.
For example:
    char name[] = "Alex";  // occupies 5 bytes: 'A', 'l', 'e', 'x', '\0'

C++ provides safer and more flexible alternatives (std::string), but
understanding C-style strings is useful for working with legacy code.

---------------------------------------------------------------------

2. Common <cstring> Functions:
------------------------------
strlen(str)      → Returns the number of characters (excluding '\0').
strcpy(dest, src) → Copies src into dest.
strcat(dest, src) → Appends src to dest.
strcmp(s1, s2)   → Compares two strings lexicographically:
                     returns 0 if equal, <0 if s1 < s2, >0 if s1 > s2.

---------------------------------------------------------------------

3. Common <cctype> Functions:
------------------------------
isalpha(ch)  → Checks if ch is alphabetic.
isdigit(ch)  → Checks if ch is a digit.
toupper(ch)  → Converts ch to uppercase.
tolower(ch)  → Converts ch to lowercase.

---------------------------------------------------------------------

4. Input Considerations:
------------------------
- `cin >> str` stops reading at the first whitespace.
- `cin.getline(str, size)` reads an entire line including spaces.

Example:
    cin >> name;
    // Input: "John Doe"
    // Result: name = "John"

    cin.getline(name, 50);
    // Input: "John Doe"
    // Result: name = "John Doe"

---------------------------------------------------------------------

5. Memory Safety Tips:
----------------------
✔ Always ensure destination arrays are large enough before using strcpy or strcat.  
✔ Uninitialized char arrays may contain garbage data.  
✔ Use `'\0'` termination to prevent buffer overflow issues.  
✔ Consider using `std::string` in modern C++ instead of char arrays.

---------------------------------------------------------------------

6. Example Exercises:
---------------------
- Modify the program to compare two user-entered names.
- Count vowels in a C-style string.
- Reverse the characters in a string manually.

---------------------------------------------------------------------

7. Summary:
-----------
- C-style strings require manual management of memory and termination.
- Useful for lower-level operations and compatibility.
- Prefer `std::string` for modern applications to avoid common pitfalls.

=====================================================================
*/