// Section 20
// Function templates in C++

#include <iostream>
#include <string>

// ----------- Template function for finding minimum -----------
template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

// ----------- Template function for finding maximum -----------
template <typename A>
A max(A x, A y) {
    return (x > y) ? x : y;
}

// ----------- Template function taking two different types -----------
template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << "func(): " << a << " " << b << std::endl;
}

// ----------- Custom struct for demonstrating comparison -----------
struct Person {
    std::string name;
    int age;

    // Overload < operator to compare Persons by age
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

// Overload << operator to print Person's name
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name;
    return os;
}

// ----------- Template function to swap two variables -----------
template <typename T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    std::cout << "----- Template: Swap -----" << std::endl;
    int x{100};
    int y{200};
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    my_swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    std::cout << "\n----- Template: min() with custom struct -----" << std::endl;
    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};

    // Uses overloaded < to compare ages
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;

    std::cout << "\n----- Template: func() with custom struct -----" << std::endl;
    func(p1, p2);  // Will print names using overloaded <<

    std::cout << "\n----- Template: min() with different types -----" << std::endl;
    std::cout << "min<int>(2,3) = " << min<int>(2,3) << std::endl;               // Explicitly specify int: 2
    std::cout << "min(2,3) = " << min(2,3) << std::endl;                         // Type inferred: 2
    std::cout << "min('A', 'B') = " << min('A', 'B') << std::endl;              // Characters: A
    std::cout << "min(12.5, 9.2) = " << min(12.5, 9.2) << std::endl;            // Doubles: 9.2
    std::cout << "min(5+2*2, 7+40) = " << min(5+2*2, 7+40) << std::endl;        // Expressions: min(9, 47) = 9

    std::cout << "\n----- Template: max() -----" << std::endl;
    std::cout << "max(100, 99) = " << max(100, 99) << std::endl; // 100

    std::cout << "\n----- Template: func() with different type combinations -----" << std::endl;
    func<int, int>(10, 20);                           // Explicit types
    func(10, 20);                                     // Inferred types
    func<char, double>('A', 12.4);                    // Explicit types
    func('A', 12.4);                                  // Inferred types
    func(1000, "Testing");                            // Mixed: int and const char*
    func(2000, std::string{"Frank"});                 // Mixed: int and std::string

    return 0;
}
