// Section 9 Menu-Driven Vector Challenge
//
// This program maintains a list of integers and lets the user choose actions
// from a simple text menu. It demonstrates:
// - std::vector for dynamic lists
// - do-while loop for repeating the menu until the user quits
// - if / else-if chains for selection logic
// - basic aggregation (mean), min and max scans
//
// Notes for learners:
// 1) A vector grows as we push_back elements. No need to predefine its size.
// 2) We use do-while so the menu shows at least once and keeps showing until 'Q'.
// 3) We accept both uppercase and lowercase menu choices for convenience.
// 4) We always check for empty vector before computing mean/min/max to avoid errors.

#include <iostream>
#include <vector>
#include <limits>   // for std::numeric_limits
using namespace std;

int main() {

    vector<int> numbers {};     // our dynamic list of integers starts empty
    char selection {};          // holds the user's menu choice each loop

    // Helper lambda to safely read an int (clears bad input and reprompts)
    auto safe_read_int = []() -> int {
        int value {};
        while (!(cin >> value)) {
            cout << "Input was not a valid integer. Please try again: ";
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
        }
        return value;
    };

    do {
        // Display the menu every iteration
        cout << "\n==================== Number List Menu ====================" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> selection;

        // Normalize nothing; we will compare both cases explicitly.
        // Each branch below explains its steps with brief comments.

        if (selection == 'P' || selection == 'p') {
            // Print the current list contents
            if (numbers.empty()) {
                cout << "[] - the list is empty" << endl;
            } else {
                cout << "[ ";
                for (int n : numbers)
                    cout << n << " ";
                cout << "]" << endl;
            }

        } else if (selection == 'A' || selection == 'a') {
            // Add a new number to the list
            cout << "Enter an integer to add to the list: ";
            int num_to_add = safe_read_int();
            numbers.push_back(num_to_add);
            cout << num_to_add << " added to the list." << endl;

        } else if (selection == 'M' || selection == 'm') {
            // Compute and display the arithmetic mean
            if (numbers.empty()) {
                cout << "Unable to calculate the mean - no data." << endl;
            } else {
                long long total {0}; // long long to reduce overflow risk for many elements
                for (int n : numbers)
                    total += n;
                double mean = static_cast<double>(total) / numbers.size();
                cout << "Mean (average) of " << numbers.size() << " number(s) is " << mean << endl;
            }

        } else if (selection == 'S' || selection == 's') {
            // Find and display the smallest element
            if (numbers.empty()) {
                cout << "Unable to determine the smallest number - list is empty." << endl;
            } else {
                int smallest = numbers.at(0);
                for (int n : numbers)
                    if (n < smallest)
                        smallest = n;
                cout << "The smallest number is: " << smallest << endl;
            }

        } else if (selection == 'L' || selection == 'l') {
            // Find and display the largest element
            if (numbers.empty()) {
                cout << "Unable to determine the largest number - list is empty." << endl;
            } else {
                int largest = numbers.at(0);
                for (int n : numbers)
                    if (n > largest)
                        largest = n;
                cout << "The largest number is: " << largest << endl;
            }

        } else if (selection == 'Q' || selection == 'q') {
            // Exit the program
            cout << "Goodbye. Thanks for using the number list menu." << endl;

        } else {
            // Any other letter is invalid; prompt again
            cout << "Unknown selection, please try again." << endl;
            // Clean any stray input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (selection != 'q' && selection != 'Q');

    cout << endl;
    return 0;
}

/*
====================================================
Summary and Tips
====================================================
- Printing: Iterate and format as [ a b c ] for readability.
- Adding: Use vector::push_back to append elements.
- Mean: Sum all elements and divide by the count. Cast to double to avoid integer division.
- Smallest/Largest: Scan through the list and track the current min/max.
- Input safety: When reading integers, clear bad input states to prevent infinite loops.

Possible Extensions (practice ideas):
- Search for a number and report how many times it appears.
- Clear the entire list via numbers.clear().
- Prevent duplicates by checking before push_back.
- Sort the list before printing.
- Persist the list to a file and load it when the program starts.

Loop Choice:
- do-while is convenient for menus because it runs at least once,
  then repeats until the user chooses to quit.

Selection Logic:
- Here we used if / else-if, but switch on toupper(selection) is also an option.
*/ 