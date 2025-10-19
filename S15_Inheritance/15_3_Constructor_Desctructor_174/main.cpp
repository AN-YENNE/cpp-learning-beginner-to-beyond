// Section 15
// Constructors and Destructors

#include <iostream>

using namespace std;

class Base {
private:
    int value;

public:
    Base()
        : value{0} {
        cout << "Base no-args constructor" << endl;
    }

    Base(int x)
        : value{x} {
        cout << "Base (int) overloaded constructor" << endl;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    // Inherit Base's constructors using 'using' declaration
    using Base::Base;

private:
    int doubled_value;

public:
    Derived()
        : doubled_value{0} {
        cout << "Derived no-args constructor" << endl;
    }

    Derived(int x)
        : doubled_value{x * 2} {
        cout << "Derived (int) overloaded constructor" << endl;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    // Base b;           // calls Base no-args constructor
    // Base b{100};      // calls Base(int) constructor
    // Derived d;        // calls Derived no-args, and Base no-args

    Derived d{1000};     // calls Derived(int), and Base(int)

    return 0;
}
/*
When Derived d{1000}; is executed:

Derived(int) constructor is called.

Since no explicit Base constructor is called, the default one would be used — but because of using Base::Base, the compiler checks if it needs to call a Base(int) constructor. In this case, it does.

Base(int) constructor runs before Derived(int).

Then, destructors run in reverse order when the object goes out of scope:

Derived destructor

Base destructor
 */