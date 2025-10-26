// Section 7 Vectors
//
// This program demonstrates how std::vector works in C++.
// You will see how to declare, initialize, access, modify, grow, and
// safely index vectors, including a 2D vector example.
//
// Key ideas covered in code comments and at the end:
// - Declaring vectors with and without initial values
// - Access via [] and .at()
// - size(), push_back(), bounds checking, and exceptions
// - 2D vectors (vector of vectors)

#include <iostream>
#include <vector>   // Required to use std::vector
using namespace std;

int main() {
    /************************************************************
     * 1) Declaring and Initializing Vectors
     ************************************************************/
    // Various ways to declare vectors:
    // vector<char> vowels;            // empty
    // vector<char> vowels(5);         // size 5, default-initialized ('\0' for char)
    vector<char> vowels {'a', 'e', 'i', 'o', 'u'}; // list-initialized with 5 vowels

    cout << "\n=== Vowels Vector Example ===" << endl;
    cout << "First vowel (vowels[0]): " << vowels[0] << endl;  // operator[] (no bounds check)
    cout << "Last vowel  (vowels[4]): " << vowels[4] << endl;

    /************************************************************
     * 2) Integer Vector: Access via [] and .at()
     ************************************************************/
    // vector<int> test_scores(3);       // size 3, default-initialized to 0
    // vector<int> test_scores(3, 100);  // size 3, each element = 100
    vector<int> test_scores {100, 98, 89};  // list-initialized with three values

    cout << "\n=== Test Scores (array-style syntax) ===" << endl;
    cout << "Score 0 (test_scores[0]): " << test_scores[0] << endl;
    cout << "Score 1 (test_scores[1]): " << test_scores[1] << endl;
    cout << "Score 2 (test_scores[2]): " << test_scores[2] << endl;

    cout << "\n=== Test Scores (vector .at() syntax) ===" << endl;
    cout << "Score 0 (test_scores.at(0)): " << test_scores.at(0) << endl;
    cout << "Score 1 (test_scores.at(1)): " << test_scores.at(1) << endl;
    cout << "Score 2 (test_scores.at(2)): " << test_scores.at(2) << endl;

    cout << "\nCurrent number of scores (test_scores.size()): " << test_scores.size() << endl;

    /************************************************************
     * 3) Updating Elements Safely with .at()
     ************************************************************/
    cout << "\nEnter 3 test scores (will overwrite existing values): ";
    cin  >> test_scores.at(0);
    cin  >> test_scores.at(1);
    cin  >> test_scores.at(2);

    cout << "\nUpdated test scores are:" << endl;
    cout << "Score 0: " << test_scores.at(0) << endl;
    cout << "Score 1: " << test_scores.at(1) << endl;
    cout << "Score 2: " << test_scores.at(2) << endl;

    /************************************************************
     * 4) Growing a Vector with push_back()
     ************************************************************/
    cout << "\nEnter a new test score to append to the vector: ";
    int score_to_add {0};
    cin >> score_to_add;
    test_scores.push_back(score_to_add);  // vector grows automatically

    cout << "Enter one more test score to append to the vector: ";
    cin >> score_to_add;
    test_scores.push_back(score_to_add);

    cout << "\nAfter appending two scores, the vector contains:" << endl;
    cout << "Score 0: " << test_scores.at(0) << endl;
    cout << "Score 1: " << test_scores.at(1) << endl;
    cout << "Score 2: " << test_scores.at(2) << endl;
    cout << "Score 3: " << test_scores.at(3) << endl; // newly added
    cout << "Score 4: " << test_scores.at(4) << endl; // newly added
    cout << "Total number of scores (size): " << test_scores.size() << endl;

    // Example of bounds checking:
    // Uncommenting the next line will throw an exception if index is invalid.
    // cout << "Accessing out of range: " << test_scores.at(10) << endl;

    /************************************************************
     * 5) 2D Vector (Vector of Vectors)
     ************************************************************/
    vector<vector<int>> movie_ratings {
        {1, 2, 3, 4},  // Reviewer 0
        {1, 2, 4, 4},  // Reviewer 1
        {1, 3, 4, 5}   // Reviewer 2
    };

    cout << "\n=== 2D Vector: Movie Ratings ===" << endl;
    cout << "Reviewer 0 ratings using array-style syntax: ";
    cout << movie_ratings[0][0] << " "
         << movie_ratings[0][1] << " "
         << movie_ratings[0][2] << " "
         << movie_ratings[0][3] << endl;

    cout << "Reviewer 0 ratings using .at() syntax:       ";
    cout << movie_ratings.at(0).at(0) << " "
         << movie_ratings.at(0).at(1) << " "
         << movie_ratings.at(0).at(2) << " "
         << movie_ratings.at(0).at(3) << endl;

    cout << "\nVector demo complete. Explore safely growing and indexing vectors!" << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
NOTES, SUMMARY, AND TIPS (Vectors)
=====================================================================

1) What is a std::vector?
   - A vector is a dynamic array that can grow and shrink at runtime.
   - It manages memory for you and stores elements contiguously (like arrays).

2) Declaring and Initializing
   - Empty:           vector<int> v;
   - Fixed size:      vector<int> v(5);          // 5 elements, default-initialized
   - Fixed size + val vector<int> v(5, 42);      // 5 elements, each 42
   - List init:       vector<int> v {1, 2, 3};   // initialize with 1, 2, 3

3) Accessing Elements
   - operator[]:  v[0]  // fast, NO bounds check
   - at():        v.at(0) // throws std::out_of_range on invalid index
   - size():      v.size() // number of elements currently in the vector
   - front()/back(): v.front(), v.back() // first and last element

4) Modifying and Growing
   - push_back(x): append an element to the end (vector grows as needed)
   - pop_back():   remove the last element
   - clear():      remove all elements (size becomes 0)
   - insert/erase: insert or erase at positions (O(n) operations)
   - assign():     replace contents with a count/value or iterator range

5) Capacity vs Size
   - size():     how many elements are actually stored
   - capacity(): how many elements can be stored without reallocating
   - reserve(n): request capacity for at least n elements (optional performance optimization)
   - shrink_to_fit(): request to reduce capacity to fit size (non-binding)

6) Bounds and Safety
   - operator[] does not perform bounds checking; using it with invalid indices is undefined behavior.
   - at() performs bounds checking and throws std::out_of_range on invalid indices.
   - Prefer .at() while learning; switch to [] when you need absolute performance and you know indices are valid.

7) Iterating
   - Index-based:
       for (size_t i = 0; i < v.size(); ++i) { cout << v[i]; }
   - Range-based:
       for (const auto& x : v) { cout << x; }
   - Iterators:
       for (auto it = v.begin(); it != v.end(); ++it) { cout << *it; }

8) 2D Vectors (vector<vector<T>>)
   - A vector of vectors can represent tables or matrices.
   - Access via v[row][col] or v.at(row).at(col) for checked access.
   - Inner vectors can have different sizes (jagged arrays).

9) Performance Tips
   - Use reserve() if you know approximately how many elements you will push_back, to reduce reallocations.
   - In critical code, prefer move semantics where possible (push_back(std::move(x))).
   - Avoid frequent insertions/erasures in the middle of large vectors (consider deque/list for those patterns).

10) Common Pitfalls
   - Using invalid indices (off-by-one errors). Always ensure 0 <= index < v.size().
   - Assuming .size() and .capacity() behave the same — they do not.
   - Forgetting to include <vector>.

Summary:
- std::vector is the go-to dynamic sequence container in C++.
- Learn to use size(), push_back(), and .at() safely.
- For 2D data, vector<vector<T>> is flexible and easy to work with.

*/
