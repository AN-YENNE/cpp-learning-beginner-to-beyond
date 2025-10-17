// Section 15
// Copy constructor and operator=

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
        cout << "int Base constructor" << endl;
    }

    Base(const Base& other)
        : value{other.value} {
        cout << "Base copy constructor" << endl;
    }

    Base& operator=(const Base& rhs) {
        cout << "Base operator=" << endl;

        if (this == &rhs)
            return *this;  // check for self-assignment

        value = rhs.value;
        return *this;
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
        : Base{} {
        cout << "Derived no-args constructor" << endl;
    }

    Derived(int x)
        : Base{x}, doubled_value{x * 2} {
        cout << "int Derived constructor" << endl;
    }

    Derived(const Derived& other)
        : Base(other), doubled_value{other.doubled_value} {
        cout << "Derived copy constructor" << endl;
    }

    Derived& operator=(const Derived& rhs) {
        cout << "Derived operator=" << endl;

        if (this == &rhs)
            return *this;

        Base::operator=(rhs);           // call base class assignment
        doubled_value = rhs.doubled_value;
        return *this;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    // Base b{100};    // calls Base(int) constructor
    // Base b1{b};     // calls Base copy constructor
    // b = b1;         // calls Base operator=

    Derived d{100};     // calls Derived(int) and Base(int)
    Derived d1{d};      // calls Derived copy constructor and Base copy constructor
    d = d1;             // calls Derived operator= and Base operator=

    return 0;
}
/*For these lines:
Derived d{100};
Derived d1{d};
d = d1;


Here's what happens:

Derived(int) runs
→ Calls Base(int)
→ Then sets doubled_value

Derived(const Derived&) runs
→ Calls Base(const Base&)
→ Then copies doubled_value

Derived::operator= runs
→ Calls Base::operator=
→ Then assigns doubled_value

When main() ends, destructors run in reverse order:

Derived destructor

Base destructor
For both objects: d and d1*/