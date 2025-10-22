// Section 13: Copy Constructor
//
// This example shows the problem with a *shallow copy* in C++.
//
// A shallow copy simply copies the address of a pointer, not the actual data
// that the pointer points to. This means two objects end up pointing to the
// same memory location. When both objects are destroyed, they both try to
// free the same memory, leading to a crash (double deletion).
//
// This example will compile and run, but will crash at runtime due to that issue.
// We will use this to understand why *deep copies* are necessary
// when working with raw pointers and dynamic memory allocation.

#include <iostream>
using namespace std;

class Shallow {
private:
    int *data;  // Pointer to an integer stored in the heap (dynamic memory)

public:
    // Setter: changes the value stored in the allocated memory
    void set_data_value(int d) { *data = d; }

    // Getter: returns the value stored in the allocated memory
    int get_data_value() { return *data; }

    // Constructor: dynamically allocates memory and initializes it
    Shallow(int d);

    // Copy Constructor: performs a *shallow copy* (copies pointer only)
    Shallow(const Shallow &source);

    // Destructor: frees the allocated memory
    ~Shallow();
};

// Constructor Definition
Shallow::Shallow(int d) {
    data = new int;   // allocate memory on the heap
    *data = d;        // store the passed value
    cout << "Constructor allocating memory and setting value: " << *data << endl;
}

// Copy Constructor Definition (Shallow Copy)
// This copies the pointer itself, not the data it points to.
// Both objects now point to the same memory address!
Shallow::Shallow(const Shallow &source)
    : data(source.data) // shallow copy of pointer
{
    cout << "Copy constructor - shallow copy performed" << endl;
}

// Destructor Definition
// Frees the memory that 'data' points to.
// If two objects share the same memory (due to shallow copy),
// both destructors will try to free the same memory address -> CRASH.
Shallow::~Shallow() {
    delete data;  // free the heap memory
    cout << "Destructor freeing data" << endl;
}

// A function that takes a Shallow object *by value*
// Passing by value means the copy constructor is called to make a copy.
void display_shallow(Shallow s) {
    cout << "Data value inside function: " << s.get_data_value() << endl;
}

// Main Function
int main() {
    // Step 1: Create the first object using the constructor
    Shallow obj1{100};

    // Step 2: Pass obj1 to a function BY VALUE.
    // This calls the copy constructor, creating a copy that shares the same pointer.
    display_shallow(obj1);

    // Step 3: Create a second object using the copy constructor directly.
    // Again, both obj1 and obj2 point to the same integer in memory.
    Shallow obj2{obj1};

    // Step 4: Change the value through obj2.
    // Since obj1 and obj2 share the same pointer, this also changes obj1's data.
    obj2.set_data_value(1000);

    // Step 5: When main ends, destructors for obj2 and obj1 both run.
    // They will both attempt to delete the same memory, causing a runtime crash.

    return 0;
}

/*
Summary Notes:
1. Shallow Copy:
   - A shallow copy simply copies the pointer value (address),
     not the actual data in memory.
   - Both objects end up pointing to the same memory.
   - When destructors run, both try to delete the same memory.
     This causes undefined behavior (usually a crash).

2. When does shallow copy happen?
   - When you define a copy constructor that copies only the pointer.
   - Or when the compiler-generated copy constructor does a member-wise copy
     and your class has raw pointers.

3. How to identify shallow copy issues:
   - If your class uses 'new' or allocates resources,
     you must ensure you implement a *deep copy* copy constructor.

4. Why this program crashes:
   - obj1 and obj2 share the same 'data' pointer.
   - When both objects are destroyed, they both call 'delete data;'.
   - The second delete attempts to free memory that is already freed.

5. Solution:
   - Implement a "Deep Copy Constructor" that allocates its own memory
     and copies the data value instead of the pointer address.
   - Example of a deep copy version:
         Shallow(const Shallow &source) {
             data = new int;
             *data = *source.data;
         }

6. Key takeaway:
   - If your class uses raw pointers and dynamic allocation (new/delete),
     always implement:
       - a custom Copy Constructor (deep copy),
       - a Destructor, and
       - possibly an Assignment Operator.
   - This is known as the "Rule of Three" in C++.
*/
