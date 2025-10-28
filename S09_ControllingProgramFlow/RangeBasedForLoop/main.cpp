// Section 9
// Range-based For Loop
//
// This example demonstrates the use of range-based for loops in C++.
// Range-based for loops provide a simple and readable way to iterate over arrays,
// vectors, strings, or any container that supports iteration.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

    /************************************************************
     * 1) Example: Iterating over an array
     ************************************************************/
    int scores[] {10, 20, 30};

    cout << "Printing scores using a range-based for loop:" << endl;
    for (auto score : scores)
        cout << score << " ";
    cout << endl;


    /************************************************************
     * 2) Example: Calculating average temperature from a vector
     ************************************************************/
    vector<double> temperatures {87.9, 77.9, 80.0, 72.5};
    double total {};
    double average_temp {};

    for (auto temp : temperatures)
        total += temp;

    if (!temperatures.empty())
        average_temp = total / temperatures.size();

    cout << fixed << setprecision(1);
    cout << "\nAverage temperature from the recorded data: " << average_temp << "°F" << endl;


    /************************************************************
     * 3) Example: Iterating over an initializer list
     ************************************************************/
    cout << "\nDisplaying numbers from an initializer list: " << endl;
    for (auto val : {1, 2, 3, 4, 5})
        cout << val << " ";
    cout << endl;


    /************************************************************
     * 4) Example: Iterating over a string (skipping spaces)
     ************************************************************/
    cout << "\nDisplaying characters from a string (excluding spaces): " << endl;
    for (auto c : string("This is a test"))
        if (c != ' ')
            cout << c;
    cout << endl;


    /************************************************************
     * 5) Example: Replacing spaces with tabs when printing a string
     ************************************************************/
    cout << "\nReplacing spaces with tabs in the string:" << endl;
    for (auto c : string("This is a test"))
        if (c == ' ')
            cout << "\t";
        else
            cout << c;
    cout << endl;


    cout << "\nProgram completed successfully." << endl;
    return 0;
}

/*
=====================================================================
NOTES ON RANGE-BASED FOR LOOPS
=====================================================================

1. Overview:
-------------
The range-based for loop provides a more concise syntax to iterate over
collections like arrays, vectors, and strings.

Syntax:
    for (auto variable : collection)
        statement;

Example:
    int nums[] = {1, 2, 3, 4, 5};
    for (auto n : nums)
        cout << n << " ";

---------------------------------------------------------------------

2. Key Points:
--------------
- The `auto` keyword automatically deduces the type of the element.
- The loop variable holds a **copy** of the element by default.
- To modify elements directly, use a reference:
      for (auto &n : nums)
          n *= 2;  // modifies the original array/vector
- For read-only efficiency with large objects, use a const reference:
      for (const auto &n : nums)
          cout << n << " ";

---------------------------------------------------------------------

3. Comparison with Traditional for Loop:
----------------------------------------
Traditional:
    for (int i = 0; i < size; ++i)
        cout << nums[i] << endl;

Range-based:
    for (auto n : nums)
        cout << n << endl;

The range-based version eliminates index handling and reduces errors.

---------------------------------------------------------------------

4. Works With:
--------------
- Arrays
- STL containers (e.g., vector, list, map)
- Strings
- Initializer lists
- Any class implementing begin() and end() iterators

---------------------------------------------------------------------

5. Tips:
--------
✔ Use `auto` when type is obvious from context.  
✔ Use `const auto &` for read-only operations on large objects.  
✔ Use `auto &` when you need to modify the elements directly.  
✔ Avoid unnecessary copies for performance.

---------------------------------------------------------------------

6. Example Recap:
-----------------
- Printed elements of an integer array.
- Calculated average temperature using a vector.
- Displayed an initializer list.
- Demonstrated string character iteration and manipulation.

=====================================================================
*/