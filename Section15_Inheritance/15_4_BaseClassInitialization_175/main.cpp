// Section 15
// Base class initialization explicitely from derived class

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
private:
    int doubled_value;

public:
    Derived()
        : Base{}, doubled_value{0} {
        cout << "Derived no-args constructor" << endl;
    }

    Derived(int x)
        : Base{x}, doubled_value{x * 2} {
        cout << "Derived (int) constructor" << endl;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    // Derived d;          // calls Derived() and Base()
    Derived d{1000};       // calls Derived(int) and Base(int)

    return 0;
}
/*For Derived d{1000};:

Derived(int) constructor runs.

Inside it, Base(int) is explicitly called with x = 1000.

After construction, destructors run in reverse order:

First, Derived destructor.

Then, Base destructor.*/