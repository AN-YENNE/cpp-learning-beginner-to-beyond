
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include "Mystring.h"

// No-args constructor
// Create empty string "" with a single null terminator
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
// Initialize from C string argument; treat nullptr as empty
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

// Copy constructor (deep copy)
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move constructor (steal pointer, null out source)
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
    source.str = nullptr;
}

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

// Copy assignment (deep copy)
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment (transfer ownership)
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display helper
void Mystring::display() const {
    std::cout << (str ? str : "(null)") << " : " << get_length() << std::endl;
}

// Getters
int Mystring::get_length() const { return str ? static_cast<int>(std::strlen(str)) : 0; }
const char *Mystring::get_str() const { return str; }

// Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << (rhs.str ? rhs.str : "");
    return os;
}

// Stream extraction operator
// Reads one whitespace-delimited token
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    std::string temp;
    in >> temp;
    if (!in) return in;
    rhs = Mystring{temp.c_str()};
    return in;
}

// ===== Operator overloads (member methods) =====

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return std::strcmp(str, rhs.str) == 0;
}

// Inequality
bool Mystring::operator!=(const Mystring &rhs) const {
    return !(*this == rhs);
}

// Lexical less-than
bool Mystring::operator<(const Mystring &rhs) const {
    return std::strcmp(str, rhs.str) < 0;
}

// Lexical greater-than
bool Mystring::operator>(const Mystring &rhs) const {
    return std::strcmp(str, rhs.str) > 0;
}

// Unary minus: lowercase copy
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(buff[i])));
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenation
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concat-assign
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs; // reuse operator+
    return *this;
}

// Repeat n times
Mystring Mystring::operator*(int n) const {
    // Simple loop-based approach that reuses operator+
    Mystring temp;
    for (int i = 1; i <= n; i++)
        temp = temp + *this;
    return temp;

    // Alternative (more efficient) approach is commented in earlier examples
}

// Repeat-assign
Mystring &Mystring::operator*=(int n) {
    *this = *this * n; // reuse operator*
    return *this;
}

// Pre-increment: make uppercase in place, return updated object
Mystring &Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
    return *this;
}

// Post-increment: return old value, but make current uppercase
Mystring Mystring::operator++(int) {
    Mystring temp(*this); // copy old value
    operator++();         // reuse pre-increment
    return temp;          // return old value
}
