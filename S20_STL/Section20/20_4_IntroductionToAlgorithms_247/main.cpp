// Section 20
// Extended Algorithms Demo (find, count, replace, transform, partition, remove_if, copy_if, for_each, sort, unique)

 #include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <cctype>  // for ::toupper

// A simple Person class to demonstrate find on user-defined types
class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) 
        : name{name}, age{age}  {}

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }

    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }


    std::string get_name() const { return name; }
    int get_age() const { return age; }
};


// Utility to print a vector<int>
void print_vec(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << "]" << std::endl;
}

// Utility to print a vector<Person>
void print_persons(const std::vector<Person> &vec) {
    std::cout << "[ ";
    for (auto &p : vec) {
        std::cout << "(" << p.get_name() << "," << p.get_age() << ") ";
    }
    std::cout << "]" << std::endl;
}


// ===== find_test =====
void find_test() {
    std::cout << "\n===== find_test(): std::find demo =====" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};
    auto loc = std::find(vec.begin(), vec.end(), 1);
    if (loc != vec.end())
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };
    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});
    if (loc1 != players.end())
        std::cout << "Found Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
}

// ===== count_test =====
void count_test() {
    std::cout << "\n===== count_test(): std::count demo =====" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences of 1 found" << std::endl;
}

// ===== count_if_test =====
void count_if_test() {
    std::cout << "\n===== count_if_test(): std::count_if demo =====" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1, 100};
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
    std::cout << num << " numbers are >= 5" << std::endl;
}

// ===== replace_test =====
void replace_test() {
    std::cout << "\n===== replace_test(): std::replace demo =====" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};
    std::cout << "Before replace: ";
    print_vec(vec);

    std::replace(vec.begin(), vec.end(), 1, 100);

    std::cout << "After replace (1 -> 100): ";
    print_vec(vec);
}

// ===== all_of_test =====
void all_of_test() {
    std::cout << "\n===== all_of_test(): std::all_of demo =====" << std::endl;
    std::vector<int> vec1 {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};

    if (std::all_of(vec1.begin(), vec1.end(), [](int x){ return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;

    if (std::all_of(vec1.begin(), vec1.end(), [](int x){ return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}

// ===== string_transform_test =====
void string_transform_test() {
    std::cout << "\n===== string_transform_test(): std::transform demo =====" << std::endl;
    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;

    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    std::cout << "After transform (to uppercase): " << str1 << std::endl;
}

// ===== sort_test =====
void sort_test() {
    std::cout << "\n===== sort_test(): std::sort demo =====" << std::endl;
    std::vector<int> vec {5, 3, 9, 1, 0, 8};
    std::cout << "Before sort: ";
    print_vec(vec);

    std::sort(vec.begin(), vec.end());

    std::cout << "After sort: ";
    print_vec(vec);
}

// ===== unique_test =====
void unique_test() {
    std::cout << "\n===== unique_test(): std::unique + erase demo =====" << std::endl;
    std::vector<int> vec {1, 1, 2, 3, 3, 4, 5, 5, 5, 6};
    std::cout << "Original: ";
    print_vec(vec);

    auto new_end = std::unique(vec.begin(), vec.end());
    vec.erase(new_end, vec.end());

    std::cout << "After std::unique (consecutive duplicates removed): ";
    print_vec(vec);
}

// ===== partition_test =====
void partition_test() {
    std::cout << "\n===== partition_test(): std::partition demo =====" << std::endl;
    std::vector<int> vec {1, 4, 3, 8, 5, 2, 7, 6};
    std::cout << "Original: ";
    print_vec(vec);

    auto pivot = std::partition(vec.begin(), vec.end(),
                                [](int x){ return x % 2 == 0; });
    std::cout << "After partition (evens first): ";
    print_vec(vec);
    std::cout << "Partition point index: " << (pivot - vec.begin()) << std::endl;

    std::vector<int> vec2 = {1, 4, 3, 8, 5, 2, 7, 6};
    auto stab_pivot = std::stable_partition(vec2.begin(), vec2.end(),
                                            [](int x){ return x % 2 == 0; });
    std::cout << "After stable_partition (evens first, stable order): ";
    print_vec(vec2);
    std::cout << "Stable partition point index: " << (stab_pivot - vec2.begin()) << std::endl;
}

// ===== remove_if_test2 =====
void remove_if_test2() {
    std::cout << "\n===== remove_if_test2(): std::remove_if + erase demo =====" << std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Original: ";
    print_vec(vec);

    auto new_end = std::remove_if(vec.begin(), vec.end(),
                                  [](int x){ return x % 2 == 0; });
    std::cout << "After remove_if (logical removal of evens): ";
    print_vec(vec);
    std::cout << "new_end index: " << (new_end - vec.begin()) << std::endl;

    vec.erase(new_end, vec.end());
    std::cout << "After erase: ";
    print_vec(vec);
}

// ===== copy_if_test =====
void copy_if_test() {
    std::cout << "\n===== copy_if_test(): std::copy_if demo =====" << std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Original: ";
    print_vec(vec);

    std::vector<int> evens;
    std::copy_if(vec.begin(), vec.end(),
                 std::back_inserter(evens),
                 [](int x){ return x % 2 == 0; });

    std::cout << "Copied evens to new vector: ";
    print_vec(evens);
}

// ===== for_each_test =====
void for_each_test() {
    std::cout << "\n===== for_each_test(): std::for_each demo =====" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    std::cout << "Original: ";
    print_vec(vec);

    std::cout << "Printing elements via for_each: ";
    std::for_each(vec.begin(), vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

    std::cout << "Doubling each element via for_each..." << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int &x){
        x *= 2;
    });
    std::cout << "After doubling: ";
    print_vec(vec);
}

// ===== combo_test =====
// A combined use of partition + erase, showing a realistic filtering process
void combo_test() {
    std::cout << "\n===== combo_test(): partition + erase-remove pattern =====" << std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Original: ";
    print_vec(vec);

    auto pivot = std::stable_partition(vec.begin(), vec.end(),
                                       [](int x){ return x <= 5; });
    std::cout << "After stable_partition (<=5 first): ";
    print_vec(vec);
    std::cout << "Pivot index: " << (pivot - vec.begin()) << std::endl;

    std::cout << "Elements > 5 to be removed: ";
    for (auto it = pivot; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec.erase(pivot, vec.end());
    std::cout << "After erase: ";
    print_vec(vec);
}

// ===== main =====
int main() {
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    sort_test();
    unique_test();
    partition_test();
    remove_if_test2();
    copy_if_test();
    for_each_test();
    combo_test();

    return 0;
}
