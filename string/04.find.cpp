/**
 * All the find functions return std::string::npos when there is no match, not
 * -1 and not 0. Position 0 is a perfectly good result, so testing the result
 * for truth is a bug: always compare against npos.
 */

#include <iostream>
#include <string>

int main() {
    std::string text = "the cat sat on the mat";

    // find() searches forward, rfind() backward
    std::cout << "First \"the\": " << text.find("the") << std::endl;
    std::cout << "Last \"the\":  " << text.rfind("the") << std::endl;

    // A match at position 0 is why npos exists
    size_t position = text.find("the");
    if (position != std::string::npos) {
        std::cout << "Found at " << position << ", and 0 would be valid too" << std::endl;
    }

    if (text.find("dog") == std::string::npos) {
        std::cout << "\"dog\" is absent" << std::endl;
    }

    // Searching from an offset finds every occurrence
    std::cout << "All occurrences of \"at\":";
    for (size_t i = text.find("at"); i != std::string::npos; i = text.find("at", i + 1)) {
        std::cout << " " << i;
    }
    std::cout << std::endl;

    // find_first_of matches any character from a set
    size_t vowel = text.find_first_of("aeiou");
    std::cout << "First vowel at " << vowel << ": " << text[vowel] << std::endl;

    return 0;
}
