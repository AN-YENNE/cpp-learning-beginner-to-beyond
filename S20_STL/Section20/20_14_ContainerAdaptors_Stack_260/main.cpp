// Section 20 - Stack Example

#include <iostream>     // std::cout, std::endl
#include <stack>        // std::stack container adapter
#include <vector>       // For using vector as underlying container
#include <list>         // For using list as underlying container

// ============================================================
// Display the contents of a stack by value (non-destructive)
// NOTE: Stack is passed by value to avoid modifying original.
// ============================================================

template <typename T>
void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "===== Stack Operations Demo =====" << std::endl;

    // Stack of integers using default underlying container (deque)
    std::stack<int> s;

    // Stack using alternative underlying containers
    std::stack<int, std::vector<int>> s1;  // using vector
    std::stack<int, std::list<int>> s2;    // using list
    std::stack<int, std::deque<int>> s3;   // using deque explicitly

    std::cout << "\n-- Pushing initial elements: 1,2,3,4,5 --" << std::endl;
    for (int i: {1, 2, 3, 4, 5})
        s.push(i);
    display(s);

    std::cout << "\n-- Pushing 100 onto stack --" << std::endl;
    s.push(100);
    display(s);

    std::cout << "\n-- Popping top two elements --" << std::endl;
    s.pop();
    s.pop();
    display(s);

    std::cout << "\n-- Clearing entire stack --" << std::endl;
    while (!s.empty())
        s.pop();
    display(s);

    std::cout << "Stack size after clearing: " << s.size() << std::endl;

    std::cout << "\n-- Pushing 10 onto empty stack --" << std::endl;
    s.push(10);
    display(s);

    std::cout << "\n-- Modifying top element to 100 --" << std::endl;
    s.top() = 100;
    display(s);

    std::cout << "===== End of Stack Demo =====" << std::endl;
    return 0;
}
