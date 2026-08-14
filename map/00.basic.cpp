/**
 * std::map stores key-value pairs kept sorted by key. Lookup, insertion and
 * removal are O(log n), and iteration always follows key order rather than
 * insertion order.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages = {
        {"Charlie", 35},
        {"Alice", 30},
        {"Bob", 25}
    };

    // Two ways of adding an entry
    ages["Dave"] = 28;
    ages.insert({"Eve", 22});

    std::cout << "Size: " << ages.size() << std::endl;
    std::cout << "Alice is " << ages["Alice"] << " years old." << std::endl;

    // Note the output order: sorted by key, not the order written above
    for (const auto& entry : ages) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }

    return 0;
}
