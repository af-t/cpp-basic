#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::count

int main() {
    std::vector<int> numbers = {1, 2, 3, 1, 4, 1, 5};

    // Menghitung elemen yang memiliki nilai 1.
    // count mengembalikan difference_type, jadi gunakan auto.
    auto count = std::count(numbers.begin(), numbers.end(), 1);

    std::cout << "Number of 1s: " << count << std::endl;

    return 0;
}
