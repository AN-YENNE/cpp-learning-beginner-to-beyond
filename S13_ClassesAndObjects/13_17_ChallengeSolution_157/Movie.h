/******************************************************************
 * Section 13 Challenge Solution: Movie.h
 *
 * Purpose:
 *   Define a Movie class with three attributes:
 *     - std::string name   : title of the movie
 *     - std::string rating : content rating such as G, PG, PG-13, R
 *     - int watched        : how many times the movie has been watched
 *
 * Design notes:
 *   - Keep data members private and expose behavior through public methods.
 *   - Getters are const-correct since they do not modify the object.
 *   - Provide a simple increment operation for watched count.
 ******************************************************************/
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie {
private:
    std::string name;    // movie title
    std::string rating;  // rating such as G, PG, PG-13, R
    int watched;         // number of times watched

public:
    // Constructor that initializes all attributes
    Movie(std::string name, std::string rating, int watched);

    // Copy constructor (creates a new Movie from an existing one)
    Movie(const Movie& source);

    // Destructor (nothing special to free here, but provided for completeness)
    ~Movie();

    // Setters and getters
    void set_name(std::string name)            { this->name = name; }
    std::string get_name() const               { return name; }

    void set_rating(std::string rating)        { this->rating = rating; }
    std::string get_rating() const             { return rating; }

    void set_watched(int watched)              { this->watched = watched; }
    int get_watched() const                    { return watched; }

    // Increase watched count by 1
    void increment_watched()                   { ++watched; }

    // Print movie info in a compact format: Title, Rating, WatchedCount
    void display() const;
};

#endif // _MOVIE_H_
