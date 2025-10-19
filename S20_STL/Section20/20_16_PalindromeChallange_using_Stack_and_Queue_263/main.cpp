// Section 20 - Challenge 4: Palindrome Check Using Stack and Queue

#include <iostream>     // std::cout, std::endl
#include <stack>        // std::stack for LIFO
#include <queue>        // std::queue for FIFO
#include <cctype>       // std::isalpha, std::toupper
#include <string>       // std::string
#include <vector>       // std::vector
#include <iomanip>      // std::setw, std::boolalpha

// ============================================================
// Checks if the input string is a palindrome (ignoring case and non-alphabetic characters)
// Uses both a stack (LIFO) and a queue (FIFO) for comparison
// ============================================================

bool is_palindrome(const std::string& s) {
    std::stack<char> stk;
    std::queue<char> q;

    // Load stack and queue with uppercase alphabetic characters
    for (char c : s) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
            stk.push(c);
            q.push(c);
        }
    }

    // Compare characters from both ends
    while (!q.empty()) {
        char front = q.front(); q.pop();
        char top   = stk.top(); stk.pop();
        if (front != top)
            return false;
    }

    return true;
}

// ============================================================
// Driver code to test is_palindrome with various strings
// ============================================================

int main() {
    std::vector<std::string> test_strings{
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a palindrome", "palindrome"
    };

    std::cout << "===== Palindrome Test =====" << std::endl;
    std::cout << std::boolalpha;  // Print "true"/"false" instead of 1/0
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    for (const auto& str : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(str) << str << std::endl;
    }

    std::cout << "==============================" << std::endl;
    return 0;
}
