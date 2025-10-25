// Section 14 - Operator Overloading as Member Methods
//
// This class demonstrates **operator overloading** for unary and binary operators.
// Operators implemented:
//   - operator==() : Equality comparison
//   - operator-()  : Unary operator to convert all characters to lowercase
//   - operator+()  : Binary operator to concatenate two Mystring objects
//
// Key Learning Points:
// 1. How to overload operators as **member functions**.
// 2. How to return new temporary Mystring objects.
// 3. Difference between unary and binary operators in syntax.
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char* str;  // Pointer to a dynamically allocated C-style string

public:
    // Constructors and destructor
    Mystring();                             // No-args constructor
    Mystring(const char* s);                // Overloaded constructor
    Mystring(const Mystring& source);       // Copy constructor
    Mystring(Mystring&& source);            // Move constructor
    ~Mystring();                            // Destructor

    // Assignment operators
    Mystring& operator=(const Mystring& rhs);  // Copy assignment
    Mystring& operator=(Mystring&& rhs);       // Move assignment

    // Operator overloads
    Mystring operator-() const;                 // Unary operator: convert to lowercase
    Mystring operator+(const Mystring& rhs) const; // Binary operator: concatenate
    bool operator==(const Mystring& rhs) const;    // Equality comparison

    // Utility functions
    void display() const;
    int get_length() const;
    const char* get_str() const;
};

#endif // _MYSTRING_H_
