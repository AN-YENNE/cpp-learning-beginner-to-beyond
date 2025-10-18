// -------------------------------------------
// C++ STL Algorithms with Lambda Expressions
// -------------------------------------------

// Standard headers used in this program
#include <iostream>     // For input and output (std::cout, std::endl)
#include <vector>       // For std::vector container
#include <algorithm>    // For STL algorithms (for_each, sort, transform, remove_if, all_of, etc.)
#include <numeric>      // For std::iota (to generate sequences of numbers)
#include <string>       // For std::string (used in Password validators)

// -------------------------------------------------------------------------
// TEST 1: std::for_each - Non-modifying sequence operation
// Demonstrates applying a lambda to each element in a vector.
// -------------------------------------------------------------------------
void test1()
{
    std::cout << "\n--- Test1: for_each Example --------------------------" << std::endl;

    std::vector<int> numbers { 10, 20, 30, 40, 50 };

    std::cout << "Elements in the vector are: ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;
}

// -------------------------------------------------------------------------
// TEST 2: std::is_permutation - Checks whether two triangles are equivalent
// Two triangles are represented as vectors of 3 points (x, y).
// Order of points doesn't matter if they form the same triangle.
// is_permutation - Non-modifying sequence operation
// Tests whether two triangles are equivalent.
// Triangles are defined by a vector of three points in any order.
// Regardless of the order of points, if two triangles contain the 
// same three points then they are equivalent.
// This is determined by testing whether one sequence of points is a 
// permutation of another using a predicate lambda to compare points.
// -------------------------------------------------------------------------
void test2()
{
    std::cout << "\n--- Test2: is_permutation Example --------------------" << std::endl;

    struct Point
    {
        int x;
        int y;
    };

    // Define 4 points
    Point p1{1, 2};
    Point p2{4, 3};
    Point p3{3, 5};
    Point p4{3, 1};

    // Define three triangles (two are same with different order of points)
    std::vector<Point> triangle1 { p1, p2, p3 };
    std::vector<Point> triangle2 { p2, p3, p1 };
    std::vector<Point> triangle3 { p1, p2, p4 };

    // Check if triangle1 and triangle2 are equivalent
    bool t1_t2_equiv = std::is_permutation(
        triangle1.begin(), triangle1.end(),
        triangle2.begin(),
        [](Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
    );

    std::cout << "Triangle1 and Triangle2 are "
              << (t1_t2_equiv ? "EQUIVALENT ✅" : "NOT equivalent ❌") << std::endl;

    // Check if triangle1 and triangle3 are equivalent
    bool t1_t3_equiv = std::is_permutation(
        triangle1.begin(), triangle1.end(),
        triangle3.begin(),
        [](Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
    );

    std::cout << "Triangle1 and Triangle3 are "
              << (t1_t3_equiv ? "EQUIVALENT ✅" : "NOT equivalent ❌") << std::endl;
}

// -------------------------------------------------------------------------
// TEST 3: std::transform - Modifying sequence operation
// transform - Modifying sequence operation
// Similar to the lambda "bonus" we defined earlier which awarded 
// bonus points to test scores, the transform function applies whatever 
// operation is defined within the passed lambda to each element of the sequence.
// In this case, each test score is increased by 5 points.
// Increases each test score by bonus points.
// -------------------------------------------------------------------------
void test3()
{
    std::cout << "\n--- Test3: transform Example -------------------------" << std::endl;

    std::vector<int> test_scores { 93, 88, 75, 68, 65 };
    int bonus_points { 5 };

    // Increase each score by bonus_points
    std::transform(
        test_scores.begin(), test_scores.end(),
        test_scores.begin(),
        [bonus_points](int score) {
            return score + bonus_points;
        }
    );

    std::cout << "Test scores after adding " << bonus_points << " bonus points: ";
    for (int score : test_scores)
        std::cout << score << " ";
    std::cout << std::endl;
}

// -------------------------------------------------------------------------
// TEST 4: std::remove_if + erase - Erase-Remove Idiom
// Removes all even numbers from a vector.
// remove_if - Modifying sequence operation
// This example is what's known as an erase-remove idiom and is one of 
// the most common uses of lambdas with the standard template library.
// The remove_if function removes all elements for which the predicate 
// lambda returns true. The way in which it does this is by replacing 
// each element for which the predicate returns true with the next element 
// for which the predicate returns false. The function then returns an 
// iterator to the new end of the sequence.
// The size of the sequence is not altered, only the position of its 
// elements and its end iterator.
// Used in conjunction with the vector member function "erase", the
// removed elements can be erased from the vector so that it only contains
// the elements for which the predicate returned false.
// In this case, the erase-remove idiom is used to remove all even numbers from nums.
// -------------------------------------------------------------------------
void test4()
{
    std::cout << "\n--- Test4: remove_if Example -------------------------" << std::endl;

    std::vector<int> numbers { 1, 2, 3, 4, 5 };

    numbers.erase(
        std::remove_if(
            numbers.begin(),
            numbers.end(),
            [](int num) { return num % 2 == 0; }   // Predicate: true for even numbers
        ),
        numbers.end()
    );

    std::cout << "Vector after removing even numbers: ";
    for (int num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;
}

// -------------------------------------------------------------------------
// Class used in TEST 5
// sort - Sorting
// Sorts elements in the sequence according to the predicate lambda.
// In this example, a vector of people is first sorted by name in ascending order
// and then by age in descending order.
// -------------------------------------------------------------------------
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p) : name{p.name}, age{p.age} {}
    ~Person() = default;

    std::string get_name() const { return name; }
    void set_name(std::string n) { name = n; }

    int get_age() const { return age; }
    void set_age(int a) { age = a; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// -------------------------------------------------------------------------
// TEST 5: std::sort - Sorting with lambdas
// Sort by name (ascending) and age (descending).
// in_between is used for test6
// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
// -------------------------------------------------------------------------
void test5()
{
    std::cout << "\n--- Test5: sort Example -----------------------------" << std::endl;

    std::vector<Person> people {
        Person("Larry", 18),
        Person("Moe", 30),
        Person("Curly", 25)
    };

    // Sort by name in ascending order
    std::sort(people.begin(), people.end(),
              [](const Person &lhs, const Person &rhs) {
                  return lhs.get_name() < rhs.get_name();
              });

    std::cout << "Sorted by name (A-Z):" << std::endl;
    for (const Person &p : people)
        std::cout << p << std::endl;

    std::cout << std::endl;

    // Sort by age in descending order
    std::sort(people.begin(), people.end(),
              [](const Person &lhs, const Person &rhs) {
                  return lhs.get_age() > rhs.get_age();
              });

    std::cout << "Sorted by age (descending):" << std::endl;
    for (const Person &p : people)
        std::cout << p << std::endl;
}

// -------------------------------------------------------------------------
// TEST 6: std::all_of - Check if all numbers fall within a range
// Helper function: in_between()
// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
// In this case, the all_of function is contained within the class
// Password_Validator which determines whether a password contains
// a restricted symbol and thus is valid or not.
// The same can be accomplished by using the stl function "none_of" and
// changing the conditional contained within the passed lambda.
// -------------------------------------------------------------------------
bool in_between(const std::vector<int> &nums, int start_value, int end_value)
{
    return std::all_of(
        nums.begin(),
        nums.end(),
        [start_value, end_value](int value) {
            return value >= start_value && value <= end_value;
        }
    );
}

void test6()
{
    std::cout << "\n--- Test6: all_of Example ---------------------------" << std::endl;
    std::cout << std::boolalpha;

    std::vector<int> numbers(10);
    std::iota(numbers.begin(), numbers.end(), 1);  // Fill with 1..10

    std::cout << "Numbers in the vector: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Are all numbers between 50 and 60? " << in_between(numbers, 50, 60) << std::endl;
    std::cout << "Are all numbers between 1 and 10? "  << in_between(numbers, 1, 10) << std::endl;
    std::cout << "Are all numbers between 5 and 7? "   << in_between(numbers, 5, 7) << std::endl;
}

// -------------------------------------------------------------------------
// Password Validator classes used in TEST 7
// Demonstrate std::all_of and std::none_of.
// -------------------------------------------------------------------------
class Password_Validator1 {
private:
    char restricted_symbol {'$'};
public:
    bool is_valid(const std::string &password) {
        return std::all_of(
            password.begin(),
            password.end(),
            [this](char c) { return c != restricted_symbol; }
        );
    }
};

class Password_Validator2 {
private:
    std::vector<char> restricted_symbols { '!', '$', '+' };
public:
    bool is_valid(const std::string &password) {
        return std::all_of(
            password.begin(),
            password.end(),
            [this](char c) {
                return std::none_of(
                    restricted_symbols.begin(),
                    restricted_symbols.end(),
                    [c](char symbol) { return c == symbol; }
                );
            }
        );
    }
};

// -------------------------------------------------------------------------
// TEST 7: all_of and none_of
// Validates passwords by checking for restricted characters.
// -------------------------------------------------------------------------
void test7()
{
    std::cout << "\n--- Test7: Password Validation Example --------------" << std::endl;

    // Using Password_Validator1 (restricts only '$')
    std::string password = "holywood1$";
    Password_Validator1 pv1;

    std::cout << "Testing password: " << password << std::endl;
    std::cout << (pv1.is_valid(password) ? " Valid" : "Not valid") << std::endl;

    password = "hollywood1";
    std::cout << "\nTesting password: " << password << std::endl;
    std::cout << (pv1.is_valid(password) ? "Valid" : "Not valid") << std::endl;

    std::cout << "\n";

    // Using Password_Validator2 (restricts multiple symbols)
    password = "C++Rocks!";
    Password_Validator2 pv2;

    std::cout << "Testing password: " << password << std::endl;
    std::cout << (pv2.is_valid(password) ? "Valid" : "Not valid") << std::endl;

    password = "CPlusPlusRocks!";
    std::cout << "\nTesting password: " << password << std::endl;
    std::cout << (pv2.is_valid(password) ? "Valid" : "Not valid") << std::endl;

    password = "CPlusPlusRocks";
    std::cout << "\nTesting password: " << password << std::endl;
    std::cout << (pv2.is_valid(password) ? "Valid" : "Not valid") << std::endl;
}

// -------------------------------------------------------------------------
// main()
// -------------------------------------------------------------------------
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    std::cout << "\nProgram finished successfully ✅" << std::endl;
    return 0;
}
