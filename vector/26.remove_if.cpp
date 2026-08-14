#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};

    // Menghapus elemen yang lebih kecil dari 4
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int x){ return x < 4; }), numbers.end());

    // Menampilkan hasil
    for (const int& num : numbers) {
        std::cout << num << " ";  // Output: 4 5 6 7
    }
    std::cout << std::endl;

    return 0;
}
