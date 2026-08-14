#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::transform

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());

    // Menggandakan setiap elemen
    std::transform(numbers.begin(), numbers.end(), result.begin(), [](int x){ return x * 2; });

    // Menampilkan hasil
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
