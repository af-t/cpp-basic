/**
 * operator[] does not check bounds: reading out of range is undefined behaviour.
 * at() performs the check and throws std::out_of_range instead.
 */

#include <iostream>
#include <vector>
#include <stdexcept>  // Untuk std::out_of_range

int main() {
    std::vector<int> numbers = {10, 20, 30};

    // Akses yang valid, keduanya setara
    std::cout << "numbers[1]      = " << numbers[1] << std::endl;
    std::cout << "numbers.at(1)   = " << numbers.at(1) << std::endl;

    // Akses di luar batas: at() melempar exception, operator[] tidak
    try {
        std::cout << numbers.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << std::endl;
    }

    // front() dan back() juga tidak memeriksa batas, jadi periksa dulu
    if (!numbers.empty()) {
        std::cout << "First: " << numbers.front()
                  << ", Last: " << numbers.back() << std::endl;
    }

    return 0;
}
