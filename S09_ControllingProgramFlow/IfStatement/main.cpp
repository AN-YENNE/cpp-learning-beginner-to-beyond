// Section 9: The if Statement
//
// This program demonstrates the use of simple if statements
// to check conditions and control program flow based on user input.

#include <iostream>
using namespace std;

int main() {
    int num {};
    const int min {10};
    const int max {100};

    cout << "Enter a number between " << min << " and " << max << ": ";
    cin >> num;

    /************************************************************
     * 1) If statement - Checking lower bound
     ************************************************************/
    if (num >= min) {
        cout << "\n=========== If Statement 1 =============" << endl;
        cout << num << " is greater than or equal to " << min << endl;

        int diff {num - min};
        cout << num << " is " << diff << " greater than " << min << endl;
    }

    /************************************************************
     * 2) If statement - Checking upper bound
     ************************************************************/
    if (num <= max) {
        cout << "\n=========== If Statement 2 =============" << endl;
        cout << num << " is less than or equal to " << max << endl;

        int diff {max - num};
        cout << num << " is " << diff << " less than " << max << endl;
    }

    /************************************************************
     * 3) If statement - Checking if within range
     ************************************************************/
    if (num >= min && num <= max) {
        cout << "\n=========== If Statement 3 =============" << endl;
        cout << num << " is within the range of " << min << " and " << max << endl;
        cout << "This means statements 1 and 2 also evaluated as true." << endl;
    }

    /************************************************************
     * 4) If statement - Checking if on the boundary
     ************************************************************/
    if (num == min || num == max) {
        cout << "\n=========== If Statement 4 =============" << endl;
        cout << num << " is right on a boundary!" << endl;
        cout << "This means all 4 statements display!" << endl;
    }

    cout << "\nEnd of program." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON IF STATEMENTS
=====================================================================

1. The if Statement:
--------------------
- Used to make decisions in a program.
- Syntax:
      if (condition)
          statement;

- The condition must evaluate to a boolean value (true or false).
- If the condition is true, the statement(s) inside the block run.
- If the condition is false, they are skipped.

Example:
    int age {18};
    if (age >= 18)
        cout << "You are an adult.";

---------------------------------------------------------------------

2. Compound Statements (Blocks):
--------------------------------
- When multiple statements should execute under one condition,
  enclose them in braces { }.

Example:
    if (score > 90) {
        cout << "Excellent!" << endl;
        grade = 'A';
    }

---------------------------------------------------------------------

3. Relational and Logical Operators in if:
------------------------------------------
- You can combine multiple conditions with logical operators:
      && (AND), || (OR), and ! (NOT)

Examples:
    if (x >= 10 && x <= 20)
        cout << "x is between 10 and 20";

    if (temperature < 0 || raining)
        cout << "Stay indoors!";

---------------------------------------------------------------------

4. Nested if Statements:
------------------------
- You can place one if statement inside another.

Example:
    if (num > 0) {
        if (num < 100)
            cout << "Positive and less than 100";
    }

---------------------------------------------------------------------

5. Common Mistakes:
-------------------
- Using assignment (=) instead of comparison (==) in if conditions.
    if (x = 5)   // WRONG: assigns 5 to x
    if (x == 5)  // CORRECT: compares x with 5

- Forgetting braces when multiple statements are part of the condition.
  Only the first statement after the if executes without braces.

---------------------------------------------------------------------

6. Tips:
--------
- Always use braces for clarity, even for single-line if statements.
- Indent blocks consistently for readability.
- Logical operators (&&, ||) can be used to combine multiple tests.

*/