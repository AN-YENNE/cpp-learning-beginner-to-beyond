// Section 9 If-Else Statement
#include <iostream>
using namespace std;

int main() {
    int num {};
    const int target {10};

    cout << "Enter a number and I'll compare it to " << target << ": ";
    cin >> num;

    /************************************************************
     * If-Else: Conditional branching based on comparison result
     ************************************************************/
    if (num >= target) {
        cout << "\n==================================" << endl;
        cout << num << " is greater than or equal to " << target << endl;

        int diff { num - target };
        cout << num << " is " << diff << " greater than " << target << endl;

    } else {
        cout << "\n==================================" << endl;
        cout << num << " is less than " << target << endl;

        int diff { target - num };
        cout << num << " is " << diff << " less than " << target << endl;
    }

    cout << "\nEnd of comparison." << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES ON IF-ELSE STATEMENTS
=====================================================================

1. The If-Else Structure:
--------------------------
- The `if` statement tests a condition.
- If the condition evaluates to `true`, the `if` block executes.
- If the condition evaluates to `false`, the `else` block executes.

Syntax:
    if (condition) {
        // executes if true
    } else {
        // executes if false
    }

Example:
    if (age >= 18)
        cout << "You are an adult.";
    else
        cout << "You are a minor.";

---------------------------------------------------------------------

2. How It Works:
----------------
- Exactly one of the two branches will run.
- If the condition is `true`, the program ignores the `else` part.
- If the condition is `false`, it skips the `if` part and runs `else`.

---------------------------------------------------------------------

3. Example in This Program:
----------------------------
- Condition: (num >= target)
    * If true  → print “greater than or equal to”
    * If false → print “less than”

This is a simple branching example using one decision point.

---------------------------------------------------------------------

4. Using Else If:
-----------------
- When there are multiple conditions to check, you can chain them.

Example:
    if (score >= 90)
        cout << "Grade: A";
    else if (score >= 80)
        cout << "Grade: B";
    else if (score >= 70)
        cout << "Grade: C";
    else
        cout << "Fail";

---------------------------------------------------------------------

5. Best Practices:
------------------
- Always use braces `{ }`, even for one-line conditions.
- Indent consistently to improve readability.
- Keep condition logic simple and easy to follow.
- Avoid deeply nested if-else structures when possible.

---------------------------------------------------------------------

6. Common Pitfalls:
-------------------
- Using `=` instead of `==` (assignment instead of comparison).
- Missing `else` when it’s logically needed.
- Unclear condition ranges (e.g., overlapping conditions).
=====================================================================
*/
