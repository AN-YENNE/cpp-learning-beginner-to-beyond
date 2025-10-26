// Challenge - Solution 2 (Non-member friend functions)
//
// This class wraps a dynamically allocated C-style string (char*)
// and demonstrates overloading many operators as NON-MEMBER FRIENDS.
// Why friends here?
//   - For symmetric operators like +, ==, etc., non-member overloads
//     allow implicit conversions on both operands.
//
// Notes:
//   - This is an educational example. In production, prefer std::string.
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iosfwd>  // forward declare std::istream and std::ostream

class Mystring
{
    // Friend operator overloads (non-member)
    friend Mystring operator-(const Mystring &obj);                       // lowercase copy
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);  // concatenation
    friend bool     operator==(const Mystring &lhs, const Mystring &rhs); // equals
    friend bool     operator!=(const Mystring &lhs, const Mystring &rhs); // not equals
    friend bool     operator<(const Mystring &lhs, const Mystring &rhs);  // lexical less-than
    friend bool     operator>(const Mystring &lhs, const Mystring &rhs);  // lexical greater-than
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);      // concat-assign
    friend Mystring operator*(const Mystring &lhs, int n);                // repeat n times
    friend Mystring &operator*=(Mystring &lhs, int n);                    // repeat-assign
    friend Mystring &operator++(Mystring &obj);                           // pre-increment: uppercase
    friend Mystring operator++(Mystring &obj, int);                       // post-increment: uppercase
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a null-terminated C string

public:
    // Rule of Five components used here
    Mystring();                           // No-args constructor
    Mystring(const char *s);              // Overloaded constructor
    Mystring(const Mystring &source);     // Copy constructor (deep copy)
    Mystring(Mystring &&source);          // Move constructor (steal pointer)
    ~Mystring();                          // Destructor

    // Assignments
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);      // Move assignment

    // Utilities
    void        display() const;              // print value and length
    int         get_length() const;           // number of characters
    const char *get_str() const;              // raw pointer (read-only)
};

#endif // _MYSTRING_H_
