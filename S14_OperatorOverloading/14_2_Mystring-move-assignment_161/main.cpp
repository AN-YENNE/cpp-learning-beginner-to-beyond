// File3: main.cpp
// --------------------------------------------------------------
// Section 14
// Overloading move constructor and move assignment operator
//
// This driver demonstrates when copy vs. move assignment happens.
// We use generic sample names and messages for clarity.
// --------------------------------------------------------------
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    // Example A: Move assignment from a temporary (rvalue)
    Mystring a{"SampleOne"};      // Overloaded ctor
    a = Mystring{"SampleTwo"};    // Temporary created, then move assignment
    a = "SampleThree";            // Temporary created from const char*, then move assignment

    // Example B: Copy vs Move depending on lvalue/rvalue
    Mystring empty;               // No-args ctor
    Mystring nameA("NameA");      // Overloaded ctor
    Mystring aliasA{nameA};       // Copy ctor (aliasA is a copy of nameA)
    Mystring group;               // No-args ctor

    empty = aliasA;               // Copy assignment (aliasA is an lvalue)
    empty = "NameZ";              // Move assignment (temporary rvalue from literal)

    empty.display();
    nameA.display();
    aliasA.display();
    empty.display();

    group = "NameA, NameB, NameC";
    group.display();

    // Example C: Vector behavior often triggers moves
    vector<Mystring> names;
    names.push_back("NameA");     // Likely move ctor from temporary
    names.push_back("NameB");     // Likely move ctor
    names.push_back("NameC");     // Likely move ctor

    cout << "=== Before modification ===" << endl;
    for (const Mystring& s : names)
        s.display();

    cout << "=== Modifying all elements with move assignment from rvalue ===" << endl;
    for (Mystring& s : names)
        s = "Updated";           // Move assignment from temporary

    cout << "=== After modification ===" << endl;
    for (const Mystring& s : names)
        s.display();

    return 0;
}

/*
Summary Notes: Move Assignment Operator (= with rvalue)
-------------------------------------------------------
1) Purpose:
   - Efficiently assign temporary (rvalue) objects by transferring ownership
     of resources instead of allocating and copying.

2) When it is selected:
   - The left-hand side is an lvalue object and the right-hand side is an rvalue
     (temporary), e.g. obj = Mystring{"temp"} or obj = "literal".

3) Typical implementation steps:
   a) Check for self-assignment:
        if (this == &rhs) return *this;
   b) Delete current resource:
        delete [] str;
   c) Steal the resource pointer from rhs:
        str = rhs.str;
   d) Null out rhs so it will not free the resource:
        rhs.str = nullptr;
   e) Return *this by reference:
        return *this;

4) Benefits:
   - Avoids allocation and character copy for large strings.
   - Leaves the moved-from object in a valid but empty state.

5) Relationship to copy operations:
   - Copy assignment does a deep copy (allocate + copy characters).
   - Move assignment just transfers the pointer and nulls the source.
*/
