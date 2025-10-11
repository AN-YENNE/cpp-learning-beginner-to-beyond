// Section 20 - Queue Example

#include <iostream>     // std::cout, std::endl
#include <queue>        // std::queue container adapter

// ============================================================
// Display the contents of a queue by value (non-destructive)
// NOTE: The queue is passed by value, so the original is not modified.
// ============================================================

template <typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        T elem = q.front();   // Access front element
        q.pop();              // Remove front
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "===== Queue Operations Demo =====" << std::endl;

    std::queue<int> q;

    std::cout << "\n-- Pushing elements: 1,2,3,4,5 --" << std::endl;
    for (int i: {1, 2, 3, 4, 5})
        q.push(i);
    display(q);

    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element:  " << q.back() << std::endl;

    std::cout << "\n-- Pushing 100 --" << std::endl;
    q.push(100);
    display(q);

    std::cout << "\n-- Popping two elements --" << std::endl;
    q.pop();
    q.pop();
    display(q);

    std::cout << "\n-- Clearing the queue --" << std::endl;
    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Queue size after clearing: " << q.size() << std::endl;

    std::cout << "\n-- Pushing 10, 100, 1000 --" << std::endl;
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element:  " << q.back() << std::endl;

    std::cout << "\n-- Modifying front and back values --" << std::endl;
    q.front() = 5;
    q.back() = 5000;
    display(q);

    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element:  " << q.back() << std::endl;

    std::cout << "===== End of Queue Demo =====" << std::endl;
    return 0;
}
