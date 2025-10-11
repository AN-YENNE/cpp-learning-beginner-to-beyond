#include <cctype>       // for std::isalpha, std::toupper
#include <deque>        // double-ended queue
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>      // for std::setw

// Returns true if the input string 's' is a palindrome, false otherwise.
bool is_palindrome(const std::string& s)
{
    std::deque<char> d;

    // 1. Clean and normalize the input string:
    //    - Remove non-alphabet characters
    //    - Convert to uppercase
    for (char c : s)
        if (std::isalpha(c))
            d.push_back(std::toupper(c));  // Store uppercase letter in deque

    // 2. Compare characters from front and back
    while (d.size() > 1) {
        char front = d.front();
        char back = d.back();
        d.pop_front();   // remove from front
        d.pop_back();    // remove from back

        if (front != back)
            return false;   // Mismatch found => not a palindrome
    }

    // If loop finishes, it's a palindrome
    return true;
}

int main()
{
    // A variety of test cases: single letters, simple palindromes, phrases, non-palindromes
    std::vector<std::string> test_strings{
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a palindrome", "palindrome"
    };

    std::cout << std::boolalpha;  // print 'true'/'false' instead of 1/0
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    // Test each string
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }

    return 0;
}

/*
| Feature                     | Explanation                                                                           |
| --------------------------- | ------------------------------------------------------------------------------------- |
| `std::deque<char>`          | Allows fast access from both front and back. Ideal for comparing mirrored characters. |
| `std::isalpha(c)`           | Ensures only letters are considered (ignores digits, punctuation).                    |
| `std::toupper(c)`           | Makes the comparison case-insensitive.                                                |
| `std::boolalpha`            | Formats boolean output as `true` / `false`.                                           |
| `std::setw()` + `std::left` | Formats output into aligned columns.                                                  |
| `std::vector<std::string>`  | Stores multiple test strings to loop over and validate.                               |
*/