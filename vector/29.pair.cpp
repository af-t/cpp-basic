#include <iostream>
#include <vector>
#include <string>
#include <utility>  // Untuk std::pair

int main() {
    std::vector<std::pair<int, std::string>> idNamePairs = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};

    // Menampilkan isi
    for (const auto& pair : idNamePairs) {
        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
    }

    return 0;
}
