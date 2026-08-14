/**
 * Because a map is sorted, it can answer range questions that a hash table
 * cannot: everything from a key onwards, or everything between two keys.
 *
 * lower_bound(k) is the first entry not less than k, upper_bound(k) the first
 * entry greater than k. Use the member functions, not the std:: algorithms:
 * the members follow the tree and run in O(log n).
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> events = {
        {1990, "a"},
        {1995, "b"},
        {2000, "c"},
        {2005, "d"},
        {2010, "e"}
    };

    // Everything in [1995, 2005)
    auto from = events.lower_bound(1995);
    auto to = events.lower_bound(2005);
    std::cout << "Between 1995 and 2005:" << std::endl;
    for (auto it = from; it != to; ++it) {
        std::cout << "  " << it->first << ": " << it->second << std::endl;
    }

    // The bounds do not have to exist as keys
    auto after = events.upper_bound(1997);
    std::cout << "First entry after 1997: " << after->first << std::endl;

    // lower_bound returns end() when every key is smaller
    if (events.lower_bound(2020) == events.end()) {
        std::cout << "Nothing at or after 2020" << std::endl;
    }

    return 0;
}
