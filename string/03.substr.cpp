/**
 * substr(pos, count) takes a starting position and a length, not two
 * positions. count may run past the end, in which case the rest of the string
 * is returned, but pos past the end throws std::out_of_range.
 */

#include <iostream>
#include <string>
#include <stdexcept>  // For std::out_of_range

int main() {
    std::string date = "2026-08-14";

    std::cout << "Year:  " << date.substr(0, 4) << std::endl;
    std::cout << "Month: " << date.substr(5, 2) << std::endl;
    std::cout << "Day:   " << date.substr(8, 2) << std::endl;

    // Omitting the length takes everything from pos onwards
    std::cout << "From the month on: " << date.substr(5) << std::endl;

    // A length beyond the end is clamped, which is harmless
    std::cout << "Clamped: " << date.substr(8, 100) << std::endl;

    // A position beyond the end is not
    try {
        std::cout << date.substr(50) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << std::endl;
    }

    // Splitting on a separator found at run time
    std::string path = "folder/file.txt";
    size_t slash = path.find('/');
    if (slash != std::string::npos) {
        std::cout << "Directory: " << path.substr(0, slash) << std::endl;
        std::cout << "File: " << path.substr(slash + 1) << std::endl;
    }

    return 0;
}
