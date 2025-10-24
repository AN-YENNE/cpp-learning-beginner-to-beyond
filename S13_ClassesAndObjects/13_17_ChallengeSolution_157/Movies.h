/******************************************************************
 * Movies.h
 *
 * Purpose:
 *   Define a Movies collection class that stores Movie objects
 *   inside a std::vector.
 *
 * Responsibilities:
 *   - Add a movie if it does not already exist by name.
 *   - Increment the watched count for a named movie.
 *   - Display all movies in the collection.
 ******************************************************************/
#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <string>
#include "Movie.h"

class Movies {
private:
    // Container that owns Movie objects by value.
    // Storing by value is fine here because Movie is small and has no raw pointers.
    std::vector<Movie> movies;

public:
    Movies();   // constructor
    ~Movies();  // destructor

    // Add a new movie if a movie with the same name does not already exist.
    // Returns true if added, false if a duplicate name was found.
    bool add_movie(std::string name, std::string rating, int watched);

    // Increment the watched count for an existing movie by name.
    // Returns true if incremented, false if no movie with that name exists.
    bool increment_watched(std::string name);

    // Display the entire collection. Prints a friendly message if empty.
    void display() const;
};

#endif // _MOVIES_H_
