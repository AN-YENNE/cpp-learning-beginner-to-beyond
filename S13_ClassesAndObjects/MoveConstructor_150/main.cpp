// Section 13: Move Constructor
//
// This example demonstrates the move constructor and how it transfers ownership
// of dynamically allocated resources (a raw int* here) from one object to another.
// Moving avoids expensive deep copies and prevents double-deletes by setting the
// source pointer to nullptr after the move.
//
// Key ideas:
// 1) Copy constructor: allocates new memory and copies the value (deep copy).
// 2) Move constructor: steals the pointer and nulls out the source.
// 3) Destructor: releases memory if owned (pointer not null).
// 4) std::vector reallocation triggers moves/copies of its elements.
//    Temporaries like Move{10} are candidates for move construction.
//
// Notes for modern C++:
// - Prefer smart pointers (unique_ptr) instead of raw new/delete.
// - If a class manages a resource, consider the Rule of Five:
//     copy ctor, copy assignment, move ctor, move assignment, destructor.

#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int* data;  // owns a heap-allocated int

public:
    // Modifiers and accessors
    void set_data_value(int d) { *data = d; }
    int get_data_value() const { return *data; }

    // Constructors and destructor
    Move(int d);                   // normal constructor
    Move(const Move& source);      // copy constructor (deep copy)
    Move(Move&& source) noexcept;  // move constructor (steal pointer)
    ~Move();                       // destructor

    // Tip: In a complete design, also implement copy assignment and move assignment.
    // They are omitted here to keep the example focused on the move constructor.
};

// Normal constructor
// Allocates and initializes a new int on the heap.
Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor: allocated and set value to " << *data << endl;
}

// Copy constructor (deep copy)
// Allocates new memory and copies the value so each object owns its own memory.
Move::Move(const Move& source)
    : Move{*source.data}  // delegate to the normal constructor for allocation
{
    cout << "Copy constructor: deep-copied value " << *data << endl;
}

// Move constructor (transfer ownership)
// Steals the pointer from 'source' and sets source.data to nullptr so that
// only this object will delete the resource.
Move::Move(Move&& source) noexcept
    : data{source.data}            // take ownership of the pointer
{
    source.data = nullptr;         // release ownership from source
    if (data != nullptr)
        cout << "Move constructor: moved resource with value " << *data << endl;
    else
        cout << "Move constructor: source was empty (nullptr)" << endl;
}

// Destructor
// Deletes the owned pointer if not null. Safe to call delete on nullptr,
// but we branch to print more helpful messages.
Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor: freeing resource with value " << *data << endl;
    } else {
        cout << "Destructor: nothing to free (nullptr)" << endl;
    }
    delete data;  // delete is safe for nullptr
}

int main() {
    // Vector to demonstrate move behavior during push_back and potential reallocations
    vector<Move> vec;

    // Reserve some capacity to control reallocations (optional).
    // Comment out the next line to force more reallocations and observe more moves.
    // vec.reserve(8);

    // Each push_back(Move{X}) constructs a temporary Move and then places it into the vector.
    // Because the argument is an rvalue (temporary), the move constructor is preferred.
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    // When main returns, vec destroys its elements.
    // Destructors run for each element; moved-from temporaries had their data set to nullptr,
    // so their destructors will report "nothing to free (nullptr)".

    return 0;
}

/*
Summary notes:
1) Move vs Copy:
   - Copy creates a second, independent ownership by allocating new memory and copying the value.
   - Move transfers ownership by pointer-steal and nulling the source pointer.

2) Why move is efficient:
   - No new allocation and no value copying for large data; only pointer reassignment.
   - Particularly beneficial in containers like std::vector during reallocation.

3) After a move:
   - The moved-from object remains valid but in a valid-but-unspecified state.
   - In this pattern, we set the pointer to nullptr, which makes the state explicit and safe.

4) Rule of Five (if you manage a resource):
   - Copy constructor
   - Copy assignment operator
   - Move constructor
   - Move assignment operator
   - Destructor

5) Prefer RAII and smart pointers:
   - Using std::unique_ptr<int> data; removes the need to write custom destructor and move logic.
   - Copying would be deleted by default for unique_ptr, which avoids accidental shallow copies.
*/
