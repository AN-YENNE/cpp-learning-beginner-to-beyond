#include <iostream>
#include <memory>  // Required for shared_ptr and weak_ptr

using namespace std;

class B;  // ✅ Forward declaration — needed because class A uses B before it’s fully defined

class A {
    std::shared_ptr<B> b_ptr;  // 🔁 Strong shared ownership of B
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }

    A()  { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B {
    std::weak_ptr<A> a_ptr;  // ✅ Weak reference to A to break circular reference, if it is shared_ptr, then destructor will never be called
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;  // ❗ This does NOT increase reference count of A
    }

    B()  { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main() {
    // 🔁 Create shared instances of A and B
    shared_ptr<A> a = make_shared<A>();  // Reference count: 1
    shared_ptr<B> b = make_shared<B>();  // Reference count: 1

    // 🔗 Set up mutual references
    a->set_B(b);  // A now holds a shared_ptr to B ➜ b’s count = 2
    b->set_A(a);  // B now holds a weak_ptr to A ➜ a’s count = stays 1 (not incremented!)

    // ✅ When main exits, both shared_ptr go out of scope
    // Since weak_ptr doesn’t affect reference count, both A and B are destroyed

    return 0;
}
/*
| Concept              | Explanation                                                              |
| -------------------- | ------------------------------------------------------------------------ |
| `std::shared_ptr<T>` | Smart pointer with shared ownership. Increments use count.               |
| `std::weak_ptr<T>`   | Non-owning smart pointer. Doesn't increment use count.                   |
| Circular reference   | When A owns B and B owns A ➜ causes memory leak unless weak_ptr is used. |
| Forward declaration  | Required because A and B refer to each other.                            |
| `make_shared<T>()`   | Safer and more efficient way to create shared_ptr.                       |
| `use_count()`        | Returns how many shared_ptr instances currently own the object.          |
*/