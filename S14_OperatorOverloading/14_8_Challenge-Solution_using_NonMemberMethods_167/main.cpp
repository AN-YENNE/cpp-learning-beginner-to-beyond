// Section 14
// Challenge - Solution 2 (Non-member friend functions)
//
// Demonstrates non-member operator overloads with generic names and
// meaningful console messages.
// --------------------------------------------------------------
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // Equality and inequality with generic tokens
    Mystring a{"alpha"};
    Mystring b{"alpha"};
    cout << "[Check] a == b ? " << (a == b) << " (expect true)" << endl;
    cout << "[Check] a != b ? " << (a != b) << " (expect false)" << endl;

    b = "bravo";
    cout << "[Check] a == b ? " << (a == b) << " (expect false)" << endl;
    cout << "[Check] a != b ? " << (a != b) << " (expect true)" << endl;
    cout << "[Order] a < b  ? " << (a < b)  << " (lexical compare)" << endl;
    cout << "[Order] a > b  ? " << (a > b)  << " (lexical compare)" << endl;

    // Lowercase via unary minus
    Mystring s1{"ALPHA"};
    s1 = -s1;
    cout << "[Lower] s1 -> " << s1 << endl;

    // Concatenation and concat-assign
    s1 = s1 + "***";
    cout << "[Concat] s1 + \"***\" -> " << s1 << endl;

    s1 += "---";
    cout << "[Concat-Assign] s1 += \"---\" -> " << s1 << endl;

    // Repeat and repeat-assign with numbers
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << "[Repeat] \"12345\" * 3 -> " << s1 << " (expect 123451234512345)" << endl;

    Mystring s3{"abcdef"};
    s3 *= 5;
    cout << "[Repeat-Assign] \"abcdef\" *= 5 -> " << s3 << endl;

    // Interactive repeat example
    Mystring repeat_string;
    int repeat_times{};
    cout << "[Input] Enter a single word to repeat: ";
    cin >> repeat_string;
    cout << "[Input] Enter how many times to repeat: ";
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "[Result] Repeated string -> " << repeat_string << endl;

    // Show temporary usage with operator*
    cout << "[Preview] Repeating it 2 more times -> " << (repeat_string * 2) << endl;

    // Multi-step concatenation
    repeat_string = "Echo";
    cout << "[Multi-Concat] Echo + Echo + Echo -> " << (repeat_string + repeat_string + repeat_string) << endl;

    // Pre and post increment semantics (uppercase)
    Mystring s{"delta"};
    ++s; // uppercase in place
    cout << "[Upper Pre] ++s -> " << s << " (expect DELTA)" << endl;

    s = -s; // back to lowercase
    cout << "[Lower] -s -> " << s << " (expect delta)" << endl;

    Mystring result;
    result = ++s; // result gets uppercase too
    cout << "[Upper Pre Assign] s -> " << s << " | result -> " << result << endl;

    s = "delta";
    s++; // post-increment: s becomes uppercase, returned value is old lowercase
    cout << "[Upper Post] s++ then s -> " << s << " (expect DELTA)" << endl;

    s = -s; // lowercase again
    cout << "[Lower Again] s -> " << s << " (expect delta)" << endl;

    result = s++; // result receives old lowercase, s becomes uppercase
    cout << "[Post Assign] s (now uppercase) -> " << s << " | result (old lowercase) -> " << result << endl;

    // Demonstrate non-member + allowing literal on the left side
    Mystring joined = "Left" + Mystring{"Right"};
    cout << "[Literal Left] \"Left\" + Mystring(\"Right\") -> " << joined << endl;

    return 0;
}

/*
Summary Notes:
1) Non-member friend operators:
   - Allow implicit conversions on both operands (e.g., "Left" + myStr).
   - Suitable for symmetric operations like +, ==, <, >.

2) Operators implemented:
   -: lowercase copy
   +, +=: concatenation
   ==, !=, <, >: comparisons using std::strcmp
   * , *=: repetition via simple loop (reuses +)
   ++ (pre/post): in-place uppercase

3) I/O:
   - operator>> reads a single token (whitespace-delimited).
   - For multi-word input with spaces, use std::getline into std::string
     and then assign to Mystring.

4) Memory:
   - Class owns a raw char*; copy/move operations are provided to avoid leaks.
   - In real-world code, prefer std::string or a smart wrapper to avoid manual new/delete.
*/
