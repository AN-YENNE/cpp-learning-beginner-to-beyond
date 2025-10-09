// Section 20
// Class templates

#include <iostream>
#include <string>
#include <vector>

// ----------- Template Class: Item -----------
// A generic class that holds a name (string) and a value of any type T
template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    // Constructor: initialize name and value
    Item(std::string name, T value) : name{name}, value{value} {}

    // Getter for name
    std::string get_name() const { return name; }

    // Getter for value
    T get_value() const { return value; }
};

// ----------- Template Struct: My_Pair -----------
// A simple struct that mimics a std::pair
// Holds two values of potentially different types (T1 and T2)
template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

int main() {
    std::cout << "----- Template Class: Item<int> -----" << std::endl;

    // Creates an Item object holding an int value
    Item<int> item1 {"Frank", 100};
    std::cout << "Item with <int>: " << item1.get_name() << " - " << item1.get_value() << std::endl;

    std::cout << "\n----- Template Class: Item<std::string> -----" << std::endl;

    // Item holding a string value instead of an int
    Item<std::string> item2 {"Frank", "Professor"};
    std::cout << "Item with <std::string>: " << item2.get_name() << " - " << item2.get_value() << std::endl;

    std::cout << "\n----- Nested Template: Item<Item<std::string>> -----" << std::endl;

    // An Item whose value is another Item (demonstrates nesting templates)
    Item<Item<std::string>> item3 {"Frank", {"C++", "Professor"}};
    std::cout << "Outer name: " << item3.get_name() << std::endl;
    std::cout << "Inner name: " << item3.get_value().get_name() << std::endl;
    std::cout << "Inner value: " << item3.get_value().get_value() << std::endl;

    std::cout << "\n----- Vector of Item<double> -----" << std::endl;

    // Creating a vector to store multiple Item<double> objects
    std::vector<Item<double>> vec {};
    vec.push_back(Item<double>("Larry", 100.0));
    vec.push_back(Item<double>("Moe", 200.0));
    vec.push_back(Item<double>("Curly", 300.0));

    // Loop through the vector and display each Item's name and value
    for (const auto &item : vec) {
        std::cout << "Name: " << item.get_name() << ", Value: " << item.get_value() << std::endl;
    }

    std::cout << "\n----- Template Struct: My_Pair<T1, T2> -----" << std::endl;

    // Demonstrating the use of a custom pair struct with different types
    My_Pair<std::string, int> p1 {"Frank", 100};       // string and int
    My_Pair<int, double> p2 {124, 13.6};               // int and double

    std::cout << "My_Pair<std::string, int>: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "My_Pair<int, double>: " << p2.first << ", " << p2.second << std::endl;

    return 0;
}


/*
| Concept                           | Description                                                                                    |
| --------------------------------- | ---------------------------------------------------------------------------------------------- |
| **Class Templates**               | `Item<T>` allows you to create class objects that can store any data type as `value`.          |
| **Nested Templates**              | `Item<Item<std::string>>` shows you can nest template instances.                               |
| **Template Structs**              | `My_Pair<T1, T2>` behaves like a simplified `std::pair`.                                       |
| **Vectors with Template Objects** | `std::vector<Item<double>>` shows how templates work with containers.                          |
| **Type Inference**                | No need to explicitly mention types when creating pairs or items if you're using constructors. |
*/