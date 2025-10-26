// Section 6: The sizeof operator
//
// This example shows how to use sizeof to find out how many bytes a type or a variable occupies in memory.
// It also prints the minimum and maximum values for common integral types using <climits>.
//
// Key ideas:
// 1) sizeof(T) works with a type name T, returns size in bytes at compile time.
// 2) sizeof var or sizeof(var) works with a variable or expression.
// 3) Sizes and numeric limits are platform and compiler dependent.
// 4) Use <climits> for integer limits like INT_MIN, INT_MAX, etc.
// 5) Floating point sizes come from sizeof, while limits are in <cfloat> if needed.

#include <iostream>
#include <climits>   // integer limits such as INT_MIN, INT_MAX, etc.
#include <cfloat>    // floating point limits such as FLT_MIN, FLT_MAX (optional)
using namespace std;

int main() {
    cout << "=== Basic sizeof information (in bytes) ===" << endl;

    // sizeof with fundamental character and integer types
    cout << "char:               " << sizeof(char)        << " byte(s)" << endl;
    cout << "signed char:        " << sizeof(signed char) << " byte(s)" << endl;
    cout << "unsigned char:      " << sizeof(unsigned char) << " byte(s)" << endl;

    cout << "short:              " << sizeof(short)       << " byte(s)" << endl;
    cout << "unsigned short:     " << sizeof(unsigned short) << " byte(s)" << endl;

    cout << "int:                " << sizeof(int)         << " byte(s)" << endl;
    cout << "unsigned int:       " << sizeof(unsigned int) << " byte(s)" << endl;

    cout << "long:               " << sizeof(long)        << " byte(s)" << endl;
    cout << "unsigned long:      " << sizeof(unsigned long) << " byte(s)" << endl;

    cout << "long long:          " << sizeof(long long)   << " byte(s)" << endl;
    cout << "unsigned long long: " << sizeof(unsigned long long) << " byte(s)" << endl;

    cout << "bool:               " << sizeof(bool)        << " byte(s)" << endl;

    cout << "=== Floating point sizeof information (in bytes) ===" << endl;
    cout << "float:              " << sizeof(float)       << " byte(s)" << endl;
    cout << "double:             " << sizeof(double)      << " byte(s)" << endl;
    cout << "long double:        " << sizeof(long double) << " byte(s)" << endl;

    // Integer range information from <climits>
    cout << "=== Integer type minimum values ===" << endl;
    cout << "char min:           " << static_cast<int>(CHAR_MIN) << endl;   // cast shows numeric value
    cout << "signed char min:    " << static_cast<int>(SCHAR_MIN) << endl;
    cout << "short min:          " << SHRT_MIN << endl;
    cout << "int min:            " << INT_MIN << endl;
    cout << "long min:           " << LONG_MIN << endl;
    cout << "long long min:      " << LLONG_MIN << endl;

    cout << "=== Integer type maximum values ===" << endl;
    cout << "char max:           " << static_cast<int>(CHAR_MAX) << endl;
    cout << "signed char max:    " << static_cast<int>(SCHAR_MAX) << endl;
    cout << "unsigned char max:  " << static_cast<unsigned int>(UCHAR_MAX) << endl;
    cout << "short max:          " << SHRT_MAX << endl;
    cout << "unsigned short max: " << USHRT_MAX << endl;
    cout << "int max:            " << INT_MAX << endl;
    cout << "unsigned int max:   " << UINT_MAX << endl;
    cout << "long max:           " << LONG_MAX << endl;
    cout << "unsigned long max:  " << ULONG_MAX << endl;
    cout << "long long max:      " << LLONG_MAX << endl;
    cout << "unsigned long long max: " << ULLONG_MAX << endl;

    // Optional: show floating point limits from <cfloat>
    cout << "=== Floating point limits from <cfloat> ===" << endl;
    cout << "float min positive: " << FLT_MIN << "    float max: " << FLT_MAX << endl;
    cout << "double min positive: " << DBL_MIN << "   double max: " << DBL_MAX << endl;
    cout << "long double min positive: " << LDBL_MIN << "   long double max: " << LDBL_MAX << endl;

    // sizeof can also be used with variable names or expressions
    cout << "=== sizeof using variables and expressions ===" << endl;

    int user_age {32};
    cout << "Variable user_age is " << sizeof(user_age) << " byte(s)" << endl;
    // Alternative syntax without parentheses
    cout << "Variable user_age is " << sizeof user_age << " byte(s) [no parentheses]" << endl;

    double hourly_rate { 27.50 };
    cout << "Variable hourly_rate is " << sizeof(hourly_rate) << " byte(s)" << endl;
    cout << "Expression sizeof(user_age + hourly_rate) is "
         << sizeof(user_age + hourly_rate) << " byte(s)  // result type of the expression"
         << endl;

    // Notes
    // 1) sizeof is evaluated at compile time for types and most expressions.
    // 2) Sizes and limits can vary by platform and compiler options.
    // 3) Use static_cast to print numeric value of char limits to avoid printing characters.

    return 0;
}