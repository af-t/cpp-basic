/**
 * Removing duplicates (see 10.remove_duplicate_elements.cpp) keeps one copy of
 * every value. Searching for unique elements is a different question: which
 * values occur exactly once?
 */

#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::sort, std::equal_range

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};

    // equal_range membutuhkan rentang yang sudah terurut
    std::sort(numbers.begin(), numbers.end());

    std::vector<int> unique_values;
    for (auto it = numbers.begin(); it != numbers.end(); ) {
        // Mengambil seluruh rentang elemen yang bernilai sama
        auto range = std::equal_range(it, numbers.end(), *it);
        if (std::distance(range.first, range.second) == 1) {
            unique_values.push_back(*it);
        }
        it = range.second;  // Melompat ke nilai berbeda berikutnya
    }

    std::cout << "Values that occur exactly once:";
    for (int num : unique_values) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
