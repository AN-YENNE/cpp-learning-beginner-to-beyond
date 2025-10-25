// --------------------------------------------------------------
// Implements constructors, destructors, and operator overloads
// for Mystring class.
//
// Demonstrates how overloaded operators allow custom behavior
// for objects using natural syntax (e.g., +, -, ==).
// --------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <cctype>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring& source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "[Copy Ctor] Copied from '" << source.str << "'." << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring&& source)
    : str(source.str) {
    source.str = nullptr;
    std::cout << "[Move Ctor] Resource moved." << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

// Copy assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
    std::cout << "[Copy Assign] Copying from '" << rhs.str << "'." << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
    std::cout << "[Move Assign] Moving from temporary." << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Equality operator (==)
// Returns true if two Mystring objects have identical character sequences.
bool Mystring::operator==(const Mystring& rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Unary minus operator (-)
// Creates a lowercase copy of the current string.
Mystring Mystring::operator-() const {
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Binary plus operator (+)
// Concatenates this string with rhs and returns a new Mystring object.
Mystring Mystring::operator+(const Mystring& rhs) const {
    char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Display
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// Get string length
int Mystring::get_length() const {
    return std::strlen(str);
}

// Get internal C-string
const char* Mystring::get_str() const {
    return str;
}

/*
Summary Notes:
1. Operator== compares two Mystring objects for equality.
2. Operator- (unary) creates a lowercase version of the string.
3. Operator+ (binary) concatenates two Mystring objects into a new one.
4. Operators return new temporary objects so expressions can be chained.
5. Always deallocate temporary buffers to prevent memory leaks.
*/
