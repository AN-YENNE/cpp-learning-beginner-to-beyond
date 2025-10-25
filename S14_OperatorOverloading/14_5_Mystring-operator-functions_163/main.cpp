// Overloading operators as NON-MEMBER (friend) functions
//
// This demo uses generic names and prints meaningful messages.
// It shows:
//   - unary - to lowercase
//   - == for equality
//   - + for concatenation
//   - Why non-member overloads allow "literal" + Mystring
// --------------------------------------------------------------
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // Start with a simple string
    Mystring title{"Title"};
    title.display();  // "Title"

    // Unary minus: lowercase
    title = -title;   // make lowercase
    cout << "[Main] After lowercase operation: ";
    title.display();  // "title"

    // Compare values
    Mystring nameA{"Alpha"};
    Mystring cloneA{nameA};
    cout << "[Main] nameA == cloneA ? " << (nameA == cloneA) << endl;  // true

    Mystring nameB{"Beta"};
    cout << "[Main] nameA == nameB ? " << (nameA == nameB) << endl;    // false

    // Friend operator+ allows conversions on both sides
    // "Literal" + Mystring works because the constructor converts the literal to Mystring
    Mystring joined1 = "Alpha" + nameB;        // becomes Mystring("Alpha") + nameB
    cout << "[Main] Joined1: ";
    joined1.display();                          // "AlphaBeta"

    // More chaining with spaces
    Mystring spaced = nameB + " " + nameA;     // "Beta Alpha"
    cout << "[Main] Spaced: ";
    spaced.display();

    Mystring trio = nameB + " " + nameA + " " + "Gamma";
    cout << "[Main] Trio: ";
    trio.display();                             // "Beta Alpha Gamma"

    // Vector usage just to show copies and moves may occur
    vector<Mystring> labels;
    labels.push_back("One");
    labels.push_back("Two");
    labels.push_back("Three");

    cout << "[Main] Vector contents:" << endl;
    for (const Mystring& s : labels) s.display();

    return 0;
}

/*
============================= NOTES =============================

Why use FRIEND (non-member) operator overloads?
------------------------------------------------
- For symmetric binary operators (like +, ==), non-member overloads allow
  implicit conversions on BOTH operands via converting constructors.
  Example:
      Mystring x{"World"};
      auto r = "Hello " + x; // works because "Hello " converts to Mystring

- If operator+ were a member of Mystring, "Hello " + x would FAIL because
  the left operand is not a Mystring (no member function to call).
  You would only get implicit conversion on the RIGHT operand.

What each operator does in this demo:
------------------------------------------------
- operator== : compares character sequences for equality.
- operator-  : returns a lowercase copy of the string.
- operator+  : concatenates two Mystring objects into a new one.

Design and safety notes:
------------------------------------------------
- Deep copy is used wherever appropriate (copy ctor, copy assignment).
- Move operations transfer ownership to avoid extra allocations.
- After a move, the moved-from object is left in a valid, empty state.
- Always return new temporary objects by value for + and - so expressions can chain.

Takeaway:
------------------------------------------------
Friend non-member overloads can make APIs more natural and flexible,
especially for symmetric operations that should work with implicit conversions
on both sides of the operator.
*/
