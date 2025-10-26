// Section 14: Challenge - Solution 1 (Member methods)
//
// This driver exercises the overloaded operators and prints meaningful messages.
// Generic labels are used instead of personal names to keep examples neutral.
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // Equality and inequality checks
    Mystring a{"alpha"};
    Mystring b{"alpha"};
    cout << "[Check] a == b ? " << (a == b) << " (expect true)" << endl;
    cout << "[Check] a != b ? " << (a != b) << " (expect false)" << endl;

    // Change b and compare ordering
    b = "bravo";
    cout << "[Check] a == b ? " << (a == b) << " (expect false)" << endl;
    cout << "[Check] a != b ? " << (a != b) << " (expect true)" << endl;
    cout << "[Order] a < b  ? " << (a < b)  << " (lexical)" << endl;
    cout << "[Order] a > b  ? " << (a > b)  << " (lexical)" << endl;

    // Unary minus makes lowercase
    Mystring s1{"ALPHA"};
    s1 = -s1;
    cout << "[Lower] s1 to lowercase: " << s1 << endl;

    // Concatenation and concat-assign
    s1 = s1 + "***";
    cout << "[Concat] s1 + \"***\" -> " << s1 << endl;

    s1 += "---";
    cout << "[Concat-Assign] s1 += \"---\" -> " << s1 << endl;

    // Repeat and repeat-assign
    Mystring s2{"123"};
    Mystring rep = s2 * 3;    // 123123123
    cout << "[Repeat] s2 * 3 -> " << rep << endl;

    Mystring s3{"abcd"};
    s3 *= 4;                  // abcdabcdabcdabcd
    cout << "[Repeat-Assign] s3 *= 4 -> " << s3 << endl;

    // Interactive repeat example
    Mystring repeat_string;
    int repeat_times{};
    cout << "[Input] Enter a single word to repeat: ";
    cin >> repeat_string;
    cout << "[Input] How many times should it repeat? ";
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "[Result] Repeated string: " << repeat_string << endl;

    // Show temporary usage with operator*
    cout << "[Preview] Repeating the string 2 more times: " << (repeat_string * 2) << endl;

    // Multi-step concatenation
    repeat_string = "Echo";
    cout << "[Multi-Concat] Echo + Echo + Echo -> " << (repeat_string + repeat_string + repeat_string) << endl;

    // Combine concat-assign with repeat
    repeat_string += (repeat_string * 2);
    cout << "[Combine] Echo += Echo*2 -> " << repeat_string << endl;

    // Pre and post increment semantics (uppercase transformation)
    Mystring s = "delta";
    ++s;                        // pre-increment: make uppercase, return updated
    cout << "[Upper Pre] ++s -> " << s << " (expect DELTA)" << endl;

    s = -s;                     // make lowercase again
    cout << "[Lower] -s  -> " << s << " (expect delta)" << endl;

    Mystring result;
    result = ++s;               // s becomes uppercase; result receives uppercase
    cout << "[Upper Pre Assign] s -> " << s << " | result -> " << result << endl;

    s = "delta";
    s++;                        // post-increment: returns old lowercase value
    cout << "[Upper Post] s++ then print s -> " << s << " (expect DELTA)" << endl;

    s = -s;                     // back to lowercase
    cout << "[Lower Again] s -> " << s << " (expect delta)" << endl;

    result = s++;               // result gets old lowercase, s becomes uppercase
    cout << "[Post Assign] s (now uppercase) -> " << s << " | result (old lowercase) -> " << result << endl;

    return 0;
}

/*
Notes:
1) Operators implemented as member methods:
   -: lowercase copy
   +: concatenation
   ==, !=, <, >: comparisons using std::strcmp
   +=: concat-assign implemented via operator+
   * : repeat implemented via loop and operator+
   *=: repeat-assign implemented via operator*
   ++ (pre): in-place uppercase, returns *this
   ++ (post): returns old value, then uppercase in place

2) Design:
   - Keep operations small and reuse existing operators to avoid duplication.
   - For performance on large repeats, consider a single buffer approach.

3) Safety:
   - This class owns a raw char*; copy and move operations are defined to avoid leaks.
   - In real projects, prefer std::string to avoid manual memory management.
*/
