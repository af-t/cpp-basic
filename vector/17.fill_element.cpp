#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::fill

int main() {
    std::vector<int> numbers(10);  // Vector dengan 10 elemen

    // Mengisi semua elemen dengan nilai 7
    std::fill(numbers.begin(), numbers.end(), 7);

    // Menampilkan elemen
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
