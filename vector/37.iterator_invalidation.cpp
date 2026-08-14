/**
 * A vector stores its elements in one contiguous block. Growing past the
 * current capacity allocates a new block, which invalidates every iterator,
 * pointer and reference into the old one. Erasing invalidates everything from
 * the erased position onwards.
 *
 * Using an invalidated iterator is undefined behaviour: it may appear to work,
 * which is exactly what makes the bug hard to find.
 */

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3};

    // Reallocation membatalkan iterator lama
    std::cout << "Capacity before: " << numbers.capacity() << std::endl;
    auto it = numbers.begin();
    numbers.push_back(4);  // 'it' tidak boleh dipakai lagi setelah baris ini
    std::cout << "Capacity after:  " << numbers.capacity() << std::endl;

    // Mengambil ulang iterator adalah cara yang benar
    it = numbers.begin();
    std::cout << "First element: " << *it << std::endl;

    // Menghapus di dalam loop: erase mengembalikan iterator ke elemen berikutnya
    // yang masih valid, jadi jangan menaikkan iterator saat menghapus.
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    for (auto iter = values.begin(); iter != values.end(); ) {
        if (*iter % 2 == 0) {
            iter = values.erase(iter);
        } else {
            ++iter;
        }
    }

    std::cout << "Odd values left:";
    for (int num : values) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Untuk penghapusan massal, erase-remove_if lebih efisien karena hanya
    // memindahkan elemen satu kali. Lihat 26.remove_if.cpp.

    return 0;
}
