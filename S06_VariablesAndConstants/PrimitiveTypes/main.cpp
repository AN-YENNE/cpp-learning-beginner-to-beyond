// Section 6: Primitive Types
//
// This example introduces C++ primitive (built-in) data types.
// It demonstrates declaration, initialization, and printing of characters, integers, floating-point numbers, and booleans.
// It also shows an integer overflow scenario.
//
// Key ideas:
// 1. Use single quotes for `char` literals (e.g., 'A').
// 2. Integer types vary by size and whether they allow negatives.
// 3. Use underscores (or apostrophes) in large numbers for readability (since C++14).
// 4. Floating-point types (float, double, long double) hold decimal values.
// 5. Boolean types store true/false values, printed as 1 or 0 by default.
// 6. Overflow occurs when the result exceeds the variable’s type capacity.

#include <iostream>
using namespace std;

int main() {
    /***********************************************
     *  Character type
     **********************************************/
    char middle_initial {'J'};  // Use single quotes for a single character
    cout << "My middle initial is " << middle_initial << endl;

    /***********************************************
     *  Integer types
     **********************************************/
    unsigned short int exam_score {55};  // Unsigned means no negative values
    cout << "My exam score was " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented 
         << " countries represented in the conference." << endl;

    long people_in_region {20'610'000};  // long integer literal with digit separator
    cout << "There are about " << people_in_region 
         << " people in the region." << endl;

    long long global_population {7'900'000'000};  // long long for very large values
    cout << "There are roughly " << global_population 
         << " people on Earth." << endl;

    long long distance_to_star {9'461'000'000'000};  // in kilometers
    cout << "The distance to the nearest star system is approximately " 
         << distance_to_star << " kilometers." << endl;

    /***********************************************
     *  Floating point types
     **********************************************/
    float car_payment {401.23F};  // F suffix makes literal float (optional)
    cout << "My monthly car payment is $" << car_payment << endl;

    double pi {3.14159};
    cout << "The value of π (pi) is approximately " << pi << endl;

    long double huge_number {2.7e120L};  // L suffix denotes long double
    cout << huge_number << " is an extremely large number." << endl;

    /***********************************************
     *  Boolean type
     **********************************************/
    bool game_over {false};
    cout << "Is the game over? " << game_over << " (1 = true, 0 = false)" << endl;

    /***********************************************
     *  Overflow example
     **********************************************/
    short value1 {30000};
    short value2 {1000};
    // The product exceeds short’s maximum value (~32767)
    short product {static_cast<short>(value1 * value2)};
    cout << "Multiplying " << value1 << " by " << value2 
         << " gives " << product << " (overflow example)." << endl;

    // Explanation:
    // value1 * value2 = 30,000 * 1,000 = 30,000,000
    // Since 'short' cannot store such a large number,
    // it wraps around and produces an incorrect result.

    /***********************************************
     *  Summary
     **********************************************/
    cout << "\n--- Summary ---" << endl;
    cout << "Character: " << middle_initial << endl;
    cout << "Integer examples: " << exam_score << ", " << countries_represented << endl;
    cout << "Floating point examples: " << car_payment << ", " << pi << endl;
    cout << "Boolean: " << game_over << endl;
    cout << "Overflow demo result: " << product << endl;

    return 0;
}

/*
Notes for learners:
- C++ supports multiple primitive types, each with a specific range and size.
- For portability, prefer fixed-width types like int32_t, uint64_t from <cstdint>.
- Boolean values print as 0 (false) or 1 (true). You can use std::boolalpha to print "true"/"false".
- Numeric literals can use digit separators (') for readability.
- Overflow is undefined behavior in signed integers — results may differ by compiler.

Try modifying the values and observe how C++ handles different data sizes and types!
*/