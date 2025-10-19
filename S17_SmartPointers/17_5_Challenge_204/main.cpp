// Section 17
// Challenge 1 - Solution
/***********************************************************************************************************
Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.
   
   This function will prompt the user to enter an integer, create a shared_ptr to a Test object 
   initialized to the entered integer and add that shared pointer to the vector.
   
3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object
   
4. The main driver should look as follows:

    int main() {
        std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
        vec_ptr = make();
        std::cout << "How many data points do you want to enter: ";
        int num;
        std::cin >> num;
        fill(*vec_ptr, num);
        display(*vec_ptr);
        return 0;
    }
    
Below is a sample run for the user entering 3 at the console:
    
How many data points do you want to enter: 3
Enter data point [1] : 10
        Test constructor (10)
Enter data point [2] : 20
        Test constructor (20)
Enter data point [3] : 30
        Test constructor (30)
Displaying vector data
=======================
10
20
30
=======================
        Test destructor (10)
        Test destructor (20)
        Test destructor (30)

- I am providing the function prototypes in the code. 
However, feel free to modify these as you wish
***********************************************************************************************************/
#include <iostream>
#include <memory>   // for smart pointers
#include <vector>   // for std::vector

// Simple Test class
class Test {
private:
    int data;
public:
    // Default constructor
    Test() : data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    // Parameterized constructor
    Test(int data) : data{data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }

    int get_data() const { return data; }

    // Destructor
    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};

// Function prototypes
auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);


// ✅ Function to create and return a unique_ptr to a vector of shared_ptr<Test>
auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}


// ✅ Fill vector with shared_ptr<Test> dynamically from user input
void fill(std::vector<std::shared_ptr<Test>> &vec, int num)  {
    int temp;
    for (int i = 1; i <= num; ++i) {
        std::cout << "Enter data point [" << i << "] : ";
        std::cin >> temp;

        // Create a shared_ptr<Test> and add it to the vector
        vec.push_back(std::make_shared<Test>(temp));
    }
}


// ✅ Display the data stored in each Test object inside the vector
void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "\nDisplaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto &ptr : vec)
        std::cout << ptr->get_data() << std::endl;
    std::cout << "=======================" << std::endl;
}


int main() {
    // Step 1: Create unique_ptr to vector of shared_ptr<Test>
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;

    vec_ptr = make();  // Create and assign the vector

    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;

    // Step 2: Fill the vector with shared_ptr<Test>
    fill(*vec_ptr, num);

    // Step 3: Display the data
    display(*vec_ptr);

    return 0;  // Destructors are called automatically in reverse order
}
/*| Concept                        | Description                                                                  |
| ------------------------------ | ---------------------------------------------------------------------------- |
| `unique_ptr`                   | Sole owner of the resource. Automatically deallocates memory when destroyed. |
| `shared_ptr`                   | Shared ownership — reference counted. Deletes object only when count = 0.    |
| `make_unique<T>()`             | Safer and cleaner way to create a `unique_ptr`                               |
| `make_shared<T>()`             | More efficient than `shared_ptr<T>(new T)` — uses one memory allocation      |
| `std::vector<shared_ptr<T>>`   | Container that holds shared smart pointers                                   |
| Separation of responsibilities | Each function (`make`, `fill`, `display`) has a single clear responsibility. |
*/