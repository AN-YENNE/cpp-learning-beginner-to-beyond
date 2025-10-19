// Section 20
// Iterators in C++

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// ---------- Utility function to display a vector ----------
void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

// ---------- Iterator Basics ----------
void test1() {
    std::cout << "\n===== test1: Basic iterator usage with vector<int> =====" << std::endl;

    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();  // Iterator points to first element (1)
    std::cout << "it points to: " << *it << std::endl;

    it++;                     // Move to 2
    std::cout << "After it++, it points to: " << *it << std::endl;

    it += 2;                  // Move to 4 (skipping to 3rd next)
    std::cout << "After it += 2, it points to: " << *it << std::endl;

    it -= 2;                  // Move back to 2
    std::cout << "After it -= 2, it points to: " << *it << std::endl;

    it = nums1.end() - 1;     // Point to last element (5)
    std::cout << "Set it to end - 1, now it points to: " << *it << std::endl;
}

// ---------- Using iterator to traverse and modify ----------
void test2() {
    std::cout << "\n===== test2: Using iterator to read and write vector elements =====" << std::endl;

    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::cout << "Original vector elements:" << std::endl;
    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    std::cout << "Setting all elements to 0..." << std::endl;
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;  // Modify values via iterator
        it++;
    }

    std::cout << "Vector after modification: ";
    display(nums1);
}

// ---------- Const iterator: read-only access ----------
void test3() {
    std::cout << "\n===== test3: Using const_iterator for read-only traversal =====" << std::endl;

    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it1 = nums1.begin();
    std::cout << "Reading values with const_iterator:" << std::endl;
    while (it1 != nums1.end()) {
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;

    // Uncommenting this would cause compiler error:
    // *it1 = 0;  // ❌ Error: const_iterator cannot modify values
}

// ---------- Reverse iterators, map iterators, list iterators ----------
void test4() {
    std::cout << "\n===== test4: Reverse iterators, map iterators, list iterators =====" << std::endl;

    // --- Reverse iterator with vector ---
    std::vector<int> vec {1, 2, 3, 4};
    std::cout << "Reverse traversal of vector: ";
    auto it1 = vec.rbegin();
    while (it1 != vec.rend()) {
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;

    // --- Const reverse iterator with list ---
    std::list<std::string> name {"Larry", "Moe", "Curly"};
    std::cout << "Reverse traversal of list (using crbegin):" << std::endl;
    auto it2 = name.crbegin();
    std::cout << *it2 << std::endl;  // Curly
    it2++; 
    std::cout << *it2 << std::endl;  // Moe

    // --- Iterator over map ---
    std::map<std::string, std::string> favorites {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    std::cout << "Iterating over map (key-value pairs):" << std::endl;
    auto it3 = favorites.begin();
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }
}

// ---------- Iterating over a subset of a container ----------
void test5() {
    std::cout << "\n===== test5: Iterating over a subset of a vector =====" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin() + 2;       // Points to 3
    auto finish = vec.end() - 3;        // Points to 8

    std::cout << "Elements from 3 to 7: ";
    while (start != finish) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;
}

// ---------- Main driver ----------
int main() {
    test1();    // Basic iterator movement
    test2();    // Read/write via iterator
    test3();    // Const iterator
    test4();    // Reverse, list, and map iterators
    test5();    // Subset iteration
    return 0;
}
