// Section 6 Challenge - Carpet Cleaning Service
//
// This program calculates an estimate for a carpet cleaning service.
// It demonstrates the use of constants, arithmetic operations, and user input.
//
// Concepts covered:
// 1. Declaring and using constants (const keyword)
// 2. Reading multiple user inputs using `cin`
// 3. Performing arithmetic calculations
// 4. Output formatting and meaningful user interaction
//
// Constants are used for fixed values like price per room, tax rate, and estimate validity period.

#include <iostream>
using namespace std;

int main() {
    cout << "=============================================" << endl;
    cout << " Welcome to SparkleClean Carpet Services " << endl;
    cout << "=============================================" << endl;

    // Ask user how many rooms they want cleaned
    int small_rooms {0};
    cout << "\nEnter the number of SMALL rooms to clean: ";
    cin >> small_rooms;

    int large_rooms {0};
    cout << "Enter the number of LARGE rooms to clean: ";
    cin >> large_rooms;

    // Declare constants - these values remain fixed
    const double price_per_small_room {25.0};   // dollars
    const double price_per_large_room {35.0};   // dollars
    const double sales_tax_rate {0.06};         // 6% tax
    const int estimate_validity_days {30};      // offer valid for 30 days

    // Calculate subtotal (before tax)
    double cost_of_small_rooms {price_per_small_room * small_rooms};
    double cost_of_large_rooms {price_per_large_room * large_rooms};
    double subtotal {cost_of_small_rooms + cost_of_large_rooms};

    // Calculate tax and total estimate
    double tax_amount {subtotal * sales_tax_rate};
    double total_estimate {subtotal + tax_amount};

    // Display detailed estimate
    cout << "\n================= ESTIMATE =================" << endl;
    cout << "Number of small rooms : " << small_rooms << endl;
    cout << "Number of large rooms : " << large_rooms << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Price per small room  : $" << price_per_small_room << endl;
    cout << "Price per large room  : $" << price_per_large_room << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cost (before tax)     : $" << subtotal << endl;
    cout << "Tax (6%)              : $" << tax_amount << endl;
    cout << "--------------------------------------------" << endl;
    cout << "TOTAL ESTIMATE        : $" << total_estimate << endl;
    cout << "This estimate is valid for " << estimate_validity_days << " days." << endl;
    cout << "=============================================" << endl;

    cout << "\nThank you for choosing SparkleClean!" << endl;
    cout << "We'll make your carpets look brand new again!" << endl;

    return 0;
}

/*
------------------------------------------------------------
Notes on Constants and Their Use in This Program
------------------------------------------------------------

1. **Purpose of Constants**
   - Constants represent values that do not change during program execution.
   - Declared with the `const` keyword.
   - Using constants improves readability, reduces errors, and makes maintenance easier.

2. **Types of Constants in C++**
   - **Literal constants**: directly written values (e.g., 25.0, 0.06, 30).
   - **Declared constants**: created using `const`, e.g., `const double tax_rate {0.06};`.
   - **Constant expressions (constexpr)**: evaluated at compile time for efficiency.
   - **Enumerated constants (enum)**: define related sets of integer constants.
   - **Defined constants (#define)**: legacy preprocessor approach (not preferred in modern C++).

3. **Why Use Constants Here**
   - The cost per room, tax rate, and validity period never change.
   - By defining them as constants:
     - The program is easier to modify later.
     - It prevents accidental changes during runtime.
     - The compiler can optimize code performance.

4. **Good Practices**
   - Use descriptive names for constants: e.g., `sales_tax_rate` instead of `tax`.
   - Write constants in uppercase or snake_case for clarity (e.g., `PRICE_PER_ROOM` or `price_per_room`).
   - Always prefer `const` or `constexpr` over `#define` for typed safety.

5. **Calculation Recap**
   - **Cost** = (small_rooms × price_per_small_room) + (large_rooms × price_per_large_room)
   - **Tax** = Cost × sales_tax_rate
   - **Total Estimate** = Cost + Tax

------------------------------------------------------------
Example Interaction:
------------------------------------------------------------
Welcome to SparkleClean Carpet Services
---------------------------------------------
Enter the number of SMALL rooms to clean: 3
Enter the number of LARGE rooms to clean: 1

================= ESTIMATE =================
Number of small rooms : 3
Number of large rooms : 1
Price per small room  : $25
Price per large room  : $35
Cost (before tax)     : $110
Tax (6%)              : $6.6
TOTAL ESTIMATE        : $116.6
This estimate is valid for 30 days.
=============================================
------------------------------------------------------------

In this example, you practiced:
- Declaring and using constants (`const`)
- Reading multiple user inputs (`cin`)
- Using basic arithmetic expressions
- Structuring clear and user-friendly console output
------------------------------------------------------------
*/