// File5: main.cpp
/******************************************************************
 * Section 13 Challenge Solution
 * main.cpp
 *
 * Goal:
 *   Demonstrate adding movies, incrementing watched counts,
 *   and displaying the collection using the Movies class.
 *
 * Note:
 *   This driver uses generic movie titles to keep examples general.
 ******************************************************************/
#include <iostream>
#include "Movies.h"

// Helper prototypes
void increment_watched(Movies& movies, std::string name);
void add_movie(Movies& movies, std::string name, std::string rating, int watched);

// Increment helper: tries to increment a movie's watched count and reports result
void increment_watched(Movies& movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" << std::endl;
    } else {
        std::cout << name << " not found" << std::endl;
    }
}

// Add helper: tries to add a movie and reports result
void add_movie(Movies& movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" << std::endl;
    }
}

int main() {
    Movies my_movies;

    // Initially empty
    my_movies.display();

    // Add three movies
    add_movie(my_movies, "MovieAlpha", "PG-13", 2);  // OK
    add_movie(my_movies, "MovieBeta",  "PG",    5);  // OK
    add_movie(my_movies, "MovieGamma", "PG",    7);  // OK

    // Show current list
    my_movies.display();  // MovieAlpha, MovieBeta, MovieGamma

    // Try to add a duplicate and add a new one
    add_movie(my_movies, "MovieGamma", "PG",    7);  // Already exists
    add_movie(my_movies, "MovieDelta", "PG",   12);  // OK

    // Show current list again
    my_movies.display();  // MovieAlpha, MovieBeta, MovieGamma, MovieDelta

    // Increment watch counts
    increment_watched(my_movies, "MovieAlpha");  // OK
    increment_watched(my_movies, "MovieDelta");  // OK

    // Display after increments
    my_movies.display();  // MovieAlpha and MovieDelta watched incremented

    // Try to increment a non-existent movie
    increment_watched(my_movies, "MovieDoesNotExist");  // Not found

    return 0;
}

/*
Suggested exercises to explore:
1) Change ratings and watched counts, then display.
2) Add a method to remove a movie by name.
3) Make add_movie and increment_watched accept const std::string& for efficiency.
4) Persist the collection to a file and load it at startup.
*/
