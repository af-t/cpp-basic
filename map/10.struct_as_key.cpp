/**
 * A type can be used as a map key once it has a strict weak ordering. Defining
 * operator< is the usual way; std::tie keeps the field-by-field comparison
 * short and correct.
 *
 * Comparing only some of the fields is a common bug: two different points that
 * compare equal would collapse into one entry.
 */

#include <iostream>
#include <map>
#include <string>
#include <tuple>  // For std::tie

struct Point {
    int x;
    int y;
};

// std::tie compares x first, then y, without spelling out the branches
bool operator<(const Point& a, const Point& b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

int main() {
    std::map<Point, std::string> labels = {
        {{1, 2}, "origin-ish"},
        {{0, 0}, "origin"},
        {{1, 1}, "diagonal"}
    };

    labels[{2, 3}] = "far";

    // Sorted by x, then y
    for (const auto& [point, label] : labels) {
        std::cout << "(" << point.x << ", " << point.y << "): " << label << std::endl;
    }

    // Lookup builds a temporary key and compares with operator<
    auto it = labels.find({0, 0});
    if (it != labels.end()) {
        std::cout << "Found: " << it->second << std::endl;
    }

    return 0;
}
