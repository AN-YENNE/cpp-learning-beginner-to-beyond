// Section 13 Copy Constructor
//
// This example demonstrates a *deep copy* in C++.
//
// A deep copy creates a completely new copy of the dynamically allocated data
// rather than just copying the pointer address like a shallow copy does.
// This ensures each object manages its own separate memory,
// preventing runtime crashes caused by multiple destructors freeing the same memory.
//
// The opposite (shallow copy) copies only the pointer, which can cause problems
// when objects share and delete the same memory.
//
// Deep copy is essential whenever your class uses dynamic memory (with 'new').

#include <iostream>
using namespace std;

class Deep {
private:
    int *data;  // Pointer to integer data stored in heap memory

public:
    // Setter function to change the stored value
    void set_data_value(int d) { *data = d; }

    // Getter function to retrieve the stored value
    int get_data_value() { return *data; }

    // Constructor
    Deep(int d);

    // Copy Constructor (Deep Copy)
    Deep(const Deep &source);

    // Destructor
    ~Deep();
};

// Constructor Definition
// Allocates new memory and initializes the integer value
Deep::Deep(int d) {
    data = new int;   // Allocate dynamic memory
    *data = d;        // Store the value
    cout << "Constructor allocating memory and setting value: " << *data << endl;
}

// Copy Constructor Definition (Deep Copy)
// Allocates a new separate memory location and copies the value,
// so that each object owns its own copy of the data.
Deep::Deep(const Deep &source)
    : Deep{*source.data}  // Delegates to the constructor Deep(int d)
{
    cout << "Copy constructor - deep copy performed" << endl;
}

// Destructor Definition
// Releases the dynamically allocated memory safely.
// Each object will delete its own memory without affecting others.
Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

// A function that takes a Deep object *by value*
// Copy constructor is called when the argument is passed by value.
void display_deep(Deep s) {
    cout << "Data value inside function: " << s.get_data_value() << endl;
}

// Main Function
int main() {
    // Step 1: Create an object with a value
    Deep obj1{100};  // Calls the normal constructor

    // Step 2: Pass obj1 to the function by value
    // This triggers the deep copy constructor because the function
    // parameter is passed by value (a copy is made).
    display_deep(obj1);

    // Step 3: Create another object by copying obj1
    // The deep copy constructor ensures a new memory block is created.
    Deep obj2{obj1};

    // Step 4: Modify obj2's data
    // Since obj1 and obj2 have separate memory, this does not affect obj1.
    obj2.set_data_value(1000);

    // When main ends, both obj1 and obj2 destructors are called.
    // Each destructor deletes its own memory without conflict.
    return 0;
}

/*
Summary Notes:
1. Deep Copy:
   - A deep copy duplicates both the object and the dynamically allocated data it owns.
   - Each object has its own separate copy of the memory.
   - Prevents memory corruption and crashes.

2. Difference between Shallow Copy and Deep Copy:
   - Shallow Copy: copies pointer address (both objects share same memory).
   - Deep Copy: allocates new memory and copies the actual data.

3. When to use Deep Copy:
   - When your class uses raw pointers or any dynamically allocated memory.
   - Prevents double deletion and data corruption.

4. How it works here:
   - The copy constructor allocates its own memory using 'new int'.
   - It then copies the value from the source object (*source.data).
   - The destructor safely deletes only the memory it allocated.

5. The call 'Deep(const Deep &source) : Deep{*source.data}' 
   - Uses *delegating constructors* to reuse the logic in the main constructor
     instead of repeating memory allocation code.

6. Rule of Three:
   - If your class uses dynamic memory, you should define:
       a. Copy Constructor (for deep copying)
       b. Destructor (to release memory)
       c. Copy Assignment Operator (to handle assignment properly)
   - Together, these ensure safe copying, assignment, and destruction.

7. Key takeaway:
   - Deep copy ensures each object fully owns its own resources.
   - Always implement deep copy logic for classes that manage heap memory manually.
*/
