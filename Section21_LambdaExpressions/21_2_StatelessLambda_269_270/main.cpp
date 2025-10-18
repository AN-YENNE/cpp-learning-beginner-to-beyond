// Section 21
// Stateless lambda expressions
// [] - empty capture lists (no external variables are captured)

#include <iostream>
#include <string>
#include <vector>
#include <functional>   // for std::function
#include <algorithm>    // for std::sort and std::for_each

// ==========================================================================
// Person class for demonstration
// ==========================================================================
class Person {
    // Overloaded operator<< as a friend to print Person objects nicely
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p): name{p.name}, age{p.age} { }
    ~Person() = default;

    // Getters and setters
    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; }
    int get_age() const { return age; }
    void set_age(int age) { this->age = age; }
};

// Helper function for printing Person objects
std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// ==========================================================================
// TEST 1 - Stateless lambdas: simplest form with no captures
// ==========================================================================
void test1() {
    std::cout << "\n--- Test 1: Basic Stateless Lambdas ---" << std::endl;

    // Lambda with no parameters
    [] () {
        std::cout << "Hello from a stateless lambda with no parameters!" << std::endl;
    }(); // Notice the () at the end - this immediately calls the lambda

    // Lambda with one parameter
    [](int x) {
        std::cout << "Lambda received one parameter: x = " << x << std::endl;
    }(100);

    // Lambda with two parameters
    [](int x, int y) {
        std::cout << "Lambda received two parameters: " << x << " + " << y << " = " << x + y << std::endl;
    }(100, 200);
}

// ==========================================================================
// TEST 2 - Passing values and references as lambda parameters
// ==========================================================================
void test2() {
    std::cout << "\n--- Test 2: Lambda with value and reference parameters ---" << std::endl;
    
    auto l1 = [] () {
        std::cout << "Lambda stored in variable and invoked later." << std::endl;
    };
    l1(); // calling the stored lambda

    int num1 {100};
    int num2 {100};

    auto l2 = [](int x, int y) {
        std::cout << "Sum of " << x << " and " << y << " is " << x + y << std::endl;
    };
    l2(10, 20);
    l2(num1, num2);

    auto l3 = [](int &x, int y) {
        std::cout << "Before modification: x = " << x << ", y = " << y << std::endl;
        x = 1000;  // modifies original variable since x is passed by reference
        y = 2000;  // does not modify original since y is passed by value
        std::cout << "Inside lambda after modification: x = " << x << ", y = " << y << std::endl;
    };
    
    l3(num1, num2);
    std::cout << "After lambda call: num1 = " << num1 << ", num2 = " << num2 << std::endl;
}

// ==========================================================================
// TEST 3 - Passing and modifying objects through lambdas
// ==========================================================================
void test3() {
    std::cout << "\n--- Test 3: Using Objects with Lambdas ---" << std::endl;
    
    Person stooge {"Larry", 18};
    std::cout << "Original object: " << stooge << std::endl;
    
    // Passing Person by value (makes a copy)
    auto l4 = [] (Person p) {
        std::cout << "Lambda received Person by value: " << p << std::endl;
    };
    l4(stooge);
    
    // Passing Person by const reference (no copy, cannot modify inside)
    auto l5 = [] (const Person &p) {
        std::cout << "Lambda received Person by const reference: " << p << std::endl;
    };
    l5(stooge);
    
    // Passing Person by non-const reference (can modify original)
    auto l6 = [] (Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout << "Lambda modified Person object: " << p << std::endl;
    };
    l6(stooge);
    
    std::cout << "After lambda modification: " << stooge << std::endl;
}

// ==========================================================================
// Helper function used in test4
// Demonstrates passing a lambda as a function parameter
// ==========================================================================
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func) {
    std::cout << "[ ";
    for (int i : vec) {
        if (func(i))  // call the lambda for each element
            std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

// ==========================================================================
// TEST 4 - Passing lambdas as function arguments
// ==========================================================================
void test4() {
    std::cout << "\n--- Test 4: Passing Lambda to a Function ---" << std::endl;
    std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};
    
    std::cout << "Numbers greater than 50: ";
    filter_vector(nums, [](int x) { return x > 50; });
    
    std::cout << "Numbers less than or equal to 30: ";
    filter_vector(nums, [](int x) { return x <= 30; });
    
    std::cout << "Numbers between 30 and 60: ";
    filter_vector(nums, [](int x) { return x >= 30 && x <= 60; });
}

// ==========================================================================
// Helper function used in test5
// Returns a lambda
// ==========================================================================
auto make_lambda() {
    return [] () {
        std::cout << "This lambda was returned by make_lambda() function!" << std::endl;
    };
}

// ==========================================================================
// TEST 5 - Returning a lambda from a function
// ==========================================================================
void test5() {
    std::cout << "\n--- Test 5: Returning a Lambda ---" << std::endl;
    
    auto l5 = make_lambda(); // l5 now holds the lambda returned by make_lambda
    l5(); // execute the lambda
}

// ==========================================================================
// TEST 6 - Using 'auto' in lambda parameter list (generic lambdas)
// ==========================================================================
void test6() {
    std::cout << "\n--- Test 6: Generic Lambdas with 'auto' parameters ---" << std::endl;
    
    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << " | y: " << y << std::endl;
    };
    
    // Different data types work with the same lambda!
    l6(10, 20);
    l6(100.3, 200);
    l6(12.5, 15.54);
    l6(Person("Larry", 18), Person("Curly", 22));
}

// ==========================================================================
// TEST 7 - Using lambdas with algorithms (sort & for_each)
// ==========================================================================
void test7() {
    std::cout << "\n--- Test 7: Lambdas with std::sort and std::for_each ---" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    // Sorting by name (ascending)
    std::cout << "Sorting by name..." << std::endl;
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_name() < p2.get_name();
    });

    std::cout << "Result after sorting by name:" << std::endl;
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << "  " << p << std::endl;
    });
    std::cout << std::endl;

    // Sorting by age (ascending)
    std::cout << "Sorting by age..." << std::endl;
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age() < p2.get_age();
    });

    std::cout << "Result after sorting by age:" << std::endl;
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << "  " << p << std::endl;
    });
}

// ==========================================================================
// MAIN FUNCTION
// ==========================================================================
int main()
{
    test1();  // basic lambda syntax
    test2();  // passing values & references
    test3();  // working with objects
    test4();  // passing lambdas to functions
    test5();  // returning lambdas
    test6();  // generic lambdas with auto
    test7();  // lambdas with algorithms (sort & for_each)
    
    std::cout << "\n--- Program finished successfully ---" << std::endl;
    return 0;
}
/*
Key concepts covered in this example:

[] empty capture list → stateless lambda

Parameters: by value, by reference, by const reference

Passing lambdas to functions using std::function

Returning lambdas from functions

Generic lambdas using auto

Using lambdas with STL algorithms like sort and for_each.*/