/**
 * As with a vector, operator[] does not check bounds while at() throws
 * std::out_of_range. Characters are plain char values, so they can be
 * compared and modified directly.
 */

#include <iostream>
#include <string>
#include <stdexcept>  // For std::out_of_range

int main() {
    std::string word = "example";

    std::cout << "First: " << word.front() << std::endl;
    std::cout << "Last: " << word.back() << std::endl;
    std::cout << "word[2]: " << word[2] << std::endl;

    try {
        std::cout << word.at(100) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << std::endl;
    }

    // Iterating character by character.
    // Only lowercase vowels match, which is why this runs before the change
    // below rather than after it.
    int vowels = 0;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowels;
        }
    }
    std::cout << "Vowels: " << vowels << std::endl;

    // Modifying characters in place
    word[0] = 'E';
    std::cout << word << std::endl;

    return 0;
}
