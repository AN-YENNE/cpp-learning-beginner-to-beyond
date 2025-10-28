// Section 9 Nested Loops - Histogram Example
//
// This program demonstrates how nested loops can be used
// to visualize numeric data as a simple horizontal histogram.
//
// Each number entered by the user is represented as a sequence
// of '-' and '*' characters, where every 5th position is marked with a '*'. This helps visualize scale or grouping.

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int num_items {};
    cout << "How many data items do you have? ";
    cin >> num_items;

    vector<int> data {};   // will store user-provided data values

    // Outer loop: input collection
    for (int i {1}; i <= num_items; ++i) {
        int data_item {};
        cout << "Enter data item " << i << ": ";
        cin >> data_item;
        data.push_back(data_item);
    }

    cout << "\nDisplaying Histogram:\n";
    cout << "Each '-' represents 1 unit. Every 5th unit is marked with '*'.\n";
    cout << "----------------------------------------------------------\n";

    // Outer loop: iterate through each data value
    for (auto val : data) {
        // Inner loop: print symbols based on the value
        for (int i {1}; i <= val; ++i) {
            if (i % 5 == 0)
                cout << "*";   // mark every 5th step
            else
                cout << "-";   // otherwise mark with a dash
        }
        cout << " (" << val << ")" << endl;  // show numeric label for clarity
    }

    cout << "\nHistogram complete. Thank you!\n";
    return 0;
}

/*
=====================================================================
NOTES ON NESTED LOOPS
=====================================================================

1. Overview:
-------------
A nested loop is a loop inside another loop.
The inner loop runs completely for each iteration of the outer loop.

Example:
    for (int i = 1; i <= 3; ++i) {          // outer loop
        for (int j = 1; j <= 5; ++j) {      // inner loop
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }

Output:
(1,1) (1,2) (1,3) (1,4) (1,5)
(2,1) (2,2) (2,3) (2,4) (2,5)
(3,1) (3,2) (3,3) (3,4) (3,5)

---------------------------------------------------------------------

2. How This Example Works:
--------------------------
- The outer loop goes through each data value (user input).
- For each value, the inner loop runs as many times as the number indicates.
- Inside the inner loop, we print:
    - '*' every 5th unit
    - '-' otherwise
- After completing one data item’s pattern, we print a newline.

---------------------------------------------------------------------

3. Sample Run:
--------------
How many data items do you have? 3
Enter data item 1: 5
Enter data item 2: 9
Enter data item 3: 12

Displaying Histogram:
Each '-' represents 1 unit. Every 5th unit is marked with '*'.
----------------------------------------------------------
----* (5)
----*----* (9)
----*----*---* (12)

---------------------------------------------------------------------

4. Tips:
--------
✔ Nested loops multiply execution count:
   - If outer runs N times and inner runs M times,
     total iterations = N × M.
✔ Avoid unnecessary nesting — can cause performance issues.
✔ Perfect for grid, pattern, or matrix-based problems.
✔ Use meaningful loop counters and indentation for readability.

---------------------------------------------------------------------

5. Summary:
-----------
- Nested loops let us process multi-level structures.
- Ideal for tasks like:
    - Drawing patterns or histograms
    - Working with matrices (2D arrays)
    - Comparing all pairs of elements
- Keep loops clean, labeled, and visually aligned.

=====================================================================
*/
