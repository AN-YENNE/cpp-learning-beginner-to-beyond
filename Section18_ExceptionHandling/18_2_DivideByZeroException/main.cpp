#include <iostream>

int main() {    
    int miles {};               // Variable to store miles driven
    int gallons {};             // Variable to store gallons used
    double miles_per_gallon {}; // Variable to store result

    std::cout << "Enter the miles driven: ";
    std::cin >> miles;

    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;

    try {
        // ❗ Check for division by zero
        if (gallons == 0)
            throw 0;  // Throws an integer exception

        // ✅ Safe division
        miles_per_gallon = static_cast<double>(miles) / gallons;

        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) {
        // ⚠️ Handles division by zero case
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}