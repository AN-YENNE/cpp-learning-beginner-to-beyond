// Section 20 - Challenge 3: Maps and Sets
// Processes a file and builds:
// - Map of word frequencies (Part 1)
// - Map of word occurrences by line number (Part 2)

#include <iostream>     // std::cout, std::cerr
#include <fstream>      // std::ifstream for file reading
#include <sstream>      // std::stringstream to parse lines
#include <map>          // std::map for word mapping
#include <set>          // std::set for storing unique line numbers
#include <string>       // std::string
#include <iomanip>      // std::setw, std::left, std::right for formatting

// ==============================
// Helper Function: Remove punctuation from a word
// ==============================
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c != '.' && c != ',' && c != ';' && c != ':')
            result += c;
    }
    return result;
}

// ==============================
// Part 1 Display: Word -> Frequency
// ==============================
void display_words(const std::map<std::string, int> &words) {
    std::cout << "\n=== Word Frequency Table ===\n";
    std::cout << std::setw(12) << std::left << "Word"
              << std::setw(7)  << std::right << "Count" << std::endl;
    std::cout << "============================" << std::endl;
    for (const auto &pair : words)
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7)  << std::right << pair.second << std::endl;
}

// ==============================
// Part 2 Display: Word -> Set of line numbers
// ==============================
void display_words(const std::map<std::string, std::set<int>> &words) {
    std::cout << "\n=== Word Occurrences Table ===\n";
    std::cout << std::setw(12) << std::left << "Word"
              << "Occurrences" << std::endl;
    std::cout << "=========================================================" << std::endl;
    for (const auto &pair : words) {
        std::cout << std::setw(12) << std::left << pair.first << "[ ";
        for (int line : pair.second)
            std::cout << line << " ";
        std::cout << "]" << std::endl;
    }
}

// ==============================
// Part 1: Count word frequencies
// ==============================
void part1() {
    std::cout << "\n===== Part 1: Word Frequency Count =====\n";

    std::map<std::string, int> words;
    std::string line, word;
    std::ifstream in_file {"words.txt"};  // Change path if needed

    if (in_file) {
        while (std::getline(in_file, line)) {
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word]++;  // Increment count for each word
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error: Unable to open file '../words.txt'\n";
    }
}

// ==============================
// Part 2: Track word occurrences by line number
// ==============================
void part2() {
    std::cout << "\n===== Part 2: Word Occurrence by Line =====\n";

    std::map<std::string, std::set<int>> words;
    std::string line, word;
    std::ifstream in_file {"words.txt"};  // Change path if needed

    if (in_file) {
        int line_number = 0;
        while (std::getline(in_file, line)) {
            ++line_number;
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word].insert(line_number);  // Add line number to the set
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error: Unable to open file '../words.txt'\n";
    }
}

// ==============================
// Main
// ==============================
int main() {
    part1();
    part2();
    return 0;
}
