// Section 14 - Copy Assignment Operator Overloading
// Demonstrates how the copy assignment operator (=) is called when assigning one Mystring object to another.
// Also demonstrates assigning string literals (temporary Mystring objects) to existing objects.
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    // Example 1: Simple copy assignment between two objects
    Mystring greeting{"Welcome"};      // Overloaded constructor
    Mystring message;                  // No-args constructor
    message = greeting;                // Copy assignment: message.operator=(greeting)
    message = "New Message";           // Assigning from a temporary Mystring("New Message")

    // Example 2: Copy constructor and assignment in sequence
    Mystring empty;                    // No-args constructor
    Mystring name("GenericName");      // Overloaded constructor
    Mystring alias{name};              // Copy constructor

    empty = alias;                     // Copy assignment
    empty.display();                   // Displays "GenericName"
    name.display();
    alias.display();
    empty.display();

    // Example 3: Assign from string literal
    Mystring group;
    group = "Alpha, Beta, Gamma";
    group.display();

    // Example 4: Vector of Mystring objects
    vector<Mystring> my_strings;
    my_strings.push_back("First");
    my_strings.push_back("Second");
    my_strings.push_back("Third");

    cout << "=== Displaying vector contents before modification ===" << endl;
    for (const Mystring &s : my_strings)
        s.display();

    cout << "=== Modifying all vector elements using copy assignment ===" << endl;
    for (Mystring &s : my_strings)
        s = "Updated";

    cout << "=== Displaying vector contents after modification ===" << endl;
    for (const Mystring &s : my_strings)
        s.display();

    return 0;
}

/*
============================= NOTES =============================

Copy Assignment Operator (=)
---------------------------------------------------------------
C++ provides a default assignment operator for assigning one object
to another, but it performs **memberwise assignment** (shallow copy).
This is unsafe for classes managing resources (like raw pointers).

Example:
    Mystring a{"Alpha"};
    Mystring b{"Beta"};
    b = a;     // assignment -> copy assignment operator is called

If we do not define our own, the compiler’s default operator will just
copy the pointer value (shallow copy), causing both objects to point
to the same memory. When destructors run, memory will be freed twice,
leading to undefined behavior (crash).

Therefore, we must **overload** the copy assignment operator to perform
a **deep copy**.

Steps for implementing a deep copy assignment:
---------------------------------------------------------------
1. Check for self-assignment:
       if (this == &rhs)
           return *this;    // avoid deleting memory from same object

2. Deallocate existing memory before overwriting:
       delete [] str;

3. Allocate new memory for the copy:
       str = new char[std::strlen(rhs.str) + 1];

4. Copy data from rhs to current object:
       std::strcpy(str, rhs.str);

5. Return *this (by reference):
       return *this;

Returning *this enables chain assignment:
       s1 = s2 = s3;  // works correctly because operator= returns *this

----------------------------------------------------------------
In this example:
- The operator= is overloaded to ensure deep copy.
- The copy constructor ensures deep copy during initialization.
- Destructor ensures dynamic memory is safely released.
----------------------------------------------------------------
*/