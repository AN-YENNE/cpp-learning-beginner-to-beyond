#include <iostream>
#include <memory>      // ✅ For std::unique_ptr and std::make_unique
#include <vector>      // ✅ For std::vector to store multiple unique_ptrs

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

// A simple class to demonstrate constructors, destructors, and ownership
class Test {
private:
    int data;
public:
    // Default constructor
    Test() : data{0} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }

    // Overloaded constructor
    Test(int data) : data{data} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }

    int get_data() const { return data; }

    // Destructor
    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }
};

using namespace std;

int main() {
    // --- Raw pointer version (unsafe) ---
    // Test *t1 = new Test {1000};     // Raw pointer
    // delete t1;                      // Must remember to delete manually

    // --- Safer: Using unique_ptr ---
    // Owns and deletes the object automatically

    // Creating unique_ptr with 'new' (not recommended)
    // unique_ptr<Test> t1 {new Test{100}};

    // Preferred: use make_unique (C++14 and later)
    // unique_ptr<Test> t2 = make_unique<Test>(1000);

    // Transferring ownership using std::move
    // unique_ptr<Test> t3;
    // t3 = std::move(t1);             // t1 no longer owns the resource
    // if (!t1)
    //     cout << "t1 is nullptr" << endl;

    // --- Using unique_ptr with custom Account types ---

    // Creating unique_ptr to a Checking_Account object
    unique_ptr<Account> a1 = make_unique<Checking_Account>("Moe", 5000);
    cout << *a1 << endl;              // Output: Checking_Account info
    a1->deposit(5000);                // Deposit money
    cout << *a1 << endl;

    // --- Storing unique_ptrs in a vector ---
    vector<unique_ptr<Account>> accounts;

    // Adding various types of accounts using make_unique
    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));

    // Looping through vector using const reference to unique_ptr
    for (const auto &acc : accounts)
        cout << *acc << endl;         // Dereference to call operator<<

    return 0;
}