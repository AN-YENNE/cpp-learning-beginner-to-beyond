#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iosfwd> // forward declare std::ostream, std::istream

class Mystring
{
    // Stream operators as friends so they can access private data directly
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    // Pointer to a dynamically allocated null-terminated C string
    char *str;

public:
    // Rule of Five components used here
    Mystring();                           // No-args constructor
    Mystring(const char *s);              // Overloaded constructor
    Mystring(const Mystring &source);     // Copy constructor
    Mystring(Mystring &&source);          // Move constructor
    ~Mystring();                          // Destructor

    // Assignments
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);      // Move assignment

    // Basic utilities
    void display() const;                 // Print string and length
    int get_length() const;               // Number of characters
    const char *get_str() const;          // Expose raw pointer (read-only)

    // Member operator overloads (challenge focus)
    Mystring operator-() const;                   // lowercase copy
    Mystring operator+(const Mystring &rhs) const;// concatenation
    bool operator==(const Mystring &rhs) const;   // equality
    bool operator!=(const Mystring &rhs) const;   // inequality
    bool operator<(const Mystring &rhs) const;    // lexical less-than
    bool operator>(const Mystring &rhs) const;    // lexical greater-than
    Mystring &operator+=(const Mystring &rhs);    // concat-assign
    Mystring operator*(int n) const;              // repeat n times
    Mystring &operator*=(int n);                  // repeat-assign
    Mystring &operator++();                       // pre-increment: make uppercase
    Mystring operator++(int);                     // post-increment: make uppercase
};

#endif // _MYSTRING_H_
