// Overloaded insertion (<<) and extraction (>>) operators as friends

// What this shows:
//   - A minimal string wrapper that manages a dynamic C-style string (char*)
//   - Rule of Five pieces needed for safe ownership
//   - Friend overloads for stream insertion and extraction
//
// Notes:
//   - We use friend non-member operators so they can access private data
//   - The header includes <iosfwd> to forward-declare iostream types
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iosfwd>  // forward declarations for std::ostream and std::istream

class Mystring {
    // Friends: allow direct access to private char* for I/O operators
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

private:
    char* str;      // pointer to a null-terminated char array

public:
    // Big Five pieces used here
    Mystring();                               // no-args constructor
    Mystring(const char* s);                  // construct from C-string
    Mystring(const Mystring& source);         // copy constructor (deep copy)
    Mystring(Mystring&& source);              // move constructor (steal pointer)
    ~Mystring();                              // destructor

    // Assignments
    Mystring& operator=(const Mystring& rhs); // copy assignment (deep copy)
    Mystring& operator=(Mystring&& rhs);      // move assignment (transfer ownership)

    // Utilities
    void        display() const;
    int         get_length() const;
    const char* get_str() const;
};

#endif // _MYSTRING_H_