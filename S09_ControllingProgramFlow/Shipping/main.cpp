// Section 9
// Shipping Cost Calculator
//
// This program calculates the cost of shipping a package based on its dimensions
// and volume. It demonstrates the use of conditional statements (if-else chains)
// and basic arithmetic logic in C++.
//
// Rules:
// - All dimensions must be <= 10 inches, or the package is rejected.
// - Base cost: $2.50
// - If volume > 100 cubic inches → add 10% surcharge.
// - If volume > 500 cubic inches → add 25% surcharge.

#include <iostream>
#include <iomanip>  // for std::setprecision
using namespace std;

int main() {
    // Declare dimensions and constants
    int length {}, width {}, height {};
    double base_cost {2.50};

    const int tier1_threshold {100};  // volume > 100 cubic inches = 10% surcharge
    const int tier2_threshold {500};  // volume > 500 cubic inches = 25% surcharge
    const int max_dimension_length {10};  // inches limit for each dimension

    const double tier1_surcharge {0.10};  // 10% surcharge
    const double tier2_surcharge {0.25};  // 25% surcharge

    cout << "================ Shipping Cost Calculator ================\n";
    cout << "Enter package dimensions (length width height) in inches: ";
    cin >> length >> width >> height;

    // Check if dimensions are within limits
    if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length) {
        cout << "\nSorry, package rejected - dimension exceeds " << max_dimension_length << " inches.\n";
    } else {
        // Calculate package volume
        int package_volume = length * width * height;
        double package_cost = base_cost;

        cout << "\nBase cost of shipping: $" << base_cost << endl;

        // Apply surcharges based on package volume
        if (package_volume > tier2_threshold) {
            package_cost += package_cost * tier2_surcharge;
            cout << "Applying tier 2 surcharge (25%) for large volume...\n";
        } else if (package_volume > tier1_threshold) {
            package_cost += package_cost * tier1_surcharge;
            cout << "Applying tier 1 surcharge (10%) for medium volume...\n";
        } else {
            cout << "No surcharge applied.\n";
        }

        // Display final results
        cout << fixed << setprecision(2); // display currency format
        cout << "----------------------------------------------------------\n";
        cout << "Package volume       : " << package_volume << " cubic inches\n";
        cout << "Final shipping cost  : $" << package_cost << endl;
        cout << "----------------------------------------------------------\n";
    }

    cout << "\nThank you for using the shipping calculator.\n";
    return 0;
}

/*
=====================================================================
NOTES AND CONCEPTS
=====================================================================

1. Overview:
------------
This example demonstrates conditional logic in practical use.
We calculate shipping cost based on user input (length, width, height),
compute volume, and apply surcharges according to thresholds.

2. Steps:
---------
1. Get dimensions from the user.
2. Check if all dimensions are <= 10 inches.
3. Compute volume = length * width * height.
4. Start with a base cost of $2.50.
5. If volume > 500 → add 25% surcharge.
   Else if volume > 100 → add 10% surcharge.
6. Display the calculated cost.

3. Key Concepts:
----------------
- **if / else-if / else** are used for decision branching.
- **const** variables make the code easier to adjust.
- **setprecision(2)** ensures currency format output (e.g., $2.50).
- Multiplying cost by (1 + surcharge) adjusts cost proportionally.

4. Example Runs:
----------------
Example 1:
Input: length=5, width=5, height=5
Volume = 125 → Tier 1 surcharge (10%)
Output: $2.75

Example 2:
Input: length=8, width=9, height=9
Volume = 648 → Tier 2 surcharge (25%)
Output: $3.13

Example 3:
Input: length=12, width=5, height=4
→ Rejected due to size limit.

5. Tips:
--------
✔ Always validate user input before processing.  
✔ Use named constants for thresholds and surcharges to avoid magic numbers.  
✔ The nested if-else structure ensures only one surcharge is applied.  
✔ For more accuracy, consider using double for volume in future versions.

6. Possible Enhancements:
-------------------------
- Add weight-based pricing.
- Support international rates (currency conversion).
- Allow multiple packages in a single run.
- Output formatted invoice summary.

=====================================================================
*/