// Section 7 Arrays
//
// This program demonstrates how arrays work in C++.
// You’ll learn how to declare, initialize, access, modify, and display array elements.
// Arrays are fixed-size collections of elements of the same data type.

#include <iostream>
using namespace std;

int main() {

    /**********************************************
     * 1. Declaring and Initializing Character Arrays
     **********************************************/
    char vowels[] {'a', 'e', 'i', 'o', 'u'};   // size automatically deduced

    cout << "\n=== Vowels Array Example ===" << endl;
    cout << "The first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl;

    // Warning: Accessing beyond array bounds (like vowels[5]) is undefined behavior.
    // It may crash your program or print garbage values.

    /**********************************************
     * 2. Working with Floating Point Arrays
     **********************************************/
    double hi_temps[] {90.1, 89.8, 77.5, 81.6};
    cout << "\n=== Temperature Array Example ===" << endl;
    cout << "The first high temperature is: " << hi_temps[0] << " degrees." << endl;

    // Modify an element in the array
    hi_temps[0] = 100.7; // assigning a new value to index 0
    cout << "The first high temperature is now updated to: " << hi_temps[0] << " degrees." << endl;

    /**********************************************
     * 3. Integer Array Example with User Input
     **********************************************/
    int test_scores[] {100, 90, 80, 70, 60};

    cout << "\n=== Test Scores Array Example ===" << endl;
    cout << "Initial scores:" << endl;
    cout << "Index 0: " << test_scores[0] << endl;
    cout << "Index 1: " << test_scores[1] << endl;
    cout << "Index 2: " << test_scores[2] << endl;
    cout << "Index 3: " << test_scores[3] << endl;
    cout << "Index 4: " << test_scores[4] << endl;

    // Prompt user to modify array contents
    cout << "\nPlease enter 5 new test scores separated by spaces: ";
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];

    cout << "\nUpdated scores:" << endl;
    cout << "Index 0: " << test_scores[0] << endl;
    cout << "Index 1: " << test_scores[1] << endl;
    cout << "Index 2: " << test_scores[2] << endl;
    cout << "Index 3: " << test_scores[3] << endl;
    cout << "Index 4: " << test_scores[4] << endl;

    /**********************************************
     * 4. Array Indexing
     **********************************************/
    cout << "\n=== Array Indexing Concept ===" << endl;
    cout << "Arrays use zero-based indexing." << endl;
    cout << "That means index 0 is the first element, and index 4 is the fifth element." << endl;
    cout << "Example: test_scores[0] = " << test_scores[0] << " (first score)" << endl;

    /**********************************************
     * 5. Array Bounds and Safety
     **********************************************/
    cout << "\n=== Array Bounds Warning ===" << endl;
    cout << "If you access an index outside the range (like test_scores[5])," << endl;
    cout << "C++ won’t stop you, but it will cause UNDEFINED BEHAVIOR!" << endl;
    cout << "Always ensure your index is between 0 and (size - 1)." << endl;

    /**********************************************
     * 6. Printing Array Names (Memory Addresses)
     **********************************************/
    cout << "\n=== Array Name Value ===" << endl;
    cout << "When you print an array name, you see its memory address:" << endl;
    cout << "test_scores (as address): " << test_scores << endl;
    cout << "This is the address of the first element (test_scores[0])." << endl;

    /**********************************************
     * 7. Finding Array Size and Looping
     **********************************************/
    cout << "\n=== Array Size and Loop Example ===" << endl;
    int array_size = sizeof(test_scores) / sizeof(test_scores[0]);
    cout << "Number of elements in test_scores array: " << array_size << endl;

    cout << "Printing all test scores using a loop:" << endl;
    for (int i = 0; i < array_size; ++i) {
        cout << "Index " << i << ": " << test_scores[i] << endl;
    }

    cout << "\nProgram complete! Arrays are powerful when used safely." << endl;
    cout << endl;
    return 0;
}

/*
==============================================================
Notes on Arrays in C++
==============================================================

1. Declaring Arrays:
   - Arrays store multiple values of the same type.
   Example:
   int numbers[5];  // declares an array with 5 integers

2. Initializing Arrays:
   - Arrays can be initialized at declaration.
   Example:
   int values[3] {10, 20, 30};
   char letters[] {'A', 'B', 'C'};

3. Accessing and Modifying Elements:
   - Use index positions to access or modify elements.
   Example:
   numbers[0] = 99;       // modify first element
   cout << numbers[2];    // print third element

4. Array Indexing:
   - Arrays are **zero-indexed**.
   - First element is index 0, last element is (size - 1).

5. Array Bounds:
   - C++ does **not check** if the index is valid.
   - Accessing out-of-range indices leads to **undefined behavior**.
   Example:
   int data[5];
   data[5] = 100;  // ERROR! Out of bounds.

6. Printing Array Names:
   - Printing the array name (e.g., cout << numbers) prints its **memory address**.
   - Arrays “decay” into pointers in expressions.

7. Finding Array Size:
   - Use sizeof to compute total elements:
     ```cpp
     int arr[] {10, 20, 30, 40};
     int size = sizeof(arr) / sizeof(arr[0]);
     ```
   - Useful when iterating through arrays in loops.

*/
