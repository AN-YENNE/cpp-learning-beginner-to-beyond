// Section 20,
// Class Template - Array

// Note: Since C++11, the STL provides std::array, a safer alternative to raw arrays.
// This example shows how you might implement your own template-based array class.

// Also demonstrates **non-type template parameters** (like `int N`).

#include <iostream>
#include <string>

// ----------- Template Class: Array<T, N> -----------
// T is the data type (e.g., int, double, string)
// N is a non-type template parameter: the size of the array, known at compile time
template <typename T, int N>
class Array {
    int size {N};           // Stores the size of the array
    T values[N];            // Array of fixed size N (must be known at compile time)

    // Friend function to enable direct printing of Array objects using << operator
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for (const auto &val : arr.values)
            os << val << " ";
        os << "]";
        return os;
    }

public:
    Array() = default;  // Default constructor (does not initialize values)

    // Constructor to initialize all elements to a specific value
    Array(T init_val) {
        for (auto &item : values)
            item = init_val;
    }

    // Method to fill array with a given value
    void fill(T val) {
        for (auto &item : values)
            item = val;
    }

    // Returns the size of the array (fixed at compile time)
    int get_size() const {
        return size;
    }

    // Overloaded subscript operator for indexing
    T &operator[](int index) {
        return values[index];
    }
};

int main() {
    std::cout << "----- Array<int, 5> without initialization -----" << std::endl;
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << "Initial values (uninitialized): " << nums << std::endl;

    std::cout << "\nFilling nums with 0..." << std::endl;
    nums.fill(0);
    std::cout << "nums after fill(0): " << nums << std::endl;

    std::cout << "\nFilling nums with 10..." << std::endl;
    nums.fill(10);
    std::cout << "nums after fill(10): " << nums << std::endl;

    std::cout << "\nModifying specific elements..." << std::endl;
    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << "nums after modification: " << nums << std::endl;

    std::cout << "\n----- Array<int, 100> with initialization to 1 -----" << std::endl;
    Array<int, 100> nums2 {1};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << "nums2: " << nums2 << std::endl;

    std::cout << "\n----- Array<std::string, 10> initialized to 'ANY' -----" << std::endl;
    Array<std::string, 10> strings(std::string{"ANY"});
    std::cout << "The size of strings is: " << strings.get_size() << std::endl;
    std::cout << "strings: " << strings << std::endl;

    std::cout << "\nChanging strings[0] to 'YAN'..." << std::endl;
    strings[0] = std::string{"YAN"};
    std::cout << "strings after modification: " << strings << std::endl;

    std::cout << "\nFilling strings with 'X'..." << std::endl;
    strings.fill(std::string{"X"});
    std::cout << "strings after fill: " << strings << std::endl;

    return 0;
}