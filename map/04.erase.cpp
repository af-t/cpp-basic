/**
 * Erasing from a map invalidates only the iterator to the erased element.
 * Everything else stays valid, which is a stronger guarantee than a vector
 * gives.
 *
 * Erasing inside a loop still needs care: erase() returns the iterator to the
 * next element, so the loop must not increment as well.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Dave", 17},
        {"Eve", 16},
        {"Frank", 40}
    };

    // Erase by key: returns how many elements were removed (0 or 1)
    std::cout << "Removed Bob: " << ages.erase("Bob") << std::endl;
    std::cout << "Removed Zoe: " << ages.erase("Zoe") << std::endl;

    // Erase by iterator, after checking that the key exists
    auto it = ages.find("Charlie");
    if (it != ages.end()) {
        ages.erase(it);
    }

    // Erase everyone under 18 while iterating.
    // C++20 offers std::erase_if(ages, pred) for exactly this.
    for (auto iter = ages.begin(); iter != ages.end(); ) {
        if (iter->second < 18) {
            iter = ages.erase(iter);
        } else {
            ++iter;
        }
    }

    for (const auto& [name, age] : ages) {
        std::cout << name << " (" << age << ")" << std::endl;
    }

    return 0;
}
