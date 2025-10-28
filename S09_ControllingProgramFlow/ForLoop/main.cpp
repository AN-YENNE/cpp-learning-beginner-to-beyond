// Section 9
// For Loop
#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "Counting from 1 to 10:" << endl;
    for (int i {1}; i <= 10; ++i)
        cout << i << " ";
    cout << endl;

    cout << "\nCounting by 2s:" << endl;
    for (int i {1}; i <= 10; i += 2)
        cout << i << " ";
    cout << endl;

    cout << "\nCountdown from 10:" << endl;
    for (int i {10}; i > 0; --i)
        cout << i << " ";
    cout << "Blastoff!" << endl;

    cout << "\nMultiples of 10 between 10 and 100 that are divisible by 15:" << endl;
    for (int i {10}; i <= 100; i += 10)
        if (i % 15 == 0)
            cout << i << " ";
    cout << endl;

    cout << "\nPrinting pairs (i, j) where j = i + 4:" << endl;
    for (int i {1}, j {5}; i <= 5; ++i, ++j)
        cout << i << " + " << j << " = " << (i + j) << endl;

    cout << "\nPrinting numbers from 1 to 100, 10 per line:" << endl;
    for (int i {1}; i <= 100; ++i)
        cout << i << ((i % 10 == 0) ? "\n" : " ");

    cout << "\n\nPrinting contents of a vector using a for loop:" << endl;
    vector<int> nums {10, 20, 30, 40, 50};
    for (unsigned i {0}; i < nums.size(); ++i)
        cout << "Element " << i << ": " << nums[i] << endl;

    cout << endl;
}


