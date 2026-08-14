/**
 * std::move does not move anything by itself, it only casts a value into an
 * rvalue reference so that a move constructor or move assignment can take over
 * the resources instead of copying them.
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>  // Untuk std::move

int main() {
    std::vector<std::string> source = {"alpha", "beta", "gamma"};

    // Memindahkan satu elemen: isi string dipindahkan, bukan disalin
    std::string taken = std::move(source[0]);
    std::cout << "Moved element: " << taken << std::endl;

    // source[0] masih ada, tetapi isinya tidak ditentukan oleh standar.
    // Satu-satunya operasi yang aman adalah menugaskan nilai baru padanya.
    source[0] = "alpha (reassigned)";

    // Memindahkan seluruh vector: destination mengambil alih buffer milik source
    std::vector<std::string> destination = std::move(source);

    std::cout << "Destination contains:";
    for (const auto& word : destination) {
        std::cout << " " << word;
    }
    std::cout << std::endl;

    // Setelah dipindahkan, source berada dalam keadaan valid tetapi tidak
    // ditentukan. Implementasi umum meninggalkannya kosong, namun jangan
    // mengandalkan hal itu. Gunakan clear() bila ingin keadaan yang pasti.
    source.clear();
    std::cout << "Source size after clear(): " << source.size() << std::endl;

    return 0;
}
