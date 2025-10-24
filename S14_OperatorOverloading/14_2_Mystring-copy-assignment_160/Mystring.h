// Section 14 - Copy Assignment Operator Overloading
//
// This example shows how to implement the **copy assignment operator (=)**
// for a user-defined class that manages dynamic memory.
//
// Key learning goals:
// 1. Understand when and why you need to overload the assignment operator.
// 2. Learn how to safely perform a deep copy to prevent double deletion.
// 3. Learn the required pattern: check for self-assignment, delete existing
//    memory, allocate new memory, copy, and return *this.
//
// This class manages a C-style string dynamically and supports proper
// deep copying during assignments.
// --------------------------------------------------------------
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str;  // pointer to a char[] that holds a C-style string

public:
    Mystring();                              // No-args constructor
    Mystring(const char *s);                 // Overloaded constructor
    Mystring(const Mystring &source);        // Copy constructor
    ~Mystring();                             // Destructor

    Mystring &operator=(const Mystring &rhs); // Copy assignment operator

    void display() const;                    // Display string and its length
    int get_length() const;                  // Returns string length
    const char *get_str() const;             // Returns internal C-string
};

#endif // _MYSTRING_H_
