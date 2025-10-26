// Overloaded insertion (<<) and extraction (>>) operators
// Demonstration with generic names and meaningful messages.
// --------------------------------------------------------------
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring first {"Alpha"};
    Mystring second {"Beta"};
    Mystring third;  // empty, to be read from input

    cout << "[Prompt] Enter a single word for the third label: ";
    cin >> third;  // uses overloaded operator>> (reads one token)
    cout << "[Info] You entered third = \"" << third << "\"" << endl;

    cout << "[Info] Current labels: " << first << ", " << second << ", " << third << endl;

    cout << "\n[Prompt] Enter three words (space separated) to replace all labels: ";
    cin >> first >> second >> third;  // chaining operator>> works as expected

    cout << "[Result] Updated labels: " << first << ", " << second << ", " << third << endl;

    cout << "\n[Note] The stream operators here treat whitespace as a separator." << endl;
    cout << "[Note] For multi-word inputs with spaces, consider getline and a custom parser." << endl;

    return 0;
}

/*
Summary Notes:
1) operator<< (insertion) prints the character sequence of Mystring:
       std::cout << my;  // calls friend operator<<(ostream&, const Mystring&)

2) operator>> (extraction) reads a single token (up to whitespace) into Mystring:
       std::cin >> my;   // calls friend operator>>(istream&, Mystring&)

3) Why implement as non-member friends?
   - They need access to private internals for efficient I/O.
   - They support chaining naturally: std::cin >> a >> b >> c;

4) Safety considerations:
   - This implementation uses std::string as a temporary to avoid fixed-size buffers.
   - If you require multi-word inputs with spaces, you can:
       a) Use std::getline to read the entire line into std::string
       b) Then assign to Mystring using Mystring{line.c_str()}

5) Rule of Five context:
   - Because Mystring owns a heap resource (char*), we provided:
       copy ctor, move ctor, copy assign, move assign, destructor.
   - This ensures correct behavior across copies, moves, and I/O operations.
*/