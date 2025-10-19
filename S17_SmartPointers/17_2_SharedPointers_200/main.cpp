#include <iostream>
#include <memory>   // ✅ Required for smart pointers like std::shared_ptr
#include <vector>   // ✅ Required for std::vector

#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

// A helper class to demonstrate constructor/destructor behavior
class Test {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }

    Test(int data) : data {data} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }

    int get_data() const { return data; }

    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }
};

// Accepts a shared_ptr and prints how many owners currently share it
void func(std::shared_ptr<Test> p) {
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main() {
    // ============================================================================
    // EXAMPLE 1: Basic usage of shared_ptr with use_count
    // ============================================================================
    /*
    std::shared_ptr<int> p1 {new int {100} };
    std::cout << "Use count: " << p1.use_count() << std::endl;  // ➜ 1

    std::shared_ptr<int> p2 { p1 }; // Shared ownership
    std::cout << "Use count: " << p1.use_count() << std::endl;  // ➜ 2

    p1.reset();  // p1 releases its ownership
    std::cout << "Use count: " << p1.use_count() << std::endl;  // ➜ 0 (p1 is now null)
    std::cout << "Use count: " << p2.use_count() << std::endl;  // ➜ 1 (p2 still owns)
    */

    // ============================================================================
    // EXAMPLE 2: Use count increases/decreases with scope
    // ============================================================================
    /*
    std::cout << "\n==========================================" << std::endl;
    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);  // use_count = 1
    func(ptr);                                                // passed by value ➜ use_count = 2 (temporarily)
    std::cout << "Use count: " << ptr.use_count() << std::endl;

    {
        std::shared_ptr<Test> ptr1 = ptr;                     // use_count = 2
        std::cout << "Use count: " << ptr.use_count() << std::endl;

        {
            std::shared_ptr<Test> ptr2 = ptr;                 // use_count = 3
            std::cout << "Use count: " << ptr.use_count() << std::endl;
            ptr.reset();                                      // ptr releases ownership ➜ use_count = 2
        }

        std::cout << "Use count: " << ptr.use_count() << std::endl; // ptr is nullptr ➜ 0
    }

    std::cout << "Use count: " << ptr.use_count() << std::endl;     // ptr is still nullptr
    */

    // ============================================================================
    // EXAMPLE 3: Using shared_ptr with polymorphic classes (Accounts)
    // ============================================================================

    std::cout << "\n==========================================" << std::endl;

    // Creating shared_ptr to Account-derived objects
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);

    std::vector<std::shared_ptr<Account>> accounts;

    // All 3 shared_ptrs are copied into the vector ➜ use_count increases
    accounts.push_back(acc1);  // acc1 use_count = 2
    accounts.push_back(acc2);  // acc2 use_count = 2
    accounts.push_back(acc3);  // acc3 use_count = 2

    // Loop through the vector and print details and reference counts
    for (const auto &acc : accounts) {
        std::cout << *acc << std::endl;               // Calls virtual operator<<
        std::cout << "Use count: " << acc.use_count() << std::endl;
    }

    std::cout << "==========================================" << std::endl;
    return 0;
}
/*| Concept                           | Explanation                                                                                                            |
| --------------------------------- | ---------------------------------------------------------------------------------------------------------------------- |
| `std::shared_ptr<T>`              | Smart pointer that allows **multiple owners** of the same object                                                       |
| `use_count()`                     | Returns the number of `shared_ptr` instances managing the object                                                       |
| `reset()`                         | Releases ownership from that specific `shared_ptr` (may delete the object if last)                                     |
| `make_shared<T>(...)`             | Safe and efficient way to create `shared_ptr` instances                                                                |
| Shared ownership                  | Multiple `shared_ptr` can point to the same object. When the **last owner** goes out of scope, the object is destroyed |
| `std::vector<std::shared_ptr<T>>` | Very common pattern for managing dynamically allocated polymorphic objects                                             |
*/