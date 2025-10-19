// Section 20 - Sets
// Demonstrating std::set with primitives and custom classes

#include <iostream>     // for std::cout, std::cin
#include <set>          // for std::set container
#include <string>       // for std::string

// ==============================
// Person class with operator< and operator==
// ==============================
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age)
        : name{name}, age{age} {}

    // Used by std::set for sorting and uniqueness
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;  // Set will compare only by age!
    }

    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Output formatting for Person
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// ==============================
// Display utility for sets
// ==============================
template <typename T>
void display(const std::set<T> &s) {
    std::cout << "[ ";
    for (const auto &elem : s)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

// ==============================
// Test 1: Basic set operations with ints
// ==============================
void test1() {
    std::cout << "\nTest1 - std::set<int> basic operations" << std::endl;

    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1);  // auto sorted

    s1 = {1,2,3,1,1,2,2,3,3,4,5};  // Duplicates ignored
    display(s1);

    std::cout << "Inserting 0 and 10 into set..." << std::endl;
    s1.insert(0);
    s1.insert(10);
    display(s1);

    std::cout << (s1.count(10) ? "10 is in the set" : "10 is NOT in the set") << std::endl;

    auto it = s1.find(5);
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;

    std::cout << "Clearing set..." << std::endl;
    s1.clear();
    display(s1);
}

// ==============================
// Test 2: Set of custom objects (Person)
// ==============================
void test2() {
    std::cout << "\nTest2 - std::set<Person>" << std::endl;

    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);

    std::cout << "Emplacing James:50 (unique age)" << std::endl;
    stooges.emplace("James", 50);
    display(stooges);

    std::cout << "Emplacing Frank:50 (age already exists)" << std::endl;
    stooges.emplace("Frank", 50);  // Won't be added
    display(stooges);

    std::cout << "Erasing Moe:2..." << std::endl;
    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);

    std::cout << "Trying to erase Person(\"XXXX\", 50) — matches James due to age..." << std::endl;
    it = stooges.find(Person{"XXXX", 50});  // Will match by age only!
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);
}

// ==============================
// Test 3: Insert return values (std::pair)
// ==============================
void test3() {
    std::cout << "\nTest3 - Insert result from std::set<std::string>" << std::endl;

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    std::cout << "Inserting 'D'..." << std::endl;
    auto result = s.insert("D");
    display(s);
    std::cout << std::boolalpha;
    std::cout << "Inserted value: " << *(result.first) << ", success: " << result.second << std::endl;

    std::cout << "Inserting 'A' again..." << std::endl;
    result = s.insert("A");  // Already exists
    display(s);
    std::cout << "Inserted value: " << *(result.first) << ", success: " << result.second << std::endl;
}

// ==============================
// Main
// ==============================
int main() {
    test1();
    test2();
    test3();
    return 0;
}
