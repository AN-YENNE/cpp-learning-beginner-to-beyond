// Section 20
// Sequence Container: std::vector with STL algorithm examples

#include <iostream>
#include <vector>
#include <algorithm>  // for sort, copy, transform, etc.
#include <string>

// A simple Person class to let us store non-primitive types in vector
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Overload << so we can print Person directly
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// Display vector<int> using for_each + lambda
void display2(const std::vector<int> &vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
        [](int x) { std::cout << x << " "; });
    std::cout << "]" << std::endl;
}

// Generic template display that works for vector<T> (if T supports <<)
template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::cout << "Initial vector (using display): ";
    display(vec);

    vec = {2, 4, 5, 6};
    std::cout << "After assignment with initializer list (using display2): ";
    display2(vec);

    std::vector<int> vec1(10, 100);  // ten copies of 100
    std::cout << "Vector constructed with count + value: ";
    display(vec1);
}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};

    std::cout << "vec: "; display(vec);
    std::cout << "size: " << vec.size()
              << ", max_size: " << vec.max_size()
              << ", capacity: " << vec.capacity() << std::endl;

    vec.push_back(6);
    std::cout << "After push_back(6): ";
    display(vec);
    std::cout << "size: " << vec.size()
              << ", capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit(): ";
    display(vec);
    std::cout << "capacity: " << vec.capacity() << std::endl;

    vec.reserve(100);
    std::cout << "After reserve(100): ";
    display(vec);
    std::cout << "capacity: " << vec.capacity() << std::endl;
}

void test3() {
    std::cout << "\nTest3 =========================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::cout << "Before modification: ";
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;  // bounds-checked
    std::cout << "After vec[0] = 100; vec.at(1) = 200: ";
    display(vec);
}

void test4() {
    std::cout << "\nTest4 =========================" << std::endl;
    std::vector<Person> stooges;
    std::cout << "Initially: ";
    display(stooges);

    Person p1 {"Larry", 18};
    stooges.push_back(p1);
    std::cout << "After push_back Larry: ";
    display(stooges);

    stooges.push_back(Person{"Moe", 25});
    std::cout << "After push_back Moe: ";
    display(stooges);

    stooges.emplace_back("Curly", 30);  // construct in place
    std::cout << "After emplace_back Curly: ";
    display(stooges);
}

void test5() {
    std::cout << "\nTest5 =========================" << std::endl;
    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    std::cout << "Stooges: ";
    display(stooges);

    std::cout << "Front: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;

    stooges.pop_back();
    std::cout << "After pop_back(): ";
    display(stooges);
}

void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    display(vec);

    vec.clear();
    std::cout << "After clear(): ";
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Refilled: ";
    display(vec);

    vec.erase(vec.begin(), vec.begin() + 2);
    std::cout << "After erase first two elements: ";
    display(vec);

    // Erase all even numbers (careful with iterator invalidation)
    vec = {1,2,3,4,5,6,7,8,9,10};
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            it = vec.erase(it);  // erase returns next valid iterator
        } else {
            ++it;
        }
    }
    std::cout << "After removing all even numbers: ";
    display(vec);
}

void test7() {
    std::cout << "\nTest7 =========================" << std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};

    std::cout << "Before swap:" << std::endl;
    std::cout << " vec1: "; display(vec1);
    std::cout << " vec2: "; display(vec2);

    vec2.swap(vec1);

    std::cout << "After swap:" << std::endl;
    std::cout << " vec1: "; display(vec1);
    std::cout << " vec2: "; display(vec2);
}

void test8() {
    std::cout << "\nTest8 =========================" << std::endl;
    std::vector<int> vec1 {1, 21, 3, 40, 12};
    std::cout << "Before sort: ";
    display(vec1);

    std::sort(vec1.begin(), vec1.end());
    std::cout << "After sort: ";
    display(vec1);
}

void test9() {
    std::cout << "\nTest9 =========================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20};

    std::cout << "Before copy:" << std::endl;
    std::cout << " vec1: "; display(vec1);
    std::cout << " vec2: "; display(vec2);

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    std::cout << "After std::copy (append vec1 to vec2):" << std::endl;
    std::cout << " vec2: "; display(vec2);

    // Now test copy_if (e.g. copy even numbers)
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10, 20};

    std::cout << "\nCopy only even numbers from vec1 to vec2:" << std::endl;
    std::cout << " vec1: "; display(vec1);
    std::cout << " vec2: "; display(vec2);

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
        [](int x) { return x % 2 == 0; });

    std::cout << "After copy_if (even numbers):" << std::endl;
    std::cout << " vec2: "; display(vec2);
}

void test10() {
    std::cout << "\nTest10 =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;

    // Multiply pairs elementwise: 1*10, 2*20, etc.
    std::transform(vec1.begin(), vec1.end(),
                   vec2.begin(),
                   std::back_inserter(vec3),
                   [](int x, int y) { return x * y; });

    std::cout << "Result of elementwise multiplication (vec3): ";
    display(vec3);
}

void test11() {
    std::cout << "\nTest11 =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100, 200, 300, 400};

    std::cout << "Before insertion:" << std::endl;
    std::cout << " vec1: "; display(vec1);
    std::cout << " vec2: "; display(vec2);

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout << "Inserting vec2 before 5 in vec1" << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Value 5 not found in vec1" << std::endl;
    }

    std::cout << "After insertion: ";
    display(vec1);
}

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
    test10();
    test11();

    return 0;
}
