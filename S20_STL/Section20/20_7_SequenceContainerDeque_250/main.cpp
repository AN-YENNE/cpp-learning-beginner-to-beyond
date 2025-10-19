// Section 20 - Sequence Container: std::deque with STL algorithms
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>  // For std::copy, std::front_inserter, std::back_inserter

// Templated display function to print any std::deque
template <typename T>
void display(const std::deque<T> &d) {
    std::cout << "[ ";
    for (const auto &elem : d)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

// Basic construction and element access
void test1() {
    std::cout << "\nTest1 - Basic Initialization and Access ==============" << std::endl;

    std::deque<int> d {1,2,3,4,5};  // initialize deque with 5 elements
    std::cout << "Initial deque: ";
    display(d);

    d = {2,4,5,6};  // reassign using initializer list
    std::cout << "Reassigned deque: ";
    display(d);

    std::deque<int> d1(10, 100);  // 10 elements, each initialized to 100
    std::cout << "Deque with 10 copies of 100: ";
    display(d1);

    // Element access
    d[0] = 100;
    d.at(1) = 200;  // bounds-checked access
    std::cout << "After modifying elements at index 0 and 1: ";
    display(d);
}

// Demonstrating push_front, push_back, pop_front, pop_back
void test2() {
    std::cout << "\nTest2 - Front/Back Push/Pop Operations ==============" << std::endl;

    std::deque<int> d {0,0,0};
    std::cout << "Start deque: ";
    display(d);

    d.push_back(10);
    d.push_back(20);
    std::cout << "After push_back(10) and push_back(20): ";
    display(d);

    d.push_front(100);
    d.push_front(200);
    std::cout << "After push_front(100) and push_front(200): ";
    display(d);

    // Front/Back access
    std::cout << "Front element: " << d.front() << std::endl;
    std::cout << "Back element: " << d.back() << std::endl;
    std::cout << "Size of deque: " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    std::cout << "After pop_back() and pop_front(): ";
    display(d);
}

// Conditional insertion into front/back based on element value
void test3() {
    std::cout << "\nTest3 - Insert Odd to Front, Even to Back ==============" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    for (const auto &elem : vec) {
        if (elem % 2 == 0)
            d.push_back(elem);  // even numbers go to back
        else
            d.push_front(elem); // odd numbers go to front
    }

    std::cout << "Deque with odd in front and even at back: ";
    display(d);
}

// Show difference between push_front and push_back order
void test4() {
    std::cout << "\nTest4 - Push Front vs Push Back Order ==============" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    for (const auto &elem : vec) {
        d.push_front(elem);  // Reversed order
    }
    std::cout << "After push_front (reversed order): ";
    display(d);

    d.clear();  // empty the deque

    for (const auto &elem : vec) {
        d.push_back(elem);  // Original order
    }
    std::cout << "After push_back (original order): ";
    display(d);
}

// Same as test4, but using std::copy and inserters
void test5() {
    std::cout << "\nTest5 - std::copy with Front and Back Inserters ==============" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    std::copy(vec.begin(), vec.end(), std::front_inserter(d));  // reverse order
    std::cout << "After std::copy with front_inserter (reversed): ";
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(d));   // original order
    std::cout << "After std::copy with back_inserter (original): ";
    display(d);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
