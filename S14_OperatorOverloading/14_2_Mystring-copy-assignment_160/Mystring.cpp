// File2: Mystring.cpp
// --------------------------------------------------------------
// Implements constructors, destructor, and copy assignment operator.
// Demonstrates correct deep copy logic to handle dynamically allocated memory.
// --------------------------------------------------------------
#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
    std::cout << "No-args constructor called: created empty string." << std::endl;
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
        std::cout << "Overloaded constructor called: initialized empty string (nullptr input)." << std::endl;
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
        std::cout << "Overloaded constructor called: initialized with value '" << str << "'." << std::endl;
    }
}

// Copy constructor (deep copy)
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor called: copied from '" << source.str << "'." << std::endl;
}

// Destructor
Mystring::~Mystring() {
    std::cout << "Destructor called: freeing memory for '" << str << "'." << std::endl;
    delete[] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment operator called." << std::endl;

    // Step 1: Check for self-assignment
    if (this == &rhs) {
        std::cout << "Self-assignment detected; no action taken." << std::endl;
        return *this;
    }

    // Step 2: Deallocate old memory
    delete[] this->str;

    // Step 3: Allocate new memory
    str = new char[std::strlen(rhs.str) + 1];

    // Step 4: Copy data from the right-hand-side object
    std::strcpy(this->str, rhs.str);

    std::cout << "Assigned new value: '" << this->str << "'." << std::endl;

    // Step 5: Return current object by reference
    return *this;
}

// Display string and length
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// Getter for string length
int Mystring::get_length() const {
    return std::strlen(str);
}

// Getter for internal C-style string
const char *Mystring::get_str() const {
    return str;
}

/*
Summary Notes:
1. The overloaded copy assignment operator is crucial for classes managing
   resources like dynamic memory.

2. The steps for implementing deep copy assignment:
   a. Check for self-assignment:
      if (this == &rhs) return *this;
   b. Deallocate existing memory using delete[].
   c. Allocate new memory for the deep copy.
   d. Copy the string data with strcpy.
   e. Return *this (by reference) to enable chain assignment.

3. Returning *this allows expressions like:
      obj1 = obj2 = obj3;
   which executes right-to-left assignment chaining.

4. Always implement deep copy when your class has a raw pointer that owns memory.
*/
