// Section 15
// Protected members and class access

#include <iostream>

using namespace std;

class Base {
    // Friends of Base have access to all members

public:
    int a {0}; // public member: accessible from anywhere

    void display() {
        // Member functions of the class can access all members: public, protected, and private
        std::cout << a << ", " << b << ", " << c << endl;
    }

protected:
    int b {0}; // protected member: accessible within Base and Derived

private:
    int c {0}; // private member: accessible only within Base
};

class Derived : public Base {
    // Friends of Derived have access only to what Derived has access to from Base

    // a becomes public in Derived
    // b becomes protected in Derived
    // c is not accessible in Derived

public:
    void access_base_members() {
        a = 100;    // OK: public member inherited from Base
        b = 200;    // OK: protected member inherited from Base
        // c = 300; // Error: private member not accessible
    }
};

int main() {
    cout << "=== Base member access from base object ===========" << endl;
    Base base;
    base.a = 100;   // OK: public member
    // base.b = 200; // Error: protected member not accessible from outside the class
    // base.c = 300; // Error: private member not accessible from outside the class

    cout << "=== Base member access from derived object ===========" << endl;
    Derived d;
    d.a = 100;      // OK: a is public in Derived
    // d.b = 200;    // Error: b is protected in Derived, not accessible outside the class
    // d.c = 300;    // Error: c is private in Base, not accessible in Derived

    return 0;
}

/*
Public members are accessible from anywhere.

Protected members are accessible in the class and derived classes but not outside.

Private members are accessible only in the class where they are defined.

Class methods (like display) have access to all members of the class, including private and protected.
*/