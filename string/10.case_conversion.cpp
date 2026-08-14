/**
 * std::toupper and std::tolower take an int that must be representable as
 * unsigned char. On platforms where char is signed, a byte above 127 becomes
 * a negative int and passing it straight through is undefined behaviour.
 *
 * The fix is always the same: take the parameter as unsigned char.
 */

#include <iostream>
#include <string>
#include <cctype>     // For std::toupper and std::tolower
#include <algorithm>  // For std::transform

std::string toUpper(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
    return text;
}

std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return text;
}

int main() {
    std::string text = "Hello, World 123!";

    std::cout << toUpper(text) << std::endl;
    std::cout << toLower(text) << std::endl;

    // Digits and punctuation are returned unchanged
    std::cout << toUpper("a1b2-c3") << std::endl;

    // Capitalising the first letter only
    std::string word = "example";
    if (!word.empty()) {
        word[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(word[0])));
    }
    std::cout << word << std::endl;

    // These functions work one byte at a time, so multi-byte UTF-8 text is
    // left as it is rather than converted.

    return 0;
}
