#include <iostream>

// Function to calculate MPG (Miles Per Gallon)
// Throws an exception if gallons is zero to avoid division by zero
double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw 0;   //  Throwing an int to signal divide-by-zero
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};               // Variable to store miles driven
    int gallons {};             // Variable to store gallons used
    double miles_per_gallon {}; // Variable to store calculated MPG
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;

    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
        //  Try to calculate MPG
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) {
        //  Catch block handles division by zero
        std::cerr << "Tried to divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;

    return 0;
}