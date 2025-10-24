/******************************************************************
 * Implementation of the Movies collection class.
 ******************************************************************/
#include <iostream>
#include "Movies.h"

// Default constructor
Movies::Movies() {
    // No special setup required; vector starts empty.
    std::cout << "Movies collection created (empty)" << std::endl;
}

// Destructor
Movies::~Movies() {
    std::cout << "Movies collection destroyed" << std::endl;
}

// Add a movie if not already present by name
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie& movie : movies) {
        if (movie.get_name() == name) {
            // Duplicate found; do not add
            return false;
        }
    }
    Movie temp{name, rating, watched};
    movies.push_back(temp); // copies temp into the vector
    return true;
}

// Increment the watched count for a movie with the given name
bool Movies::increment_watched(std::string name) {
    for (Movie& movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

// Display all movies or a message if there are none
void Movies::display() const {
    if (movies.empty()) {
        std::cout << "Sorry, no movies to display" << std::endl << std::endl;
    } else {
        std::cout << std::endl << "===================================" << std::endl;
        for (const auto& movie : movies) {
            movie.display();
        }
        std::cout << "===================================" << std::endl << std::endl;
    }
}
