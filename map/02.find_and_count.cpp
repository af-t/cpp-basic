/**
 * find() returns an iterator to the entry, or end() when the key is absent.
 * count() answers the same question with 0 or 1, since a map holds each key
 * at most once.
 *
 * C++20 adds contains(), which reads better than "count(k) > 0". This example
 * stays on C++17.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> stock = {
        {"apple", 12},
        {"banana", 0},
        {"cherry", 7}
    };

    // find() gives access to the value without a second lookup
    auto it = stock.find("apple");
    if (it != stock.end()) {
        std::cout << it->first << ": " << it->second << " in stock" << std::endl;
    }

    if (stock.find("durian") == stock.end()) {
        std::cout << "durian: not tracked" << std::endl;
    }

    // count() only tells you whether the key exists
    std::cout << "Tracking banana? " << std::boolalpha
              << (stock.count("banana") > 0) << std::endl;

    // A key that exists may still hold a zero value, which is why counting
    // keys and checking values are different questions
    std::cout << "banana in stock? " << (stock["banana"] > 0) << std::endl;

    return 0;
}
