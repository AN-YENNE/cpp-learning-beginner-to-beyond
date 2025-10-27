// Section 8: Currency Conversion (EUR to INR)
//
// This simple program converts an amount in Euros (EUR) to Indian Rupees (INR).
// Demonstrates the use of constants, basic arithmetic, and input/output.

#include <iostream>
using namespace std;

int main() {

    const double inr_per_eur {90.45}; // example exchange rate

    cout << "Welcome to the EUR to INR Currency Converter!" << endl;
    cout << "Enter the amount in Euros (EUR): ";

    double euros {0.0};
    double rupees {0.0};

    cin >> euros;

    rupees = euros * inr_per_eur;

    cout << euros << " Euros is equivalent to " << rupees << " Indian Rupees." << endl;

    cout << "\nThank you for using the converter!" << endl;
    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES:
=====================================================================
1. Use of constants:
   - `const` prevents accidental modification of the exchange rate.
   - Improves code readability and maintainability.

2. Input and Output:
   - `cin` reads user input.
   - `cout` displays the result.

3. Precision:
   - You can use `<iomanip>` and `setprecision()` for formatted output if desired.

4. Arithmetic:
   - Simple multiplication used for currency conversion.

=====================================================================
*/
