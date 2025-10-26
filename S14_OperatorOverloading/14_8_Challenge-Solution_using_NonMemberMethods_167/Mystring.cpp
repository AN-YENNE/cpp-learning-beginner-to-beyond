// Implements Mystring and all non-member friend operators.
// Messages are generic and illustrative for learning purposes.
// --------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>   // used to make operator>> safer
#include "Mystring.h"

// ===== Core special member functions =====

// No-args constructor: create empty string ""
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor: initialize from C string (treat nullptr as empty)
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

// Copy constructor: deep copy
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move constructor: steal pointer and null out source
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
    source.str = nullptr;
}

// Destructor: release owned memory
Mystring::~Mystring() {
    delete[] str;
}

// Copy assignment: deep copy
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs)
        return *this;

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment: transfer ownership
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs)
        return *this;

    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// ===== Utilities =====

void Mystring::display() const {
    std::cout << (str ? str : "(null)") << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {
    return str ? static_cast<int>(std::strlen(str)) : 0;
}

const char *Mystring::get_str() const {
    return str;
}

// ===== Stream operators (friends) =====

std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << (rhs.str ? rhs.str : "");
    return os;
}

std::istream &operator>>(std::istream &in, Mystring &rhs) {
    // Read a whitespace-delimited token safely using std::string
    std::string temp;
    in >> temp;
    if (!in) return in;        // input failed; leave rhs unchanged
    rhs = Mystring{temp.c_str()};
    return in;
}

// ===== Comparison operators (friends) =====

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return std::strcmp(lhs.str, rhs.str) > 0;
}

// ===== Transform and arithmetic-like operators (friends) =====

// Unary minus: return a lowercase copy
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(buff[i])));
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenation: return lhs + rhs
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concat-assign: reuse operator+
Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

// Repeat n times
Mystring operator*(const Mystring &lhs, int n) {
    Mystring temp;
    for (int i = 1; i <= n; i++)
        temp = temp + lhs;
    return temp;

    // For better performance with large n, build once in a single buffer.
}

// Repeat-assign
Mystring &operator*=(Mystring &lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

// Pre-increment: uppercase in place, return reference
Mystring &operator++(Mystring &obj) {
    for (size_t i = 0; i < std::strlen(obj.str); i++) {
        obj.str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(obj.str[i])));
    }
    return obj;
}

// Post-increment: return old value, then uppercase in place
Mystring operator++(Mystring &obj, int) {
    Mystring temp{obj};  // copy old value
    ++obj;               // uppercase current using pre-increment
    return temp;         // return old value
}
