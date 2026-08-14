/**
 * The standard library has no split function before C++20's ranges, so this is
 * written by hand. Two cases come up in practice and behave differently:
 *
 *   splitting on whitespace, where runs of spaces count as one separator and
 *   empty fields cannot occur
 *
 *   splitting on a delimiter such as a comma, where "a,,b" has three fields and
 *   the middle one is empty
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Whitespace splitting: the stream skips runs of spaces for us
std::vector<std::string> splitWhitespace(const std::string& text) {
    std::vector<std::string> parts;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        parts.push_back(word);
    }
    return parts;
}

// Delimiter splitting, keeping empty fields
std::vector<std::string> split(const std::string& text, char delimiter) {
    std::vector<std::string> parts;
    size_t start = 0;
    size_t position;
    while ((position = text.find(delimiter, start)) != std::string::npos) {
        parts.push_back(text.substr(start, position - start));
        start = position + 1;
    }
    parts.push_back(text.substr(start));  // The final field has no delimiter after it
    return parts;
}

void print(const std::string& title, const std::vector<std::string>& parts) {
    std::cout << title << " (" << parts.size() << ")" << std::endl;
    for (const auto& part : parts) {
        std::cout << "  [" << part << "]" << std::endl;
    }
}

int main() {
    print("Whitespace:", splitWhitespace("  the   quick brown   fox  "));
    print("Comma:", split("a,b,c", ','));
    print("Comma with empty fields:", split("a,,b,", ','));

    return 0;
}
