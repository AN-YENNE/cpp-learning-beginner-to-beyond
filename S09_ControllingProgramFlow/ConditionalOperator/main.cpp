// Section 9 Conditional (Ternary) Operator

#include <iostream>
using namespace std;

int main() {

    /************************************************************
     * 1) Example: Check if a number is even or odd
     ************************************************************/
//    int num {};
//    cout << "Enter an integer: ";
//    cin >> num;
//
//    // Traditional if-else version
//    if (num % 2 == 0)
//        cout << num << " is even" << endl;
//    else
//        cout << num << " is odd" << endl;
//
//    // Equivalent ternary operator version
//    cout << num << " is " << ((num % 2 == 0) ? "even" : "odd") << endl;


    /************************************************************
     * 2) Example: Find the largest and smallest numbers
     ************************************************************/
    int num1{}, num2{};

    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;

    if (num1 != num2) {
        cout << "\n==================================" << endl;
        cout << "Largest number: " << ((num1 > num2) ? num1 : num2) << endl;
        cout << "Smallest number: " << ((num1 < num2) ? num1 : num2) << endl;
    } else {
        cout << "\n==================================" << endl;
        cout << "The numbers are equal." << endl;
    }

    cout << "\nProgram complete." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON THE CONDITIONAL (TERNARY) OPERATOR
=====================================================================

1. Overview:
-------------
- The conditional operator `? :` provides a compact way to write simple
  conditional expressions.

- Syntax:
      condition ? expression1 : expression2;

- If `condition` is true → evaluates `expression1`
- If `condition` is false → evaluates `expression2`

Example:
    int a = 10, b = 20;
    int max = (a > b) ? a : b;   // max = 20

---------------------------------------------------------------------

2. The Conditional Operator is Often Used For:
-----------------------------------------------
- Making quick value assignments
- Inline comparisons in output
- Simplifying short if-else logic

Examples:
    string result = (score >= 50) ? "Pass" : "Fail";
    cout << ((age >= 18) ? "Adult" : "Minor");

---------------------------------------------------------------------

3. Comparison with if-else:
---------------------------
Traditional if-else:
    if (x > y)
        max = x;
    else
        max = y;

Using ternary operator:
    max = (x > y) ? x : y;

Both produce the same result.

---------------------------------------------------------------------

4. Nesting Example (Use Sparingly!):
------------------------------------
    int x = 10, y = 20, z = 30;
    int largest = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    cout << "Largest: " << largest;

Too many nested ternaries reduce readability—prefer if-else in such cases.

---------------------------------------------------------------------

5. Advantages:
--------------
- Compact, inline decision-making.
- Ideal for simple true/false cases or assigning one of two values.

---------------------------------------------------------------------

6. Disadvantages:
-----------------
- Hard to read when nested.
- Not suitable for complex multi-step logic (use `if-else` instead).

=====================================================================
*/
