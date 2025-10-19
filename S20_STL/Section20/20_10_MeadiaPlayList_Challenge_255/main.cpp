// Section 20
// Challenge 2 - Media Playlist using std::list

#include <iostream>      // for std::cout, std::cin, std::endl
#include <list>          // for std::list (doubly linked list)
#include <string>        // for std::string
#include <cctype>        // for std::toupper
#include <iomanip>       // for std::setw and formatting output
#include <limits>        // for std::numeric_limits (safe input handling)

// ==============================
// Class representing a song
// ==============================
class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}

    std::string get_name() const { return name; }
    std::string get_artist() const { return artist; }
    int get_rating() const { return rating; }

    // For sorting by name
    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }

    // For comparing songs
    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }
};

// Overloaded stream insertion operator for Song
std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

// ==============================
// Utility Functions
// ==============================

void display_menu() {
    std::cout << "\n========== MENU ==========" << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and Play a New Song at Current Location" << std::endl;
    std::cout << "L - List the Current Playlist" << std::endl;
    std::cout << "Q - Quit" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Enter your choice: ";
}

void play_current_song(const Song &song) {
    std::cout << "\n Now Playing:\n" << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    std::cout << "\n======= Playlist =======\n";
    for (const Song &song : playlist)
        std::cout << song << std::endl;

    std::cout << "========================" << std::endl;
    std::cout << " Current Song:\n" << current_song << std::endl;
}

// ==============================
// Main Function
// ==============================
int main() {
    std::list<Song> playlist {
        {"God's Plan",         "Drake",                     5},
        {"Never Be The Same",  "Camila Cabello",            5},
        {"Pray For Me",        "The Weekend and K. Lamar",  4},
        {"The Middle",         "Zedd, Maren Morris & Grey", 5},
        {"Wait",               "Maroon 5",                  4},
        {"Whatever It Takes",  "Imagine Dragons",           3}
    };

    auto current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection {};

    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear newline

        switch (selection) {
            case 'F':
                std::cout << "\nPlaying first song..." << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;

            case 'N':
                std::cout << "\nPlaying next song..." << std::endl;
                ++current_song;
                if (current_song == playlist.end()) {
                    std::cout << "Reached end, looping to start.\n";
                    current_song = playlist.begin();
                }
                play_current_song(*current_song);
                break;

            case 'P':
                std::cout << "\nPlaying previous song..." << std::endl;
                if (current_song == playlist.begin()) {
                    std::cout << "At beginning, looping to end.\n";
                    current_song = playlist.end();
                }
                --current_song;
                play_current_song(*current_song);
                break;

            case 'A': {
                std::string name, artist;
                int rating;

                std::cout << "\n Add a new song to current location" << std::endl;
                std::cout << "Enter song name: ";
                std::getline(std::cin, name);

                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);

                std::cout << "Enter rating (1-5): ";
                std::cin >> rating;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                playlist.insert(current_song, Song{name, artist, rating});
                --current_song;  // move iterator to newly added song
                play_current_song(*current_song);
                break;
            }

            case 'L':
                display_playlist(playlist, *current_song);
                break;

            case 'Q':
                std::cout << "\nQuitting the playlist. Goodbye! \n";
                break;

            default:
                std::cout << "Invalid choice. Try again!" << std::endl;
        }

    } while (selection != 'Q');

    return 0;
}
