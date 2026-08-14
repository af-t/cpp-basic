/**
 * std::find scans the whole range in O(n). On a sorted vector the binary search
 * family works in O(log n), but it silently gives wrong answers if the range is
 * not sorted.
 *
 * binary_search only answers "is it there?". lower_bound and upper_bound return
 * the position, which is what you need to insert while keeping the order.
 */

#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::sort, std::binary_search, std::lower_bound

int main() {
    std::vector<int> numbers = {5, 1, 9, 3, 7};

    // Prasyarat mutlak untuk semua pencarian biner
    std::sort(numbers.begin(), numbers.end());  // {1, 3, 5, 7, 9}

    std::cout << "Contains 7? " << std::boolalpha
              << std::binary_search(numbers.begin(), numbers.end(), 7) << std::endl;
    std::cout << "Contains 4? "
              << std::binary_search(numbers.begin(), numbers.end(), 4) << std::endl;

    // lower_bound: elemen pertama yang tidak lebih kecil dari nilai yang dicari
    auto it = std::lower_bound(numbers.begin(), numbers.end(), 7);
    std::cout << "Index of 7: " << std::distance(numbers.begin(), it) << std::endl;

    // Menyisipkan pada posisi lower_bound menjaga vector tetap terurut
    int new_value = 4;
    auto position = std::lower_bound(numbers.begin(), numbers.end(), new_value);
    numbers.insert(position, new_value);

    std::cout << "After inserting 4:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
