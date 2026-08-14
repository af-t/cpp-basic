/**
 * std::string owns its characters and grows as needed, which is what makes it
 * safer than a raw char array. size() and length() are the same function under
 * two names.
 */

#include <iostream>
#include <string>

int main() {
    std::string greeting = "Hello";
    std::string name("World");
    std::string dashes(5, '-');  // Five copies of one character
    std::string empty;

    std::cout << greeting << ", " << name << "!" << std::endl;
    std::cout << dashes << std::endl;

    std::cout << "Size: " << greeting.size() << std::endl;
    std::cout << "Length: " << greeting.length() << std::endl;
    std::cout << "Empty? " << std::boolalpha << empty.empty() << std::endl;

    // Reading a whole line, spaces included. Using std::cin >> would stop at
    // the first space.
    std::cout << "Type a sentence: ";
    std::string line;
    if (std::getline(std::cin, line)) {
        std::cout << "You typed " << line.size() << " characters" << std::endl;
    }

    return 0;
}
