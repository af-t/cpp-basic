/**
 * std::unordered_map is a hash table: average O(1) lookup instead of O(log n),
 * at the cost of any ordering guarantee.
 *
 * The interface is nearly identical to std::map, so the choice is mostly about
 * whether you need the elements sorted. Do not rely on the iteration order of
 * an unordered_map; it may differ between runs and implementations.
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> ages = {
        {"Charlie", 35},
        {"Alice", 30},
        {"Bob", 25}
    };

    ages["Dave"] = 28;

    // Order here is unspecified
    std::cout << "unordered_map:" << std::endl;
    for (const auto& [name, age] : ages) {
        std::cout << "  " << name << " -> " << age << std::endl;
    }

    // The same data in a map always comes out sorted by key
    std::map<std::string, int> sorted(ages.begin(), ages.end());
    std::cout << "map:" << std::endl;
    for (const auto& [name, age] : sorted) {
        std::cout << "  " << name << " -> " << age << std::endl;
    }

    // Hash-table specific details
    std::cout << "Buckets: " << ages.bucket_count() << std::endl;
    std::cout << "Load factor: " << ages.load_factor() << std::endl;

    return 0;
}
