/**
 * std::stoi and friends throw std::invalid_argument when nothing parses and
 * std::out_of_range when the value does not fit. They also stop at the first
 * character they cannot use, so "12abc" quietly becomes 12.
 *
 * The optional position argument reports where parsing stopped, which is how
 * you reject trailing junk.
 */

#include <iostream>
#include <string>
#include <stdexcept>  // For std::invalid_argument and std::out_of_range

// Parses the whole string or reports failure, unlike a bare stoi call
bool parseInt(const std::string& text, int& out) {
    try {
        size_t consumed = 0;
        int value = std::stoi(text, &consumed);
        if (consumed != text.size()) return false;  // Trailing characters left
        out = value;
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

int main() {
    std::cout << "stoi(\"42\"): " << std::stoi("42") << std::endl;
    std::cout << "stod(\"3.14\"): " << std::stod("3.14") << std::endl;

    // The partial-parse trap
    std::cout << "stoi(\"12abc\"): " << std::stoi("12abc") << std::endl;

    try {
        std::stoi("abc");
    } catch (const std::invalid_argument&) {
        std::cout << "stoi(\"abc\") threw invalid_argument" << std::endl;
    }

    try {
        std::stoi("99999999999999999999");
    } catch (const std::out_of_range&) {
        std::cout << "stoi of a huge number threw out_of_range" << std::endl;
    }

    std::cout << std::boolalpha;
    int value = 0;
    std::cout << "parseInt(\"12abc\"): " << parseInt("12abc", value) << std::endl;
    std::cout << "parseInt(\"  7\"): " << parseInt("  7", value)
              << " (leading spaces are allowed, value " << value << ")" << std::endl;

    // The other direction
    std::cout << "to_string(255): " << std::to_string(255) << std::endl;

    return 0;
}
