// --------------------------------------------------------------
// Implements Mystring and the FRIEND operator overloads.
// Logs use meaningful messages to help you trace object behavior.
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
    std::cout << "[Ctor] Created empty Mystring \"\"" << std::endl;
}

// Overloaded constructor (from const char*)
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

// Move constructor (steal pointer, null out source)
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

    delete[] str; // free old
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

    delete[] str;   // free current
    str = rhs.str;  // steal pointer
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


// ======================= FRIEND OPERATORS =======================

// Equality (non-member)
// Compare character sequences of lhs and rhs
bool operator==(const Mystring& lhs, const Mystring& rhs) {
    return std::strcmp(lhs.str, rhs.str) == 0;
}

// Unary minus (non-member) -> lowercase copy
Mystring operator-(const Mystring& obj) {
    char* buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);

    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(buff[i])));

    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenation (non-member)
// Returns a new Mystring that is lhs + rhs
Mystring operator+(const Mystring& lhs, const Mystring& rhs) {
    char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    Mystring temp{buff};
    delete[] buff;
    return temp;
}

/*
Notes:
- Because these operators are non-members, implicit conversions can occur
  on BOTH operands using the Mystring(const char*) constructor. For example:
      Mystring s{"Beta"};
      auto t = "Alpha" + s;   // OK: "Alpha" becomes Mystring via ctor, then operator+ runs
- If these were member functions, only the right-hand operand could convert implicitly.
*/
