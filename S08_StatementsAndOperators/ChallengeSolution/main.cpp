// Example: Change-Making Challenge
//
// This program calculates how to provide change in US currency
// given a number of cents entered by the user.
//
// Demonstrates integer division, the modulo operator, and step-by-step problem solving.
// ===================================================================

#include <iostream>
using namespace std;

int main() {

    // Define currency conversion constants in cents
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};

    int change_amount {};
    cout << "Enter an amount in cents: ";
    cin >> change_amount;

    int balance{}, dollars{}, quarters{}, dimes{}, nickels{}, pennies{};

    /************************************************************
     * Solution 1 - Without Modulo Operator
     ************************************************************/
    cout << "\n=== Solution 1: Without Using Modulo ===" << endl;

    dollars = change_amount / dollar_value;
    balance = change_amount - (dollars * dollar_value);

    quarters = balance / quarter_value;
    balance -= quarters * quarter_value;

    dimes = balance / dime_value;
    balance -= dimes * dime_value;

    nickels = balance / nickel_value;
    balance -= nickels * nickel_value;

    pennies = balance;

    cout << "\nYou can provide this change as follows:" << endl;
    cout << "Dollars  : " << dollars << endl;
    cout << "Quarters : " << quarters << endl;
    cout << "Dimes    : " << dimes << endl;
    cout << "Nickels  : " << nickels << endl;
    cout << "Pennies  : " << pennies << endl;

    /************************************************************
     * Solution 2 - Using Modulo Operator
     ************************************************************/
    cout << "\n=== Solution 2: Using the Modulo Operator (%) ===" << endl;

    balance = dollars = quarters = dimes = nickels = pennies = 0;

    dollars = change_amount / dollar_value;
    balance = change_amount % dollar_value;

    quarters = balance / quarter_value;
    balance %= quarter_value;

    dimes = balance / dime_value;
    balance %= dime_value;

    nickels = balance / nickel_value;
    balance %= nickel_value;

    pennies = balance;

    cout << "\nYou can provide this change as follows:" << endl;
    cout << "Dollars  : " << dollars << endl;
    cout << "Quarters : " << quarters << endl;
    cout << "Dimes    : " << dimes << endl;
    cout << "Nickels  : " << nickels << endl;
    cout << "Pennies  : " << pennies << endl;

    cout << "\nThank you for using the change calculator!" << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES AND EXPLANATION:
=====================================================================

1. Integer Division:
   - Division between integers automatically truncates (rounds down).
     Example: 92 / 25 = 3 (not 3.68)
   - This is perfect for calculating how many coins fit into a given amount.

2. Modulo Operator (%):
   - Returns the remainder after integer division.
     Example: 92 % 25 = 17 (the remainder after removing 3 quarters).

3. Step-by-Step Breakdown:
   - Calculate dollars:  total / 100
   - Find remaining cents: total % 100
   - Calculate quarters, dimes, nickels, and pennies the same way.

4. Constants:
   - Defining values like `dollar_value` and `quarter_value` ensures clarity
     and easy future modification.

5. Resetting Values:
   - Before Solution 2, we reset all variables to zero to avoid stale data.

6. Testing:
   Example: For 92 cents
      Dollars  : 0
      Quarters : 3
      Dimes    : 1
      Nickels  : 1
      Pennies  : 2

7. Tips:
   - Always test with multiple inputs (e.g., 0, 99, 142, 500).
   - Use `const` for fixed conversion values.
   - Use integer division for whole units and modulo for remainders.

=====================================================================
SUMMARY:
---------------------------------------------------------------------
• Division (`/`) gives the number of coins.
• Modulo (`%`) gives the leftover balance.
• Combine both to break a value into currency denominations.
=====================================================================
*/
