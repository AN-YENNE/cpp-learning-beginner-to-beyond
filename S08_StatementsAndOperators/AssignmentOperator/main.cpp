// Section 8: Assignment operator (=) and friends
//
// This program demonstrates many assignment scenarios:
// - Simple assignment to built-in types
// - Chained assignment (a = b = c)
// - Assignment as an expression (its value is the assigned value)
// - Compound assignments (+=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=)
// - Mixed-type assignments and explicit casts
// - Assignments in conditions and common pitfalls
// - Assignment with std::string

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    cout << "=== 1) Simple assignments to built-in types ===" << endl;
    int i {10};               // list-initialization
    int j = 20;               // copy-initialization
    int k;                    // uninitialized (avoid in real code)
    k = 30;                   // simple assignment
    cout << "i: " << i << ", j: " << j << ", k: " << k << endl;

    double d {3.5};
    d = 6.25;                 // reassign double
    cout << "d: " << d << endl;

    char ch {'A'};
    ch = 'Z';
    cout << "ch: " << ch << endl;

    bool flag {false};
    flag = true;
    cout << "flag: " << flag << " (1 means true, 0 means false)" << endl;

    cout << "\n=== 2) Chained assignment (a = b = c) ===" << endl;
    int a {}, b {}, c {};
    c = 42;
    a = b = c; // b becomes c, then a becomes b
    cout << "a: " << a << ", b: " << b << ", c: " << c << " (all should be 42)" << endl;

    cout << "\n=== 3) Assignment is an expression (returns assigned value) ===" << endl;
    int result = (a = 7); // a becomes 7, and the whole expression has value 7
    cout << "After result = (a = 7): a: " << a << ", result: " << result << endl;
    int z = 0;
    if ((z = 5)) { // assigns 5 to z, then tests 5 (non-zero is true)
        cout << "Condition used assignment: z is " << z << " and condition is true" << endl;
    }

    cout << "\n=== 4) Compound assignments on integers ===" << endl;
    int x {10};
    cout << "Start x: " << x << endl;

    x += 5;   cout << "x += 5  -> x: " << x << endl;   // 15
    x -= 3;   cout << "x -= 3  -> x: " << x << endl;   // 12
    x *= 4;   cout << "x *= 4  -> x: " << x << endl;   // 48
    x /= 6;   cout << "x /= 6  -> x: " << x << endl;   // 8
    x %= 5;   cout << "x %= 5  -> x: " << x << endl;   // 3

    cout << "\n=== 5) Compound assignments with bitwise operators ===" << endl;
    unsigned int bits {0b0101}; // binary literal 5
    cout << "Start bits: " << bits << endl;
    bits <<= 1;  cout << "bits <<= 1 -> " << bits << endl;  // 10
    bits >>= 2;  cout << "bits >>= 2 -> " << bits << endl;  // 2
    bits |= 0b1000; cout << "bits |= 0b1000 -> " << bits << endl; // 10
    bits &= 0b1100; cout << "bits &= 0b1100 -> " << bits << endl; // 8
    bits ^= 0b0100; cout << "bits ^= 0b0100 -> " << bits << endl; // 12

    cout << "\n=== 6) Mixed-type assignments and conversions ===" << endl;
    double dd {0.0};
    int ii {9};
    dd = ii; // implicit promotion int -> double
    cout << "dd = ii; dd: " << dd << " (promotion int to double)" << endl;

    double fraction {3.9};
    int narrowed {};
    narrowed = static_cast<int>(fraction); // explicit cast to avoid narrowing surprise
    cout << "narrowed = static_cast<int>(3.9); narrowed: " << narrowed << endl;

    // Implicit demotion occurs but may lose data
    int implicit_demoted = 0;
    implicit_demoted = static_cast<int>(123456789.987); // explicit cast is clearer
    cout << "implicit_demoted from 123456789.987 -> " << implicit_demoted << endl;

    cout << "\n=== 7) Assignment with std::string ===" << endl;
    string s1 {"alpha"};
    string s2;
    s2 = s1;                    // copy assign
    cout << "s1: " << s1 << ", s2 (after s2 = s1): " << s2 << endl;

    s2 = "bravo";               // assign from string literal
    cout << "s2 reassigned to literal: " << s2 << endl;

    s2 += "_suffix";            // compound assignment on strings
    cout << "s2 after s2 += \"_suffix\": " << s2 << endl;

    cout << "\n=== 8) Assignment inside conditions: common pitfall ===" << endl;
    int t {0};
    cout << "t is " << t << " initially" << endl;
    if (t = 1) { // assigns 1 to t, then evaluates 1 (true)
        cout << "if (t = 1) executed. t is now " << t << " and condition is true" << endl;
    }
    // Better: if (t == 1) to compare. Or write (1 == t) to catch accidental assignment.

    cout << "\n=== 9) Const and assignability notes ===" << endl;
    const int const_value {123};
    cout << "const_value is " << const_value << endl;
    // const_value = 456; // Uncommenting this line would be a compile error (lhs not assignable)

    cout << "\n=== 10) Overflow and assignment ===" << endl;
    short small {30000};
    short more {1000};
    // The product is computed in int, then assigned to short (may overflow after cast)
    short prod = static_cast<short>(small * more);
    cout << "small: " << small << ", more: " << more << ", prod (with overflow risk): " << prod << endl;

    cout << "\nAll assignment demonstrations complete." << endl;

    return 0;
}

/*
=====================================================================
NOTES: STATEMENTS, EXPRESSIONS, ASSIGNMENTS, OPERATORS
=====================================================================

1. Assignment operator: lhs = rhs
   - rhs is an expression that is evaluated to a value.
   - The value of rhs is stored in lhs.
   - The value of rhs must be type compatible with lhs (or convertible).
   - The lhs must be assignable (for example, const variables are not assignable).
   - The assignment expression itself evaluates to the assigned value.
   - More than one variable can be assigned in a single statement via chaining:
       a = b = c = 5;

2. Mixed Type Expressions
   - C++ operations occur on operands of the same type. If they differ, C++ converts one.
   - Conversions can affect results, especially in division or when precision is lost.
   - If C++ cannot convert, a compiler error occurs.
   - Conversion hierarchy (commonly, larger/wider types hold more information):
       long double, double, float, unsigned long, long, unsigned int, int
     Also note: short and char are promoted to int in most expressions.
   - Type coercion: conversion of one operand to another type.
   - Promotion: conversion to a higher (wider) type, often used in arithmetic.
   - Demotion: conversion to a lower (narrower) type, often used in assignment.
   - Prefer explicit casts for clarity:
       average = static_cast<double>(total) / count;

3. Precedence, Associativity, and Short-Circuit
   - Logical not (!) has higher precedence than logical and (&&).
   - Logical and (&&) has higher precedence than logical or (||).
   - not is unary; and/or are binary.
   - Short-circuit evaluation:
       For A && B && C:
           If A is false, B and C are not evaluated.
       For A || B || C:
           If A is true, B and C are not evaluated.
   - Associativity:
       Use precedence rules when adjacent operators are different.
         expr1 op1 expr2 op2 expr3  // precedence decides grouping
       Use associativity rules when adjacent operators have the same precedence.
         expr1 op expr2 op expr3    // associativity decides left-to-right or right-to-left
   - Use parentheses to remove ambiguity:
       result = (x + y) * z;

4. Assignment Variants (compound assignments)
   - Arithmetic:   +=, -=, *=, /=, %=
   - Bitwise:      <<=, >>=, &=, ^=, |=
   - String:       += for concatenation
   - These combine an operation with assignment:
       x += 5;   // same as x = x + 5;

5. Assignment in Conditions: Pitfall
   - if (x = 1) assigns 1 to x, then tests true (since 1 is non-zero).
   - To compare, use ==:
       if (x == 1) { ... }
   - Some teams prefer (1 == x) to avoid accidental assignment.

6. Const and Assignability
   - const variables cannot be assigned after initialization.
   - Attempting to assign to const will cause a compile error.

Tips:
- Initialize variables upon declaration to avoid using garbage values.
- Use static_cast for explicit, clear type conversions.
- Prefer .at() when accessing vectors while learning; it checks bounds.
- Use parentheses to clarify complex expressions.
=====================================================================
*/
