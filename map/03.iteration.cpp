/**
 * Every element of a map is a std::pair<const Key, Value>. The key is const,
 * so it cannot be changed in place, but the value can.
 *
 * Structured bindings (C++17) make this far more readable than .first/.second.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> prices = {
        {"bread", 20},
        {"milk", 15},
        {"eggs", 30}
    };

    // Classic form
    for (const auto& entry : prices) {
        std::cout << entry.first << " costs " << entry.second << std::endl;
    }

    std::cout << "---" << std::endl;

    // Structured bindings, same thing
    for (const auto& [name, price] : prices) {
        std::cout << name << " costs " << price << std::endl;
    }

    std::cout << "---" << std::endl;

    // Binding by non-const reference allows editing the value.
    // The key stays const and cannot be assigned to.
    for (auto& [name, price] : prices) {
        (void)name;
        price *= 2;
    }

    for (const auto& [name, price] : prices) {
        std::cout << name << " now costs " << price << std::endl;
    }

    return 0;
}
