// Section 21
// Function Objects (Functors) Demonstration

#include <iostream> // -> for console input/output
#include <vector> // -> for using std::vector container
#include <algorithm> // -> for algorithms like std::for_each and std::transform
#include <functional> // -> for using standard function objects (if needed)

// =============================================================
// Functor that squares an integer and prints it
// =============================================================
struct Square_Functor {
    void operator() (int x) {
        // This function object prints the square of a number
        std::cout << "Square of " << x << " is: " << x * x << "  \n";
    }
};

// =============================================================
// Templated Functor that displays any type of data
// =============================================================
template <typename T>
struct Displayer {
    void operator() (const T &data) {
        // This functor simply prints the data value
        std::cout << "[Display: " << data << "] ";
    }
};

// =============================================================
// Functor that multiplies numbers by a fixed value
// =============================================================
class Multiplier {
private:
    int num{};   // the number to multiply with
public:
    Multiplier(int n) : num{n} {}
    
    // overload operator() to make the object callable like a function
    int operator()(int n) const {
        return n * num;
    }
};

// =============================================================
// MAIN FUNCTION
// =============================================================
int main()
{
    std::cout << "\n========== Test 1: Basic Functor Calls ==========\n";

    // Creating a Square_Functor object
    Square_Functor square;
    square(4);      // same as square.operator()(4) -> prints 16

    // Creating Displayer objects for int and string
    Displayer<int> d1;
    Displayer<std::string> d2;

    // Using the display functor directly
    d1(100);                // prints 100
    d2("Frank");            // prints "Frank"

    std::cout << "\n\n========== Test 2: Functors with std::for_each ==========\n";

    // Sample vectors
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    // Using Square_Functor with for_each
    std::cout << "Squares of vec1 elements: ";
    std::for_each(vec1.begin(), vec1.end(), square);                
    std::cout << std::endl;

    // Using Displayer directly without creating a named object
    std::cout << "Displaying vec1 using Displayer<int>() directly: ";
    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());  
    std::cout << std::endl;

    // Using named Displayer object for vec1
    std::cout << "Displaying vec1 using existing Displayer object d1: ";
    std::for_each(vec1.begin(), vec1.end(), d1);                    
    std::cout << std::endl;

    // Using Displayer for string vector
    std::cout << "Displaying vec2 using Displayer<std::string>() directly: ";
    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>()); 
    std::cout << std::endl;

    std::cout << "Displaying vec2 using existing Displayer object d2: ";
    std::for_each(vec2.begin(), vec2.end(), d2);    
    std::cout << std::endl;

    std::cout << "\n\n========== Test 3: Using Lambda Functions ==========\n";

    // Lambda functions are inline, unnamed functors
    std::cout << "Squares of vec1 elements using lambda: ";
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x * x  << " "; });
    std::cout << std::endl;

    std::cout << "Multiplying vec1 elements by 10 using lambda: ";
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x * 10 << " "; });
    std::cout << std::endl;

    std::cout << "Printing vec1 elements using lambda: ";
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << "Printing vec2 elements using lambda: ";
    std::for_each(vec2.begin(), vec2.end(), [](std::string s) { std::cout << s << " "; });
    std::cout << std::endl;

    std::cout << "\n\n========== Test 4: Using std::transform with Functors ==========\n";

    Multiplier mult(100);  // Create a Multiplier functor that multiplies by 100
    vec1 = {1, 2, 3, 4};

    // std::transform applies the functor to each element and stores result in the destination
    // Here: destination = same as source (vec1), so vec1 is modified
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);

    std::cout << "Elements of vec1 after multiplying by 100 (using Multiplier functor): ";
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    // Doing the same thing with a lambda instead of a functor
    vec1 = {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * 100; });

    std::cout << "Elements of vec1 after multiplying by 100 (using lambda): ";
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << "\n========== Program Completed Successfully ==========\n";
    return 0;
}
/*Key takeaways for beginners:

Functors are just classes with operator() defined.

They can be used like regular functions.

std::for_each and std::transform can work with functors, lambdas, or regular functions.

Lambdas are a quick, inline way to define functor-like behavior without creating a separate class.*/