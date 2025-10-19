#include <iostream>
#include <memory>  // For std::shared_ptr

// Simple Test class for demonstration
class Test {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    Test(int data) : data {data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    int get_data() const { return data; }

    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};

//  Custom function to delete Test objects
void my_deleter(Test *ptr) {
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;  //  Manual deletion here — just like the default deleter
}

int main() {

    {
        //  Using a custom **function** as a deleter
        std::shared_ptr<Test> ptr1 { new Test{100}, my_deleter };
        //  The custom deleter will be invoked when ptr1 goes out of scope
    }

    std::cout << "====================" << std::endl;

    {
        //  Using a **lambda expression** as a custom deleter
        std::shared_ptr<Test> ptr2 (
            new Test{1000},     // dynamically allocated object
            [] (Test *ptr) {    // lambda acting as deleter
                std::cout << "\tUsing my custom lambda deleter" << std::endl;
                delete ptr;
            }
        );
    }

    return 0;
}
/*
| Use Case                        | Example                                                       |
| ------------------------------- | ------------------------------------------------------------- |
| Logging or debugging            | Track when and how objects are deleted                        |
| Releasing non-heap resources    | E.g., file handles, sockets, or custom memory pools           |
| Interfacing with C-style APIs   | E.g., freeing resources allocated via `malloc`, `fopen`, etc. |
| Managing special deletion logic | Deleting with a custom allocator or tracking statistics       |

 * 
 * | Concept                       | Explanation                                                                  |
| ----------------------------- | ---------------------------------------------------------------------------- |
| `shared_ptr<T>`               | Smart pointer with shared ownership. Calls deleter when last reference dies. |
| Custom deleter                | Function or lambda that replaces the default `delete` operation              |
| `shared_ptr<T>(ptr, deleter)` | Creates a shared pointer that will call the given deleter on destruction     |
| `[] (T *ptr) { ... }`         | Lambda expression used to define inline custom logic for deletion            |
| `delete ptr`                  | Required inside the deleter to free memory manually                          |

 * */