/**
 * std::multimap allows a key to appear more than once. It therefore has no
 * operator[] and no at(): those would have no single value to return.
 *
 * equal_range() gives the whole group of entries sharing a key.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> courses = {
        {"Alice", "Math"},
        {"Bob", "Physics"},
        {"Alice", "Chemistry"},
        {"Alice", "Biology"},
        {"Bob", "Art"}
    };

    std::cout << "Total entries: " << courses.size() << std::endl;
    std::cout << "Entries for Alice: " << courses.count("Alice") << std::endl;

    // equal_range returns [first, last) covering every match
    auto range = courses.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Alice takes " << it->second << std::endl;
    }

    std::cout << "---" << std::endl;

    // Erasing by key removes every matching entry
    std::cout << "Erased: " << courses.erase("Alice") << std::endl;

    for (const auto& [student, course] : courses) {
        std::cout << student << ": " << course << std::endl;
    }

    return 0;
}
