// Section 10
// std::string Basics and Common Operations
//
// This example shows how to use C++ std::string safely and idiomatically.
// It demonstrates initialization, comparison, assignment, concatenation,
// indexing, iteration, substrings, erase, getline, and find.
//
// Tip: Prefer std::string over C-style strings unless you have a specific reason.
// It manages memory automatically and comes with many convenient member functions.

#include <iostream>
#include <iomanip>
#include <string>   // required for std::string

using namespace std;    // or use std::string, std::cout, etc.

int main() {

    // 1) Safe default construction and a few other forms
    string s0;                 // empty string, prints nothing, length() is 0
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};       // same letters as s1 but different case
    string s5 {s1};            // copy of s1 -> "Apple"
    string s6 {s1, 0, 3};      // substring ctor: "App" (start at 0, length 3)
    string s7 (10, 'X');       // repeated char ctor: "XXXXXXXXXX"

    cout << "s0 prints as: [" << s0 << "]" << endl;
    cout << "s0 length is: " << s0.length() << endl;

    // 2) Initialization showcase
    cout << "\nInitialization ---------------------------------------" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5 (copy of s1): " << s5 << endl;
    cout << "s6 (substring of s1): " << s6 << endl;
    cout << "s7 (10 'X'): " << s7 << endl;

    // 3) Comparison operators (lexicographical, case-sensitive)
    cout << "\nComparison --------------------------------------------" << endl;
    cout << boolalpha;
    cout << s1  << " == " << s5 << " ? " << (s1 == s5) << endl;
    cout << s1  << " == " << s2 << " ? " << (s1 == s2) << endl;
    cout << s1  << " != " << s2 << " ? " << (s1 != s2) << endl;
    cout << s1  << " <  " << s2 << " ? " << (s1 <  s2) << endl;
    cout << s2  << " >  " << s1 << " ? " << (s2 >  s1) << endl;
    cout << s4  << " <  " << s5 << " ? " << (s4 <  s5) << "  (lowercase vs uppercase)" << endl;
    cout << s1  << " == " << "Apple" << " ? " << (s1 == "Apple") << endl;

    // 4) Assignment and element access
    cout << "\nAssignment and Indexing -------------------------------" << endl;
    s1 = "Watermelon";
    cout << "s1 is now: " << s1 << endl;

    s2 = s1;
    cout << "s2 is now a copy of s1: " << s2 << endl;

    s3 = "Sample";
    cout << "s3 is now: " << s3 << endl;

    // Indexing with operator[] does not do bounds checking
    s3[0] = 'C';
    cout << "s3 after s3[0] = 'C': " << s3 << endl;

    // at() performs bounds checking and may throw on invalid index
    s3.at(0) = 'P';
    cout << "s3 after s3.at(0) = 'P': " << s3 << endl;

    // 5) Concatenation
    cout << "\nConcatenation -----------------------------------------" << endl;
    s3 = "Watermelon";
    s3 = s5 + " and " + s2 + " smoothie"; // "Apple and Watermelon smoothie"
    cout << "Concatenated s3: " << s3 << endl;

    // 6) Looping over characters
    cout << "\nLooping ------------------------------------------------" << endl;
    s1 = "Apple";
    cout << "Index-based loop over \"" << s1 << "\": ";
    for (size_t i {0}; i < s1.length(); ++i)
        cout << s1.at(i);
    cout << endl;

    cout << "Range-based loop over \"" << s1 << "\": ";
    for (char c : s1)
        cout << c;
    cout << endl;

    // 7) Substring
    cout << "\nSubstring ---------------------------------------------" << endl;
    s1 = "This is a test";
    cout << "s1:               " << s1 << endl;
    cout << "s1.substr(0, 4):  " << s1.substr(0, 4) << endl;   // "This"
    cout << "s1.substr(5, 2):  " << s1.substr(5, 2) << endl;   // "is"
    cout << "s1.substr(10, 4): " << s1.substr(10, 4) << endl;  // "test"

    // 8) Erase
    cout << "\nErase -------------------------------------------------" << endl;
    s1 = "This is a test";
    s1.erase(0, 5); // remove "This " (5 chars), results in "is a test"
    cout << "After erase(0, 5): " << s1 << endl;

    // 9) getline to read a full line including spaces
    cout << "\ngetline -----------------------------------------------" << endl;
    string full_name {};
    cout << "Enter your full name: ";
    getline(cin, full_name);   // reads the pending newline if any; if this line is skipped,
                               // insert an extra getline(cin, full_name); after cin.ignore().
    cout << "You entered: " << full_name << endl;

    // 10) find
    cout << "\nfind --------------------------------------------------" << endl;
    string sentence {"The secret word is Breeze"};
    string word {};
    cout << "Enter a word to search for in: \"" << sentence << "\": ";
    cin >> word;

    size_t pos = sentence.find(word);
    if (pos != string::npos)
        cout << "Found \"" << word << "\" at position " << pos << " (0-based index)." << endl;
    else
        cout << "Sorry, \"" << word << "\" was not found." << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES, TIPS, AND SUMMARY
=====================================================================

1) Why std::string
   - Manages memory automatically.
   - Safer and more convenient than C-style strings.
   - Rich set of member functions: size/length, substr, find, erase, insert, replace, etc.

2) Construction Patterns
   - string a;                         // empty
   - string b {"Text"};                // from literal
   - string c {b};                     // copy
   - string d {b, start_index, count}; // substring constructor
   - string e (n, 'X');                // n copies of a character

3) Comparison
   - Uses lexicographical (dictionary) order and is case-sensitive.
   - "apple" < "Banana" can be false because lowercase letters compare greater than uppercase.

4) Indexing vs at()
   - s[i] does not check bounds and can be undefined if i is invalid.
   - s.at(i) checks bounds and may throw an exception on invalid index.

5) Concatenation
   - Use + or +=, for example:
     s = a + " and " + b;
   - Concatenation of two string literals like "a" + "b" does not compile (both are const char[]).
     One side must be a std::string.

6) Substring and Erase
   - substr(pos, count) returns a new string.
   - erase(pos, count) modifies in place by removing a segment.

7) getline
   - getline(cin, s) reads a full line including spaces until newline.
   - If mixing with operator>> on cin, handle the leftover newline with cin.ignore() when necessary.

8) find
   - find returns the index where the substring starts, or string::npos if not found.

9) Performance Tips
   - Reserve capacity if you know the approximate size: s.reserve(n).
   - Prefer references and move semantics for large strings when performance matters.

10) Summary
   - std::string is the go-to string type in C++.
   - Provides safety, readability, and rich functionality.
   - Practice common operations to be productive: compare, append, iterate, slice, erase, find.
=====================================================================
*/
