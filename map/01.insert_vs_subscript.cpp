/**
 * The two ways of writing to a map behave differently, and both differ from
 * what people expect:
 *
 *   operator[] inserts a default-constructed value when the key is missing,
 *   so merely reading through it can grow the map.
 *
 *   insert() never overwrites an existing key. It reports whether it did
 *   anything through the bool in the returned pair.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores = {{"Alice", 90}};

    // Reading a missing key through operator[] silently creates it
    std::cout << "Size before reading: " << scores.size() << std::endl;
    int bob = scores["Bob"];
    std::cout << "scores[\"Bob\"] = " << bob << std::endl;
    std::cout << "Size after reading:  " << scores.size() << std::endl;

    // insert() leaves an existing value untouched
    auto result = scores.insert({"Alice", 100});
    std::cout << "Inserted a new entry? " << std::boolalpha << result.second << std::endl;
    std::cout << "Alice is still " << scores["Alice"] << std::endl;

    // operator[] does overwrite
    scores["Alice"] = 100;
    std::cout << "Alice is now " << scores["Alice"] << std::endl;

    // Use find() when you only want to look, without modifying the map
    if (scores.find("Carol") == scores.end()) {
        std::cout << "Carol is absent, and looking did not add her" << std::endl;
    }
    std::cout << "Final size: " << scores.size() << std::endl;

    return 0;
}
