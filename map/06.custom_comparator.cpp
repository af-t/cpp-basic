/**
 * The third template parameter of std::map decides the ordering, and with it
 * what counts as the same key. Two keys are considered equal when neither
 * compares less than the other, so a case-insensitive comparator makes
 * "Alice" and "alice" a single entry.
 *
 * The comparator must be a strict weak ordering, exactly as for std::sort.
 */

#include <iostream>
#include <map>
#include <string>
#include <cctype>     // For std::tolower
#include <algorithm>  // For std::lexicographical_compare

struct CaseInsensitiveLess {
    bool operator()(const std::string& a, const std::string& b) const {
        return std::lexicographical_compare(
            a.begin(), a.end(), b.begin(), b.end(),
            // The cast matters: passing a negative char to tolower is
            // undefined behaviour
            [](unsigned char x, unsigned char y) {
                return std::tolower(x) < std::tolower(y);
            });
    }
};

int main() {
    // Descending order, using a ready-made comparator
    std::map<int, std::string, std::greater<int>> countdown = {
        {1, "one"}, {3, "three"}, {2, "two"}
    };

    for (const auto& [number, name] : countdown) {
        std::cout << number << " = " << name << std::endl;
    }

    std::cout << "---" << std::endl;

    std::map<std::string, int, CaseInsensitiveLess> visits;
    visits["Alice"] = 1;
    visits["ALICE"] = 2;  // Same key under this ordering, so it overwrites
    visits["bob"] = 3;

    std::cout << "Entries: " << visits.size() << std::endl;
    for (const auto& [name, count] : visits) {
        std::cout << name << " -> " << count << std::endl;
    }

    // The key keeps the spelling it was first inserted with
    std::cout << "Lookup with \"aLiCe\": " << visits.at("aLiCe") << std::endl;

    return 0;
}
