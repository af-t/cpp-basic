/**
 * operator== and operator< compare by value, unlike char pointers where ==
 * would compare addresses. The ordering is lexicographic by character code,
 * which is not the same as alphabetical: every uppercase letter sorts before
 * every lowercase one in ASCII.
 */

#include <iostream>
#include <string>
#include <cctype>     // For std::tolower
#include <algorithm>  // For std::lexicographical_compare

bool equalsIgnoreCase(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin(), [](unsigned char x, unsigned char y) {
        return std::tolower(x) == std::tolower(y);
    });
}

int main() {
    std::string a = "apple";
    std::string b = "banana";

    std::cout << std::boolalpha;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a < b:  " << (a < b) << std::endl;

    // compare() returns a sign, useful when you need all three outcomes at once
    std::cout << "a.compare(b): " << a.compare(b) << std::endl;
    std::cout << "b.compare(a): " << b.compare(a) << std::endl;
    std::cout << "a.compare(a): " << a.compare(a) << std::endl;

    // Case matters, and uppercase sorts first in ASCII
    std::cout << "\"Zebra\" < \"apple\": " << (std::string("Zebra") < std::string("apple")) << std::endl;

    std::cout << "equalsIgnoreCase(\"HELLO\", \"hello\"): "
              << equalsIgnoreCase("HELLO", "hello") << std::endl;

    return 0;
}
