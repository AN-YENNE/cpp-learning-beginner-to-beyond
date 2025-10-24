/******************************************************************
 * Implementation of the Movie class
 ******************************************************************/
#include <iostream>
#include "Movie.h"

// Constructor initializes all data members using an initializer list
Movie::Movie(std::string name, std::string rating, int watched)
    : name{name}, rating{rating}, watched{watched} {
    std::cout << "Movie constructed: "
              << this->name << " [" << this->rating << "], watched "
              << this->watched << " time(s)" << std::endl;
}

// Copy constructor delegates to the main constructor to avoid duplication
Movie::Movie(const Movie& source)
    : Movie{source.name, source.rating, source.watched} {
    std::cout << "Movie copy-constructed from: " << source.name << std::endl;
}

// Destructor (no dynamic resources here; message added for learning purposes)
Movie::~Movie() {
    std::cout << "Movie destroyed: " << name << std::endl;
}

// Display the formatted movie information
void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}