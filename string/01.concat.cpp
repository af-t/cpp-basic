/**
 * operator+ builds a new string every time, so chaining it in a loop copies
 * repeatedly. += appends in place and is what a loop should use.
 *
 * At least one operand of + must be a std::string: "a" + "b" is pointer
 * arithmetic on two char arrays, not concatenation.
 */

#include <iostream>
#include <string>

int main() {
    std::string first = "Hello";
    std::string second = "World";

    std::string joined = first + ", " + second + "!";
    std::cout << joined << std::endl;

    // Appending in place
    std::string message = "Count:";
    for (int i = 1; i <= 5; ++i) {
        message += " ";
        message += std::to_string(i);
    }
    std::cout << message << std::endl;

    // append() can take a substring or a repeated character
    std::string line = "Total";
    line.append(": ");
    line.append(3, '9');
    std::cout << line << std::endl;

    // push_back adds a single character
    line.push_back('%');
    std::cout << line << std::endl;

    // Reserving up front avoids repeated reallocation in a long loop
    std::string big;
    big.reserve(100);
    std::cout << "Capacity at least: " << big.capacity() << std::endl;

    return 0;
}
