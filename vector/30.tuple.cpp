/**
 * allows us to store multiple values that have different data types in one element.
 */

#include <iostream>
#include <vector>
#include <string>
#include <tuple>  // Untuk std::tuple

int main() {
    // Vector of tuples: {ID, Name, Age}
    std::vector<std::tuple<int, std::string, int>> people = {
        {1, "Alice", 30},
        {2, "Bob", 25},
        {3, "Charlie", 35}
    };

    // Menampilkan isi
    for (const auto& person : people) {
        std::cout << "ID: " << std::get<0>(person)
                  << ", Name: " << std::get<1>(person)
                  << ", Age: " << std::get<2>(person) << std::endl;
    }

    return 0;
}
