// Section 20 - Priority Queue Demo
// Demonstrates std::priority_queue with primitive and custom types

#include <iostream>     // std::cout, std::endl
#include <queue>        // std::priority_queue
#include <string>       // std::string

// ====================
// Custom Person class
// ====================
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age} {}

    // Priority based on name (alphabetical order)
    bool operator<(const Person &rhs) const {
        return this->name < rhs.name; // Or use age: this->age < rhs.age;
    }

    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Overload stream insertion operator for Person
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// ====================
// Display function
// Passes the priority queue by value (copy), so original is not modified
// ====================
template <typename T>
void display(std::priority_queue<T> pq) {
    std::cout << "[ ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "]" << std::endl;
}

// ====================
// Test1: priority_queue with int
// ====================
void test1() {
    std::cout << "\nTest1 - Priority Queue with Integers" << std::endl;

    std::priority_queue<int> pq;
    for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
        pq.push(i);

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top:  " << pq.top() << std::endl;

    std::cout << "Priority Queue contents: ";
    display(pq);

    pq.pop(); // Remove the top element
    std::cout << "After popping top element: ";
    display(pq);
}

// ====================
// Test2: priority_queue with custom Person objects
// ====================
void test2() {
    std::cout << "\nTest2 - Priority Queue with Person objects (by name)" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});

    std::cout << "Priority Queue contents: ";
    display(pq);
}

// ====================
// Main
// ====================
int main() {
    test1();
    test2();
    return 0;
}
