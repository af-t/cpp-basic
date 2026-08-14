/**
 * These algorithms return iterators, not values, so an empty range is reported
 * by returning end() and must be handled before dereferencing.
 *
 * std::minmax_element finds both extremes in a single pass.
 */

#include <iostream>
#include <vector>
#include <cstdlib>  // Untuk std::abs
#include <algorithm>  // Untuk std::min_element, std::max_element, std::minmax_element

int main() {
    std::vector<int> numbers = {42, -7, 19, 73, -4};

    if (numbers.empty()) {
        std::cout << "Vector is empty" << std::endl;
        return 0;
    }

    auto smallest = std::min_element(numbers.begin(), numbers.end());
    auto largest = std::max_element(numbers.begin(), numbers.end());

    std::cout << "Min: " << *smallest
              << " at index " << std::distance(numbers.begin(), smallest) << std::endl;
    std::cout << "Max: " << *largest
              << " at index " << std::distance(numbers.begin(), largest) << std::endl;

    // Satu kali lintasan untuk kedua nilai sekaligus
    auto bounds = std::minmax_element(numbers.begin(), numbers.end());
    std::cout << "minmax_element: " << *bounds.first
              << " and " << *bounds.second << std::endl;

    // Dengan comparator: mencari nilai yang paling dekat dengan nol
    auto closest_to_zero = std::min_element(numbers.begin(), numbers.end(),
                                            [](int a, int b) { return std::abs(a) < std::abs(b); });
    std::cout << "Closest to zero: " << *closest_to_zero << std::endl;

    return 0;
}
