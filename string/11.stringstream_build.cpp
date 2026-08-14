/**
 * std::ostringstream builds a string from mixed types using the same << syntax
 * as std::cout, and applies the formatting manipulators from <iomanip>.
 *
 * std::istringstream does the reverse, reading typed values out of a string.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>  // For std::setprecision, std::setw and std::setfill

int main() {
    std::ostringstream out;
    out << "Item " << 42 << " costs " << std::fixed << std::setprecision(2) << 19.5;
    std::string line = out.str();
    std::cout << line << std::endl;

    // Padding and alignment
    std::ostringstream table;
    table << std::setw(10) << std::left << "name"
          << std::setw(5) << std::right << 7;
    std::cout << "[" << table.str() << "]" << std::endl;

    // Zero padding, useful for timestamps
    std::ostringstream clock;
    clock << std::setfill('0') << std::setw(2) << 9 << ":"
          << std::setw(2) << 5;
    std::cout << clock.str() << std::endl;

    // Reading typed values back out of a string
    std::istringstream in("10 3.5 hello");
    int count = 0;
    double ratio = 0.0;
    std::string word;
    if (in >> count >> ratio >> word) {
        std::cout << "Parsed: " << count << ", " << ratio << ", " << word << std::endl;
    }

    // Extraction fails rather than throwing, so the result must be checked
    std::istringstream bad("not-a-number");
    int value = 0;
    if (!(bad >> value)) {
        std::cout << "Extraction failed, as expected" << std::endl;
    }

    return 0;
}
