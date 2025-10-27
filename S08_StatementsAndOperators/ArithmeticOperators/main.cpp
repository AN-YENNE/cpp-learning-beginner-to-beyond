// Section 8: Arithmetic Operators
//
// This program demonstrates the basic arithmetic operators in C++, including addition, subtraction, multiplication, division, and modulo.
// It also explains integer division vs floating-point division and shows how arithmetic behaves with different data types.

#include <iostream>
using namespace std;

int main() {

    /************************************************************
     * 1) Basic integer arithmetic
     ************************************************************/
    int num1 {200};
    int num2 {100};
    int result {0};

    cout << "=== Basic Integer Arithmetic ===" << endl;

    result = num1 + num2;
    cout << num1 << " + " << num2 << " = " << result << endl;

    result = num1 - num2;
    cout << num1 << " - " << num2 << " = " << result << endl;

    result = num1 * num2;
    cout << num1 << " * " << num2 << " = " << result << endl;

    result = num1 / num2;
    cout << num1 << " / " << num2 << " = " << result << endl;

    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result << " (remainder)" << endl;

    /************************************************************
     * 2) Integer division and modulo examples
     ************************************************************/
    cout << "\n=== Integer Division and Modulo ===" << endl;
    num1 = 10;
    num2 = 3;

    result = num1 / num2;
    cout << num1 << " / " << num2 << " = " << result
         << " (integer division - fractional part discarded)" << endl;

    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result
         << " (remainder after division)" << endl;

    /************************************************************
     * 3) Mixed arithmetic with constants
     ************************************************************/
    cout << "\n=== Mixed Arithmetic with Constants ===" << endl;
    result = num1 * 10 + num2;
    cout << "num1 * 10 + num2 = " << result << endl;

    cout << "5 / 10 = " << 5 / 10 << " (integer division)" << endl;
    cout << "5.0 / 10.0 = " << 5.0 / 10.0 << " (floating-point division)" << endl;

    /************************************************************
     * 4) Floating-point arithmetic examples
     ************************************************************/
    cout << "\n=== Floating-Point Arithmetic ===" << endl;
    double x {12.5}, y {4.2}, d_result {};
    d_result = x + y;
    cout << x << " + " << y << " = " << d_result << endl;

    d_result = x - y;
    cout << x << " - " << y << " = " << d_result << endl;

    d_result = x * y;
    cout << x << " * " << y << " = " << d_result << endl;

    d_result = x / y;
    cout << x << " / " << y << " = " << d_result << endl;

    /************************************************************
     * 5) Division by zero note (integer vs double)
     ************************************************************/
    cout << "\n=== Division by Zero Notes ===" << endl;
    cout << "Dividing by zero (integer): causes a runtime error (undefined behavior)." << endl;
    cout << "Dividing by zero (floating-point): results in +inf, -inf, or NaN." << endl;

    cout << "\nProgram complete." << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON STATEMENTS, EXPRESSIONS, ASSIGNMENTS, AND OPERATORS
=====================================================================

1. Arithmetic Operators
------------------------
Operator | Meaning                 | Example     | Result
--------- | ----------------------- | ----------- | -------
+         | Addition                | 5 + 2       | 7
-         | Subtraction             | 5 - 2       | 3
*         | Multiplication          | 5 * 2       | 10
/         | Division                | 5 / 2       | 2 (integer division)
%         | Modulo (remainder)      | 5 % 2       | 1

Important: % works only with integers, not floating-point types.

+ , - , * , / operators are overloaded to work with multiple numeric types
such as int, float, double, long double, etc.
The type of result depends on operand types and conversion rules.

---------------------------------------------------------------------

2. Integer Division vs Floating-Point Division
----------------------------------------------
- Integer division truncates toward zero:
    7 / 3 = 2
    -7 / 3 = -2

- Floating-point division preserves fractional parts:
    7.0 / 3.0 = 2.33333

- Mixing int and double causes type promotion:
    7 / 3.0 → 7.0 / 3.0 → 2.33333

---------------------------------------------------------------------

3. Modulo Operator (%)
-----------------------
- Returns the remainder of an integer division.
    10 % 3 = 1
    20 % 7 = 6
- Cannot be used with floating-point types (e.g., double).

---------------------------------------------------------------------

4. Mixed-Type Expressions and Type Conversion
----------------------------------------------
C++ will automatically convert operands to a common type:
- If one operand is double and the other is int → int is promoted to double.
- The result will be in the type of the wider operand.

Example:
    int a = 7;
    double b = 2.0;
    double result = a / b;  // a promoted to double, result = 3.5

Type Promotion Order (from narrowest to widest):
    char → short → int → long → float → double → long double

Type Coercion: Automatic type conversion done by the compiler.
Promotion: Conversion to a higher type (int to double).
Demotion: Conversion to a lower type (double to int).

Use explicit casting to control conversion:
    double avg = static_cast<double>(total) / count;

---------------------------------------------------------------------

5. Expression Evaluation
--------------------------
Operator precedence and associativity determine order of evaluation.

Example:
    result = num1 * 10 + num2;
    Multiplication (*) happens before addition (+).

Use parentheses for clarity:
    result = num1 * (10 + num2);

---------------------------------------------------------------------

6. Associativity
----------------
Associativity decides evaluation order when operators have the same precedence.

Example:
    a = b = c = 10;  // Assignment is right-associative
    => a = (b = (c = 10))

    a + b + c;       // Addition is left-associative
    => ((a + b) + c)

---------------------------------------------------------------------

7. Short-Circuit Evaluation (for logical operators)
---------------------------------------------------
When evaluating a logical expression, C++ stops as soon as the result is known.

    expr1 && expr2 && expr3
    - If expr1 is false, expr2 and expr3 are not evaluated.

    expr1 || expr2 || expr3
    - If expr1 is true, expr2 and expr3 are not evaluated.

---------------------------------------------------------------------

8. Common Arithmetic Pitfalls
------------------------------
- Integer division truncates fractional parts.
- Modulo works only with integers.
- Be careful with integer overflow (e.g., multiplying large values).
- Division by zero causes a crash for integers and NaN/inf for floating points.
- Always ensure correct operand types to avoid unexpected results.

---------------------------------------------------------------------

9. Tips
--------
- Use static_cast for explicit type conversion.
- Use parentheses to clarify order of operations.
- Prefer double for fractional calculations.
- Remember: integer operations are exact but limited; floating-point ones are approximate.
*/
