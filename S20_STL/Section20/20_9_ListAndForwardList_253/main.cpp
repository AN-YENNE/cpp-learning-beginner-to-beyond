// Section 20 - List & Forward List Demo

#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <string>

// =================== Person Class ===================
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age} {}

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }

    bool operator==(const Person &rhs) const {
        return this->name == rhs.name && this->age == rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// =================== Display Functions ===================
template <typename T>
void display(const std::list<T> &l) {
    std::cout << "[ ";
    for (const auto &elem : l)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

template <typename T>
void display(const std::forward_list<T> &fl) {
    std::cout << "[ ";
    for (const auto &elem : fl)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

// =================== List Test Functions ===================
void test1() {
    std::cout << "\nTest1 - Creating and Initializing Lists\n";
    std::list<int> l1 {1,2,3,4,5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);

    std::list<int> l4(10, 100);  // 10 elements of value 100
    display(l4);
}

void test2() {
    std::cout << "\nTest2 - Size, Front, Back, and Clear\n";
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout << "Size: " << l.size() << "\n";
    std::cout << "Front: " << l.front() << "\n";
    std::cout << "Back : " << l.back() << "\n";

    l.clear();
    std::cout << "After clear:\n";
    display(l);
}

void test3() {
    std::cout << "\nTest3 - Resize and Default Construction\n";
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    l.resize(5);   // truncates
    display(l);

    l.resize(10);  // fills with 0
    display(l);

    std::list<Person> persons;
    persons.resize(5);  // 5 default-constructed Person
    display(persons);
}

void test4() {
    std::cout << "\nTest4 - Insert, Erase, Advance\n";
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end())
        l.insert(it, 100);  // insert before 5

    std::list<int> l2 {1000,2000,3000};
    l.insert(it, l2.begin(), l2.end());  // insert range before 5
    display(l);

    std::advance(it, -4);  // go back to 100
    std::cout << "Erasing: " << *it << std::endl;
    l.erase(it);
    display(l);
}

void test5() {
    std::cout << "\nTest5 - emplace_back and emplace\n";
    std::list<Person> stooges {
        {"Larry", 18}, {"Moe", 25}, {"Curly", 17}
    };
    display(stooges);

    std::string name;
    int age;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore();  // flush newline

    stooges.emplace_back(name, age);
    display(stooges);

    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);
}

void test6() {
    std::cout << "\nTest6 - Sorting Persons by Age\n";
    std::list<Person> stooges {
        {"Larry", 18}, {"Moe", 25}, {"Curly", 17}
    };
    std::cout << "Before sorting:\n";
    display(stooges);

    stooges.sort();  // uses operator<
    std::cout << "After sorting:\n";
    display(stooges);
}

// =================== Forward List Test Functions ===================
void test_fwd_1() {
    std::cout << "\nFWD Test1 - Basic Operations\n";
    std::forward_list<int> flist = {1,2,3,4,5};
    display(flist);

    flist.push_front(0);
    display(flist);

    flist.pop_front();
    display(flist);
}

void test_fwd_2() {
    std::cout << "\nFWD Test2 - Inserting After\n";
    std::forward_list<int> flist = {10,20,30};

    auto it = flist.before_begin();  // use before_begin for inserting at head
    flist.insert_after(it, 5);       // insert 5 at front
    display(flist);

    it = std::find(flist.begin(), flist.end(), 20);
    if (it != flist.end())
        flist.insert_after(it, 21);
    display(flist);
}

void test_fwd_3() {
    std::cout << "\nFWD Test3 - Sorting and Removing\n";
    std::forward_list<int> flist = {3,5,1,4,2};
    display(flist);

    flist.sort();
    std::cout << "After sorting:\n";
    display(flist);

    flist.remove_if([](int x) { return x % 2 == 0; });  // remove even numbers
    std::cout << "After removing evens:\n";
    display(flist);
}

// =================== Main ===================
int main() {
    std::cout << "=== std::list Tests ===" << std::endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    std::cout << "\n=== std::forward_list Tests ===" << std::endl;
    test_fwd_1();
    test_fwd_2();
    test_fwd_3();

    std::cout << "\nAll tests complete.\n";
    return 0;
}
