// Section 14 - Mystring Example
// Demonstrates how constructors and destructors work by creating and copying Mystring objects.
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    // Default constructor (creates an empty string)
    Mystring empty;

    // Overloaded constructor (initializes with string literal)
    Mystring larry("Larry");

    // Copy constructor (creates a new object as a copy of another object)
    Mystring stooge{larry};

    // Display object contents and lengths
    empty.display();   // Should show "" : 0
    larry.display();   // Should show "Larry" : 5
    stooge.display();  // Should show "Larry" : 5 (independent copy)

    return 0;
}

/*
Program flow explanation:
1. When 'empty' is created, the no-args constructor runs.
2. When 'larry' is created, the overloaded constructor runs.
3. When 'stooge' is created, the copy constructor runs.
4. At the end of main(), destructors are called automatically
   for each object (in reverse order of creation).

Expected Output:
----------------
 : 0
Larry : 5
Larry : 5

Each "Larry" is stored separately in memory thanks to the deep copy constructor.
*/