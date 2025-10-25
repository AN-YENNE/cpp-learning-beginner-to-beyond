// Implements Mystring with safe memory management and both copy and move assignment operators.
// --------------------------------------------------------------
#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
// Creates an empty string "" by allocating one char for the null terminator.
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
    std::cout << "[Ctor] No-args: initialized to empty string." << std::endl;
}

// Overloaded constructor from C-style string
Mystring::Mystring(const char* s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
        std::cout << "[Ctor] From nullptr: initialized to empty string." << std::endl;
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
        std::cout << "[Ctor] From const char*: initialized with '" << str << "'." << std::endl;
    }
}

// Copy constructor (deep copy)
// Allocate new memory and copy characters so each object owns its own buffer.
Mystring::Mystring(const Mystring& source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "[Copy Ctor] Copied from '" << source.str << "'." << std::endl;
}

// Move constructor (transfer ownership)
// Steal the source pointer and set source to nullptr to avoid double delete.
Mystring::Mystring(Mystring&& source)
    : str{source.str} {
    source.str = nullptr;
    std::cout << "[Move Ctor] Took ownership of resource." << std::endl;
}

// Destructor
// Release owned memory (safe to delete[] nullptr).
Mystring::~Mystring() {
    if (str == nullptr) {
        std::cout << "[Dtor] Releasing resource: nullptr (nothing to free)." << std::endl;
    } else {
        std::cout << "[Dtor] Releasing resource for '" << str << "'." << std::endl;
    }
    delete[] str;
}

// Copy assignment operator (deep copy)
Mystring& Mystring::operator=(const Mystring& rhs) {
    std::cout << "[Copy Assign] Assigning from another Mystring." << std::endl;

    // 1) Self-assignment check
    if (this == &rhs) {
        std::cout << "[Copy Assign] Self-assignment detected. No changes applied." << std::endl;
        return *this;
    }

    // 2) Free existing resource
    delete[] str;

    // 3) Allocate new memory and 4) copy
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    std::cout << "[Copy Assign] New value set to '" << str << "'." << std::endl;
    // 5) Return this object by reference
    return *this;
}

// Move assignment operator (transfer ownership)
// Free current resource, take rhs pointer, set rhs pointer to nullptr.
Mystring& Mystring::operator=(Mystring&& rhs) {
    std::cout << "[Move Assign] Transferring ownership from rvalue." << std::endl;

    // 1) Self-assignment check (rare but possible with references)
    if (this == &rhs) {
        std::cout << "[Move Assign] Self-move detected. No changes applied." << std::endl;
        return *this;
    }

    // 2) Free existing resource
    delete[] str;

    // 3) Steal the pointer and 4) null out the source
    str = rhs.str;
    rhs.str = nullptr;

    std::cout << "[Move Assign] Ownership acquired." << std::endl;
    // 5) Return this object by reference
    return *this;
}

// Display the contents and length
void Mystring::display() const {
    std::cout << (str ? str : "(null)") << " : " << get_length() << std::endl;
}

// Return length of the string
int Mystring::get_length() const {
    return (str ? static_cast<int>(std::strlen(str)) : 0);
}

// Return the internal C-string (read-only)
const char* Mystring::get_str() const {
    return str;
}

/*
Notes:
- Copy operations duplicate the characters to a new buffer (deep copy).
- Move operations transfer the pointer without allocating or copying characters,
  which is faster for temporary (rvalue) objects.
- After a move, the source is left in a valid but empty state (nullptr here).
*/
