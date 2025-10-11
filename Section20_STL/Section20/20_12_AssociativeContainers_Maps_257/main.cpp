// Section 20 - Maps
// Demonstrates std::map with primitive and nested containers

#include <iostream>     // std::cout, std::endl
#include <map>          // std::map container
#include <set>          // std::set container
#include <string>       // std::string

// ==============================
// Display function for map<string, set<int>>
// ==============================
void display(const std::map<std::string, std::set<int>> &m) {
    std::cout << "[\n";
    for (const auto &elem : m) {
        std::cout << "  " << elem.first << ": [ ";
        for (const auto &val : elem.second)
            std::cout << val << " ";
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

// ==============================
// Generic display for map<K, V>
// ==============================
template <typename T1, typename T2>
void display(const std::map<T1, T2> &m) {
    std::cout << "[ ";
    for (const auto &elem : m) {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]" << std::endl;
}

// ==============================
// Test 1: Basic std::map<string, int> operations
// ==============================
void test1() {
    std::cout << "\nTest1 - Basic std::map<string, int>\n";

    std::map<std::string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);

    std::cout << "Inserting Anna:10 using std::pair...\n";
    m.insert(std::pair<std::string, int>("Anna", 10));
    display(m);

    std::cout << "Inserting Joe:5 using std::make_pair...\n";
    m.insert(std::make_pair("Joe", 5));
    display(m);

    std::cout << "Assigning Frank = 18 using operator[]...\n";
    m["Frank"] = 18;
    display(m);

    std::cout << "Updating Frank by adding 10...\n";
    m["Frank"] += 10;
    display(m);

    std::cout << "Erasing Frank from the map...\n";
    m.erase("Frank");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");
    if (it != m.end())
        std::cout << "Found: " << it->first << " : " << it->second << std::endl;

    std::cout << "Clearing the entire map...\n";
    m.clear();
    display(m);
}

// ==============================
// Test 2: Map with nested set values (map<string, set<int>>)
// ==============================
void test2() {
    std::cout << "\nTest2 - std::map<string, std::set<int>>\n";

    std::map<std::string, std::set<int>> grades {
        {"Larry", {100, 90}},
        {"Moe",   {94}},
        {"Curly", {80, 90, 100}}
    };
    display(grades);

    std::cout << "Inserting 95 into Larry's grade set...\n";
    grades["Larry"].insert(95);
    display(grades);

    std::cout << "Inserting 1000 into Moe's grade set using iterator...\n";
    auto it = grades.find("Moe");
    if (it != grades.end()) {
        it->second.insert(1000); // Accessing the set and inserting
    }
    display(grades);
}

// ==============================
// Main
// ==============================
int main() {
    test1();
    test2();
    return 0;
}
