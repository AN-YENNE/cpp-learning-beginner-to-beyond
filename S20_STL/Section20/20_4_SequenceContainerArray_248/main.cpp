// Section 20
// Sequence Container: std::array and related STL algorithm examples

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate, etc.
#include <vector>   // for conversions when needed

// Display function for a fixed-size std::array<int, N>
// Note: The size (5) must be part of the signature
void display(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    for (const auto &i : arr)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

// ========== Test 1: Basic creation, assignment, indexing ==========
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};
    std::array<int, 5> arr2;  // default‑constructed; elements are uninitialized (for built-ins)

    std::cout << "Initial arr1: "; display(arr1);
    std::cout << "Initial arr2 (garbage): "; display(arr2);

    arr2 = {10, 20, 30, 40, 50};
    std::cout << "After arr2 = {10,20,30,40,50}:" << std::endl;
    std::cout << " arr1: "; display(arr1);
    std::cout << " arr2: "; display(arr2);

    std::cout << "Sizes: arr1.size() = " << arr1.size()
              << ", arr2.size() = " << arr2.size() << std::endl;

    // Access / modify elements
    arr1[0] = 1000;
    arr1.at(1) = 2000;  // .at() throws if out-of-range
    std::cout << "After modifications to arr1: "; display(arr1);

    std::cout << "arr2.front() = " << arr2.front()
              << ", arr2.back() = " << arr2.back() << std::endl;
}

// ========== Test 2: fill() and swap() ==========
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5> arr2 {10,20,30,40,50};

    std::cout << "Before fill & swap:" << std::endl;
    std::cout << " arr1: "; display(arr1);
    std::cout << " arr2: "; display(arr2);

    arr1.fill(0);
    std::cout << "After arr1.fill(0):" << std::endl;
    std::cout << " arr1: "; display(arr1);
    std::cout << " arr2: "; display(arr2);

    arr1.swap(arr2);
    std::cout << "After arr1.swap(arr2):" << std::endl;
    std::cout << " arr1: "; display(arr1);
    std::cout << " arr2: "; display(arr2);
}

// ========== Test 3: .data() and pointer access ==========
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};

    int *ptr = arr1.data();  // pointer to underlying array
    std::cout << "Pointer returned by data(): " << ptr << std::endl;
    *ptr = 10000;  // modify first element via pointer

    std::cout << "After *ptr = 10000:" << std::endl;
    display(arr1);
}

// ========== Test 4: Sorting the array ==========
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 4, 5, 3};
    std::cout << "Before sort: "; display(arr1);

    std::sort(arr1.begin(), arr1.end());
    std::cout << "After std::sort: "; display(arr1);
}

// ========== Test 5: Finding min and max elements ==========
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 4, 5, 3};

    auto min_it = std::min_element(arr1.begin(), arr1.end());
    auto max_it = std::max_element(arr1.begin(), arr1.end());
    std::cout << "Minimum element: " << *min_it
              << ", Maximum element: " << *max_it << std::endl;
}

// ========== Test 6: adjacent_find (detect consecutive duplicates) ==========
void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    std::array<int, 5> arr1 {2, 1, 3, 3, 5};

    auto adj = std::adjacent_find(arr1.begin(), arr1.end());
    if (adj != arr1.end())
        std::cout << "Adjacent duplicates found starting at value: " << *adj << std::endl;
    else
        std::cout << "No adjacent duplicates found" << std::endl;
}

// ========== Test 7: accumulate (sum of elements) ==========
void test7() {
    std::cout << "\nTest7 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};

    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of elements in arr1: " << sum << std::endl;
}

// ========== Test 8: count occurrences ==========
void test8() {
    std::cout << "\nTest8 =========================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};

    int cnt = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Number 3 appears " << cnt << " times" << std::endl;
}

// ========== Test 9: count_if with predicate ==========
void test9() {
    std::cout << "\nTest9 =========================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300, 400};

    // Count how many are >10 and <200
    int cnt = std::count_if(
        arr1.begin(), arr1.end(),
        [](int x) { return x > 10 && x < 200; });
    std::cout << "Found " << cnt << " elements between 10 and 200" << std::endl;
}

// ========== Additional Examples: using algorithms with std::array via conversion ==========
void extra_tests_array_algorithms() {
    std::cout << "\nExtra Tests on std::array (via conversion to vector) ===========" << std::endl;

    // Suppose we want to apply remove_if or copy_if, which modify or create containers
    std::array<int, 8> arr {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Original array: ";
    for (auto &v : arr) std::cout << v << " ";
    std::cout << "\n";

    // Convert std::array to vector for more flexible operations
    std::vector<int> v(arr.begin(), arr.end());

    // remove_if: remove values > 5
    auto new_end = std::remove_if(v.begin(), v.end(),
                                  [](int x) { return x > 5; });
    std::cout << "After std::remove_if (>5) (logical): ";
    for (auto &e : v) std::cout << e << " ";
    std::cout << "\n new_end index: " << (new_end - v.begin()) << std::endl;

    v.erase(new_end, v.end());
    std::cout << "After erase: ";
    for (auto &e : v) std::cout << e << " ";
    std::cout << "\n";

    // copy_if: pick even numbers
    std::vector<int> evens;
    std::copy_if(arr.begin(), arr.end(),
                 std::back_inserter(evens),
                 [](int x) { return x % 2 == 0; });
    std::cout << "Evens copied by std::copy_if: ";
    for (auto &e : evens) std::cout << e << " ";
    std::cout << "\n";

    // partition: move even to front, odd to back
    std::vector<int> v2(arr.begin(), arr.end());
    auto pivot = std::partition(v2.begin(), v2.end(),
                                [](int x) { return x % 2 == 0; });
    std::cout << "After partition (evens first): ";
    for (auto &e : v2) std::cout << e << " ";
    std::cout << "\nPivot index: " << (pivot - v2.begin()) << std::endl;
}

// ========== main ==========
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    extra_tests_array_algorithms();

    return 0;
}
