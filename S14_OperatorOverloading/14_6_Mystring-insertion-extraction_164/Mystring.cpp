// --------------------------------------------------------------
// Implements Mystring and stream operators << and >>
// --------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <string>     // used in operator>> to read into std::string safely
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
    std::cout << "[Ctor] Created empty Mystring \"\"" << std::endl;
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
        std::cout << "[Ctor] Initialized from nullptr as empty string" << std::endl;
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
        std::cout << "[Ctor] Initialized with \"" << str << "\"" << std::endl;
    }
}

// Copy constructor (deep copy)
Mystring::Mystring(const Mystring& source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "[Copy Ctor] Copied from \"" << source.str << "\"" << std::endl;
}

// Move constructor (transfer ownership)
Mystring::Mystring(Mystring&& source)
    : str{source.str} {
    source.str = nullptr;
    std::cout << "[Move Ctor] Took ownership of resource" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    std::cout << "[Dtor] Releasing \"" << (str ? str : "(null)") << "\"" << std::endl;
    delete[] str;
}

// Copy assignment (deep copy)
Mystring& Mystring::operator=(const Mystring& rhs) {
    std::cout << "[Copy Assign] Assigning from \"" << rhs.str << "\"" << std::endl;

    if (this == &rhs) {
        std::cout << "[Copy Assign] Self-assignment detected; no changes" << std::endl;
        return *this;
    }

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    std::cout << "[Copy Assign] New value is \"" << str << "\"" << std::endl;
    return *this;
}

// Move assignment (transfer ownership)
Mystring& Mystring::operator=(Mystring&& rhs) {
    std::cout << "[Move Assign] Taking ownership from temporary" << std::endl;

    if (this == &rhs) {
        std::cout << "[Move Assign] Self-move detected; no changes" << std::endl;
        return *this;
    }

    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;

    std::cout << "[Move Assign] Now holding resource" << std::endl;
    return *this;
}

// Display helper
void Mystring::display() const {
    std::cout << (str ? str : "(null)") << " : " << get_length() << std::endl;
}

// Getters
int Mystring::get_length() const { return (str ? static_cast<int>(std::strlen(str)) : 0); }
const char* Mystring::get_str() const { return str; }

// --------------------------------------------------------------
// Stream insertion operator (friend)
// Allows: std::cout << myString;
// Prints the raw character sequence.
// --------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Mystring& rhs) {
    os << (rhs.str ? rhs.str : "");
    return os;
}

// --------------------------------------------------------------
// Stream extraction operator (friend)
// Allows: std::cin >> myString;
// Reads a single whitespace-delimited token and stores it.
// Implementation detail:
//   We read into a temporary std::string to avoid fixed-size buffers,
//   then assign to rhs by constructing a temporary Mystring.
// --------------------------------------------------------------
std::istream& operator>>(std::istream& in, Mystring& rhs) {
    std::string temp;
    in >> temp;                 // reads until whitespace
    if (!in) return in;         // if input failed, leave rhs unchanged

    rhs = Mystring{temp.c_str()};   // use copy/move assignment to set rhs
    return in;
}