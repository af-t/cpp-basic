/**
 * at() looks up a key without ever inserting, and throws std::out_of_range
 * when it is missing. That makes it the right choice on a const map, where
 * operator[] is not even available.
 */

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>  // For std::out_of_range

void report(const std::map<std::string, int>& ages, const std::string& name) {
    // operator[] cannot be used here: the map is const.
    // The lookup is kept out of the printing statement, since a throw halfway
    // through one would leave the first half already written.
    try {
        int age = ages.at(name);
        std::cout << name << " is " << age << " years old." << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << name << " is not in the map" << std::endl;
    }
}

int main() {
    std::map<std::string, int> ages = {
        {"Alice", 30},
        {"Bob", 25}
    };

    report(ages, "Alice");
    report(ages, "Carol");

    // The map was not modified by any of the lookups above
    std::cout << "Size: " << ages.size() << std::endl;

    return 0;
}
