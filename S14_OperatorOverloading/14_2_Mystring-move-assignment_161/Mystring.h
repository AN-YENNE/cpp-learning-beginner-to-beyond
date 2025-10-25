// Move Assignment Operator Overloading
//
// This header defines a simple Mystring class that owns a dynamic
// C-style string (char*). It demonstrates:
//   - Constructors (no-args, from const char*, copy, move)
//   - Destructor
//   - Copy assignment operator (=)
//   - Move assignment operator (= with rvalue)
//
// Key ideas:
//   - Deep copy for copy operations (own your memory).
//   - Move operations transfer ownership and null the source.
//   - Always return *this by reference from assignment operators.
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char* str;  // pointer to a heap-allocated, null-terminated char array

public:
    Mystring();                          // No-args constructor
    Mystring(const char* s);             // Overloaded constructor from C-string
    Mystring(const Mystring& source);    // Copy constructor (deep copy)
    Mystring(Mystring&& source);         // Move constructor (steal pointer)
    ~Mystring();                         // Destructor

    // Assignment operators
    Mystring& operator=(const Mystring& rhs);  // Copy assignment (deep copy)
    Mystring& operator=(Mystring&& rhs);       // Move assignment (transfer ownership)

    // Observers
    void display() const;                 // Print contents and length
    int get_length() const;               // Return length
    const char* get_str() const;          // Return read-only C-string pointer
};

#endif // _MYSTRING_H_