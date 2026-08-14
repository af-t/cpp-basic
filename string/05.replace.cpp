/**
 * replace() works on a position and a length, so replacing by value means
 * finding it first. Replacing every occurrence needs a loop, and that loop
 * must skip past the text it just inserted, otherwise replacing "a" with "aa"
 * never terminates.
 */

#include <iostream>
#include <string>

// Replaces every occurrence of 'from' in 'text' with 'to'
void replaceAll(std::string& text, const std::string& from, const std::string& to) {
    if (from.empty()) return;  // Otherwise the loop would never advance

    size_t position = 0;
    while ((position = text.find(from, position)) != std::string::npos) {
        text.replace(position, from.size(), to);
        position += to.size();  // Resume after the replacement, not inside it
    }
}

int main() {
    std::string text = "the cat sat on the mat";

    // Replacing a known region
    std::string headline = text;
    headline.replace(0, 3, "one");
    std::cout << headline << std::endl;

    // Replacing a single occurrence found by value
    std::string once = text;
    size_t position = once.find("cat");
    if (position != std::string::npos) {
        once.replace(position, 3, "dog");
    }
    std::cout << once << std::endl;

    // Replacing all of them
    std::string all = text;
    replaceAll(all, "at", "AT");
    std::cout << all << std::endl;

    // The case that loops forever without the position += to.size() step
    std::string growing = "aaa";
    replaceAll(growing, "a", "aa");
    std::cout << growing << std::endl;

    // erase() and insert() work on positions in the same way
    std::string trimmed = text;
    trimmed.erase(0, 4);
    trimmed.insert(0, ">> ");
    std::cout << trimmed << std::endl;

    return 0;
}
