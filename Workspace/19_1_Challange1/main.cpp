// Section 19
// Challenge 1 Solution
// Formatting output

#include <iostream>
#include <iomanip>   // For output formatting (setw, setprecision, setfill)
#include <vector>    // For using vectors (dynamic arrays)
#include <string>    // For using strings

// Structure representing a city with name, population, and cost of tour
struct City {
    std::string name;
    long population;
    double cost;
};

// Structure representing a country with a name and a list of cities
// Assumes each country has at least one city
struct Country {
    std::string name;
    std::vector<City> cities;
};

// Structure representing the tours with a title and a list of countries
struct Tours {
    std::string title;
    std::vector<Country> countries;
};

// Helper function to print a ruler line for alignment reference
void ruler() {
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n" << std::endl;
}

int main()
{
    // Initialize the Tours object with data for countries and cities
    Tours tours
    { 
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", { 
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 } 
                },
            },
            {
                "Brazil", { 
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", { 
                    { "Valdivia", 260000, 569.12 }, 
                    { "Santiago", 7040000, 520.00 }
                },
            },
            { 
                "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Define total width for output formatting and widths for each column
    const int total_width   {70};
    const int field1_width {20};    // Width for Country column
    const int field2_width {20};    // Width for City column
    const int field3_width {15};    // Width for Population column
    const int field4_width {15};    // Width for Price column

    // Print the ruler line for alignment check
    ruler();

    // Calculate the length of the title
    int title_length = tours.title.length();

    // Print the title centered within the total width
    std::cout << std::setw((total_width  - title_length )/ 2) << "" << tours.title << std::endl;
    std::cout << std::endl;

    // Print the header row with column titles aligned appropriately
    std::cout << std::setw(field1_width) << std::left << "Country" 
              << std::setw(field2_width) << std::left << "City" 
              << std::setw(field3_width) << std::right << "Population" 
              << std::setw(field4_width) << std::right << "Price" 
              << std::endl;

    // Print a line of dashes below the header for separation
    std::cout << std::setw(total_width) 
              << std::setfill('-') 
              << "" 
              << std::endl;

    // Reset the fill character to space after printing dashes
    std::cout << std::setfill(' ');

    // Set decimal precision to 2 places and fixed-point notation for price display
    std::cout << std::setprecision(2) << std::fixed;

    // Loop through each country and its cities to print the data
    // For the first city in each country, print the country name; for others, print blank to avoid repetition
    for(Country country : tours.countries) {
        for (size_t i = 0; i < country.cities.size(); ++i) {
            std::cout << std::setw(field1_width) << std::left << ((i == 0) ? country.name : "") // Conditional operator to print country once
                      << std::setw(field2_width) << std::left << country.cities.at(i).name 
                      << std::setw(field3_width) << std::right << country.cities.at(i).population 
                      << std::setw(field4_width) << std::right << country.cities.at(i).cost 
                      << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    return 0;
}