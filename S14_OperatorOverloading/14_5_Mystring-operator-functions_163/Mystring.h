// Operator overloading as FRIEND (non-member) functions
//
// What this shows:
//  - Overloading ==, unary -, and + as non-member friend functions
//  - Why friend non-member overloads allow implicit conversions
//    on BOTH operands (e.g., "Alpha" + myStr)
//  - Safe dynamic memory management for a simple string wrapper
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
    // Friend (non-member) operator overloads
    friend bool     operator==(const Mystring& lhs, const Mystring& rhs);
    friend Mystring operator-(const Mystring& obj);                       // to lowercase
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);  // concatenate

private:
    char* str;   // pointer to a null-terminated char array (C-style string)

public:
    // Rule of Five (subset used here)
    Mystring();                       // no-args constructor
    Mystring(const char* s);          // construct from C-string
    Mystring(const Mystring& source); // copy constructor (deep copy)
    Mystring(Mystring&& source);      // move constructor (steal pointer)
    ~Mystring();                      // destructor

    // Assignments
    Mystring& operator=(const Mystring& rhs); // copy assignment (deep copy)
    Mystring& operator=(Mystring&& rhs);      // move assignment (steal pointer)

    // Utilities
    void        display() const;
    int         get_length() const;
    const char* get_str() const;
};

#endif // _MYSTRING_H_
