#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3};

    // Resize vector menjadi 5 elemen, dengan elemen baru bernilai default (0)
    numbers.resize(5);

    // Menampilkan isi vector
    for (const int& num : numbers) {
        std::cout << num << " ";  // Output: 1 2 3 0 0
    }
    std::cout << std::endl;

    return 0;
}
