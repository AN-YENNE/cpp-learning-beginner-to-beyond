// --------------------------------------------------------------
// Section 14 - Mystring Class
// Demonstrates how to implement a simple user-defined string class
// that manages dynamic memory safely using constructors, a copy
// constructor, and a destructor.
//
// Key learning objectives:
// 1. How to manage dynamic memory (new[] / delete[]).
// 2. How to implement constructors, copy constructor, and destructor.
// 3. Understanding deep copy vs shallow copy.
// 4. How to encapsulate data with getters and display methods.
//
// Later sections (like operator overloading) will build upon this class.
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str;  // Pointer to dynamically allocated char array (C-style string)

public:
    // Constructors and destructor
    Mystring();                            // No-args constructor
    Mystring(const char *s);               // Overloaded constructor (from C-string)
    Mystring(const Mystring &source);      // Copy constructor (deep copy)
    ~Mystring();                           // Destructor

    // Member functions
    void display() const;                  // Display string and its length
    int get_length() const;                // Return string length
    const char *get_str() const;           // Return pointer to internal C-string
};

#endif // _MYSTRING_H_
