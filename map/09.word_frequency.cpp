/**
 * Counting occurrences is the most common use of a map. Here operator[] is
 * exactly the right tool: a missing key is value-initialised to 0, so
 * ++counts[word] works on the first sighting of a word too.
 *
 * Sorting by count needs a detour through a vector, because a map cannot be
 * reordered by its values.
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>  // For std::sort

int main() {
    const std::string text = "the quick brown fox jumps over the lazy dog "
                             "the fox barks and the dog sleeps";

    std::map<std::string, int> counts;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        ++counts[word];
    }

    std::cout << "Distinct words: " << counts.size() << std::endl;

    // Copy into a vector so the entries can be ordered by count
    std::vector<std::pair<std::string, int>> ranked(counts.begin(), counts.end());
    std::sort(ranked.begin(), ranked.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;  // Break ties alphabetically for stable output
    });

    std::cout << "Most frequent:" << std::endl;
    for (size_t i = 0; i < ranked.size() && i < 5; ++i) {
        std::cout << "  " << ranked[i].first << ": " << ranked[i].second << std::endl;
    }

    return 0;
}
