#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::for_each

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Menggandakan setiap elemen menggunakan lambda
    std::for_each(numbers.begin(), numbers.end(), [](int &n){ n *= 2; });

    // Menampilkan hasil
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
