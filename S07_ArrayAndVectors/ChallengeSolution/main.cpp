/*  
    Section 7: Challenge - Vectors and 2D Vectors

    This challenge demonstrates:
    - Using vectors and 2D vectors in C++
    - Dynamic resizing with push_back()
    - Accessing elements safely using .at()
    - Observing how copies behave when nested inside 2D vectors

    ---------------------------------------------------------------
    Problem Description:
    --------------------
    1. Declare two 1D integer vectors: vector1 and vector2.
    2. Add elements dynamically using push_back().
    3. Display their contents and sizes.
    4. Declare a 2D vector (vector of vectors): vector_2d.
    5. Add vector1 and vector2 to vector_2d.
    6. Display elements of vector_2d.
    7. Modify vector1 and re-display vector_2d.
    8. Discuss behavior (copy vs reference semantics).
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    /************************************************************
     * Step 1: Declare two empty integer vectors
     ************************************************************/
    vector<int> vector1;
    vector<int> vector2;

    /************************************************************
     * Step 2: Add elements dynamically using push_back()
     ************************************************************/
    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\n=== Vector 1 Information ===" << endl;
    cout << "Elements of vector1:" << endl;
    cout << "Index 0: " << vector1.at(0) << endl;
    cout << "Index 1: " << vector1.at(1) << endl;
    cout << "vector1 currently contains " << vector1.size() << " elements." << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\n=== Vector 2 Information ===" << endl;
    cout << "Elements of vector2:" << endl;
    cout << "Index 0: " << vector2.at(0) << endl;
    cout << "Index 1: " << vector2.at(1) << endl;
    cout << "vector2 currently contains " << vector2.size() << " elements." << endl;

    /************************************************************
     * Step 3: Declare and initialize a 2D vector (vector of vectors)
     ************************************************************/
    vector<vector<int>> vector_2d;

    // Add copies of vector1 and vector2 into vector_2d
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\n=== 2D Vector (vector_2d) - Initial State ===" << endl;
    cout << "Row 0: " << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << "Row 1: " << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;

    /************************************************************
     * Step 4: Modify vector1 and observe the effect on vector_2d
     ************************************************************/
    cout << "\nUpdating vector1.at(0) to 1000..." << endl;
    vector1.at(0) = 1000;

    cout << "\n=== 2D Vector (vector_2d) After Modifying vector1 ===" << endl;
    cout << "Row 0: " << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << "Row 1: " << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;

    cout << "\n=== Vector 1 After Modification ===" << endl;
    cout << "Index 0: " << vector1.at(0) << endl;
    cout << "Index 1: " << vector1.at(1) << endl;
    cout << "vector1 still contains " << vector1.size() << " elements." << endl;

    /************************************************************
     * Step 5: Discussion - What happened?
     ************************************************************/
    cout << "\n=== Discussion ===" << endl;
    cout << "After changing vector1.at(0) to 1000, vector_2d did NOT change." << endl;
    cout << "Why? Because push_back() stored a COPY of vector1 and vector2 inside vector_2d." << endl;
    cout << "The 2D vector contains independent copies, not references to the originals." << endl;
    cout << "This behavior ensures each nested vector maintains its own data integrity." << endl;

    cout << "\nProgram complete!" << endl;

    cout << endl;
    return 0;
}

/*
=====================================================================
 NOTES, SUMMARY, AND TIPS ON VECTORS AND 2D VECTORS
=====================================================================

1️ Declaring Vectors:
   - Empty vector:
        vector<int> numbers;
   - Pre-sized with default values:
        vector<int> numbers(5);
   - Pre-sized and initialized:
        vector<int> numbers(5, 10);  // 5 elements, all 10
   - List initialization:
        vector<int> numbers {1, 2, 3, 4, 5};

2️ Adding Elements:
   - push_back(value): adds a new element to the end.
     Example:
        numbers.push_back(42);

3️ Accessing Elements:
   - operator[]:  fast, but unsafe (no bounds check)
   - at(index):   safe, throws std::out_of_range if invalid
   - size():      returns current number of elements
   - front(), back(): access first and last element

4️ Changing Elements:
   - You can modify elements using:
        numbers.at(0) = 99;
        numbers[1] = 88;

5️ 2D Vectors (vector of vectors):
   - A 2D vector stores vectors inside another vector:
        vector<vector<int>> matrix;
        matrix.push_back({1, 2});
        matrix.push_back({3, 4, 5});
   - Access with .at(row).at(column)
   - Each row can have a different size (jagged arrays allowed).

6️ Copy vs Reference Behavior:
   - When you push_back() a vector into another vector, 
     a **copy** of that vector is created.
   - Later modifications to the original vector will NOT affect
     the copy inside the 2D vector.

     Example:
        vector<int> v1 {10, 20};
        vector<vector<int>> v2d;
        v2d.push_back(v1);   // a copy of v1 is made
        v1.at(0) = 1000;     // this change does NOT affect v2d

7️ Displaying 2D Vectors:
   - Nested loops are often used:
        for (size_t i = 0; i < matrix.size(); ++i)
            for (size_t j = 0; j < matrix.at(i).size(); ++j)
                cout << matrix.at(i).at(j) << " ";

8️ Tips:
   - Use .at() when learning for safety.
   - Use [] for speed once confident about index validity.
   - Use const auto& when printing to avoid copying elements.
   - 2D vectors can dynamically grow both in rows and columns.
   - Remember: push_back() creates copies unless you move them
       using std::move().

9️ Common Pitfall:
   - Forgetting that push_back makes copies.
     Modifying the original after adding to a 2D vector doesn’t change the stored copy.

=====================================================================
 Summary:
=====================================================================
- Vectors are resizable arrays.
- push_back() dynamically adds elements.
- at() provides safe access.
- A 2D vector (vector of vectors) can model grids or tables.
- push_back() copies data, not references.
=====================================================================
*/
