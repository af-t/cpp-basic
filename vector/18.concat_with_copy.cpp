#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::copy

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> result;

    // Menyiapkan ruang dalam vector 'result' untuk gabungan
    result.reserve(vec1.size() + vec2.size());

    // Menggabungkan dua vector
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(result));
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(result));

    // Menampilkan hasil
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
