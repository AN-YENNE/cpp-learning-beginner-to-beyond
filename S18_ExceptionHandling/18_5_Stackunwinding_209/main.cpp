// Section 18
// Stack Unwinding
#include <iostream>

void func_a();
void func_b();
void func_c();

void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl;
}

void func_b() {
    std::cout << "Starting func_b" << std::endl;
    try {
        func_c();
    }
    catch (int &ex) {
        std::cout << "Caught error in func_b" << std::endl;
    }
    std::cout << "Ending func_b" << std::endl;
}

void func_c() {
    std::cout << "Starting func_c" << std::endl;
    throw 100;
    std::cout << "Ending func_c" << std::endl; // This will never be executed
}

int main() {
    std::cout << "Starting main" << std::endl;
    try {
        func_a();
    }
    catch (int &ex) {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "Finishing main" << std::endl;
    return 0;
}
/*This demonstrates stack unwinding, which occurs when an exception is thrown and the program starts "unwinding" the call stack to find a matching catch.

The throw in func_c() is caught by the catch block in func_b().

Because the exception is caught in func_b(), it does not propagate to func_a() or main().*/