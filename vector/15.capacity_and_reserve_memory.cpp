#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Mengalokasikan ruang untuk 100 elemen
    numbers.reserve(100);

    // Menambahkan elemen
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(i);
    }

    std::cout << "Vector size: " << numbers.size() << std::endl;
    std::cout << "Vector capacity: " << numbers.capacity() << std::endl;

    return 0;
}
