/**
 * Trimming is find_first_not_of and find_last_not_of. The case that catches
 * people out is a string made entirely of whitespace: find_first_not_of
 * returns npos there, and substr(npos) would throw.
 */

#include <iostream>
#include <string>

const std::string WHITESPACE = " \t\n\r\f\v";

std::string trimLeft(const std::string& text) {
    size_t start = text.find_first_not_of(WHITESPACE);
    return start == std::string::npos ? "" : text.substr(start);
}

std::string trimRight(const std::string& text) {
    size_t end = text.find_last_not_of(WHITESPACE);
    return end == std::string::npos ? "" : text.substr(0, end + 1);
}

std::string trim(const std::string& text) {
    return trimRight(trimLeft(text));
}

int main() {
    std::string padded = "   hello world   ";

    std::cout << "[" << padded << "]" << std::endl;
    std::cout << "[" << trimLeft(padded) << "]" << std::endl;
    std::cout << "[" << trimRight(padded) << "]" << std::endl;
    std::cout << "[" << trim(padded) << "]" << std::endl;

    // Whitespace only, and empty: both must survive
    std::cout << "[" << trim("  \t\n  ") << "]" << std::endl;
    std::cout << "[" << trim("") << "]" << std::endl;

    // Inner spaces are left alone
    std::cout << "[" << trim("  a  b  ") << "]" << std::endl;

    return 0;
}
