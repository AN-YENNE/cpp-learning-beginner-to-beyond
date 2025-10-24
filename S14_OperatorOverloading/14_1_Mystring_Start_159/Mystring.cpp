// Implements all member functions of Mystring.
// Demonstrates safe handling of dynamically allocated memory
// and the importance of deep copying when copying objects that own resources.
#include <cstring>   // for strlen, strcpy
#include <iostream>
#include "Mystring.h"

// No-args constructor: Creates an empty string ("") by allocating space for '\0'
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor: Initializes the Mystring with a provided C-style string.
Mystring::Mystring(const char *s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor (deep copy): Allocates new memory and copies the string content.
// This ensures each Mystring object has its own independent data.
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Destructor: Releases the dynamically allocated memory to prevent memory leaks.
Mystring::~Mystring() {
    delete[] str;
}

// Display the string and its length
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// Return the string length using strlen
int Mystring::get_length() const {
    return std::strlen(str);
}

// Return the internal C-string pointer (read-only)
const char *Mystring::get_str() const {
    return str;
}

/*
Summary Notes:
1. Memory Management:
   - The class dynamically allocates memory for a C-style string.
   - Destructor ensures memory is freed properly.

2. Deep Copy vs Shallow Copy:
   - Deep copy: creates a new memory block and copies data.
   - Shallow copy: copies only the pointer (dangerous, leads to double deletion).

3. Constructor chain:
   - Default constructor → sets up an empty string.
   - Overloaded constructor → initializes from provided char*.
   - Copy constructor → performs deep copy from another Mystring.

4. Good practice:
   - Always initialize pointers to nullptr.
   - Always release dynamic memory in the destructor.
   - Provide a copy constructor when your class owns a resource.

5. This class is the foundation for learning operator overloading,
   which allows objects to behave more like built-in types.
*/