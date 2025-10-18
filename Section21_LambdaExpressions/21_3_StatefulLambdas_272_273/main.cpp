// Section 21
// Stateful Lambda Expressions - Capture by Value, Reference, and this
// ---------------------------------------------------------------
// Includes:
// <iostream>   -> for console input/output
// <vector>     -> for std::vector
// <algorithm>  -> for std::copy_if and other algorithms

#include <iostream>
#include <vector>
#include <algorithm>

// A global variable (not captured but accessible through normal lookup)
int global_x {1000};

// ==========================================================================
// TEST 1 - Capture by value
// Note: global variables are not captured but can still be accessed
// ==========================================================================
void test1()
{
    std::cout << "\n--- Test 1: Capture by Value (Local Variable) ---" << std::endl;

    int local_x {100};

    // Capturing local_x by value. global_x is not captured, but still accessible
    auto l = [local_x]() {
        std::cout << "Inside lambda - local_x (captured by value): " << local_x << std::endl;
        std::cout << "Inside lambda - global_x (accessed directly): " << global_x << std::endl;
    };

    l();
}

// ==========================================================================
// TEST 2 - Capture by value with mutable
// Mutable allows modifying the *captured copy* inside the lambda.
// The original variable is not affected.
// ==========================================================================
void test2()
{
    std::cout << "\n--- Test 2: Capture by Value with mutable ---" << std::endl;

    int x {100};

    auto l = [x]() mutable {
        x += 100; // modifies the copy of x inside the lambda
        std::cout << "Inside lambda - x (modified copy): " << x << std::endl;
    };

    l(); // First call
    std::cout << "Outside lambda - x (original): " << x << std::endl;

    l(); // Second call - works with its own stored state (copy)
    std::cout << "Outside lambda after second call - x: " << x << std::endl;
}

// ==========================================================================
// TEST 3 - Capture by reference
// Changes inside the lambda affect the original variable.
// ==========================================================================
void test3()
{
    std::cout << "\n--- Test 3: Capture by Reference ---" << std::endl;

    int x {100};

    auto l = [&x]() mutable {
        x += 100;
        std::cout << "Inside lambda - x (after modification): " << x << std::endl;
    };

    l();
    std::cout << "Outside lambda - x (changed original): " << x << std::endl;
}

// ==========================================================================
// TEST 4 - Default capture by value [=]
// Only variables used inside the lambda are captured.
// ==========================================================================
void test4()
{
    std::cout << "\n--- Test 4: Default Capture by Value [=] ---" << std::endl;

    int x {100};
    int y {200};
    int z {300};  // not used in lambda, so not captured

    auto l = [=]() mutable {
        x += 100;
        y += 100;
        std::cout << "Inside lambda - x: " << x << " y: " << y << std::endl;
    };

    l();
    std::cout << "Outside lambda - x: " << x << " y: " << y << std::endl;
}

// ==========================================================================
// TEST 5 - Default capture by reference [&]
// All used variables are captured by reference.
// ==========================================================================
void test5()
{
    std::cout << "\n--- Test 5: Default Capture by Reference [&] ---" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&]() {
        x += 100;
        y += 100;
        z += 100;
        std::cout << "Inside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
    };

    l();
    std::cout << "Outside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
}

// ==========================================================================
// TEST 6 - Default capture by value, selective capture by reference
// [=, &y] -> captures x and z by value, y by reference
// ==========================================================================
void test6()
{
    std::cout << "\n--- Test 6: Mixed Capture ([=, &y]) ---" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=, &y]() mutable {
        x += 100; // local copy
        y += 100; // original variable modified
        z += 100; // local copy
        std::cout << "Inside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
    };

    l();
    std::cout << "Outside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
}

// ==========================================================================
// TEST 7 - Default capture by reference, selective capture by value
// [&, x, z] -> captures everything by reference except x and z by value
// Equivalent to TEST 6 but reversed
// ==========================================================================
void test7()
{
    std::cout << "\n--- Test 7: Mixed Capture ([&, x, z]) ---" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&, x, z]() mutable {
        x += 100; // local copy (value capture)
        y += 100; // reference capture
        z += 100; // local copy (value capture)
        std::cout << "Inside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
    };

    l();
    std::cout << "Outside lambda - x: " << x << " y: " << y << " z: " << z << std::endl;
}

// ==========================================================================
// Person class for demonstrating capturing 'this'
// ==========================================================================
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p) = default;
    ~Person() = default;

    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; }
    int get_age() const { return age; }
    void set_age(int age) { this->age = age; }

    // Return lambdas that modify member variables
    auto change_person1() { return [this](std::string new_name, int new_age) { name = new_name; age = new_age; }; }
    auto change_person2() { return [=](std::string new_name, int new_age) { name = new_name; age = new_age; }; } // deprecated in C++20
    auto change_person3() { return [&](std::string new_name, int new_age) { name = new_name; age = new_age; }; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// ==========================================================================
// TEST 8 - Capturing 'this' in lambdas
// [this], [=], [&] are equivalent when capturing member variables
// ==========================================================================
void test8()
{
    std::cout << "\n--- Test 8: Capturing 'this' ---" << std::endl;

    Person person("Larry", 18);
    std::cout << "Original Person: " << person << std::endl;

    auto change1 = person.change_person1(); // capture this
    change1("Moe", 30);
    std::cout << "After change_person1: " << person << std::endl;

    auto change2 = person.change_person2(); // capture by [=]
    change2("Curly", 25);
    std::cout << "After change_person2: " << person << std::endl;

    auto change3 = person.change_person3(); // capture by [&]
    change3("Frank", 34);
    std::cout << "After change_person3: " << person << std::endl;
}

// ==========================================================================
// Lambda class equivalence demonstration
// ==========================================================================
class Lambda {
private:
    int y;
public:
    Lambda(int y) : y{y} {}
    void operator()(int x) const {
        std::cout << "Lambda class - result: " << x + y << std::endl;
    }
};

void test9()
{
    std::cout << "\n--- Test 9: Lambda Class Equivalence ---" << std::endl;

    int y {100};

    Lambda lambda1(y);                     // Functor class
    auto lambda2 = [y](int x) { std::cout << "Lambda expression - result: " << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

// ==========================================================================
// Class demonstrating complex lambda captures
// ==========================================================================
class People {
    std::vector<Person> people;
    int max_people;
public:
    People(int max = 10) : max_people(max) {}
    People(const People &p) = default;

    void add(std::string name, int age) {
        people.emplace_back(name, age);
    }
    void set_max_people(int max) {
        max_people = max;
    }
    int get_max_people() const {
        return max_people;
    }

    // Lambda captures this, max_age by value, count by reference
    std::vector<Person> get_people(int max_age) {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(),
                     people.end(),
                     std::back_inserter(result),
                     [this, &count, max_age](const Person &p) {
                         return p.get_age() > max_age && ++count <= max_people;
                     });
        return result;
    }
};

// ==========================================================================
// TEST 10 - Realistic lambda use with STL algorithms
// ==========================================================================
void test10() {
    std::cout << "\n--- Test 10: Complex Lambda Capture Example ---" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    std::cout << "\nFilter people with age > 17:" << std::endl;
    auto result = friends.get_people(17);
    for (const auto &p: result) std::cout << p << std::endl;

    friends.set_max_people(3);
    std::cout << "\nFilter people with age > 17 and limit to 3:" << std::endl;
    result = friends.get_people(17);
    for (const auto &p: result) std::cout << p << std::endl;

    std::cout << "\nFilter people with age > 50:" << std::endl;
    result = friends.get_people(50);
    for (const auto &p: result) std::cout << p << std::endl;
}

// ==========================================================================
// MAIN
// ==========================================================================
int main()
{
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

    std::cout << "\n--- Program finished successfully ---\n";
    return 0;
}
