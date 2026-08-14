/**
 * std::string_view (C++17) is a non-owning reference to characters that
 * already exist somewhere else. Passing one copies no text, and taking a
 * substring of one copies no text either.
 *
 * The cost is lifetime: a view does not keep its characters alive. Outliving
 * the string it points into is the one mistake to watch for, and it is silent.
 */

#include <iostream>
#include <string>
#include <string_view>

// Accepts std::string, string literals and string_view without any conversion
// or allocation
void describe(std::string_view text) {
    std::cout << "\"" << text << "\" has " << text.size() << " characters" << std::endl;
}

int main() {
    std::string owned = "hello world";
    const char* literal = "from a literal";

    describe(owned);
    describe(literal);
    describe("a temporary");

    // substr on a view returns another view into the same characters
    std::string_view view = owned;
    std::string_view second = view.substr(6);
    std::cout << "Second word: " << second << std::endl;

    // remove_prefix and remove_suffix move the ends of the view
    std::string_view trimmed = owned;
    trimmed.remove_prefix(6);
    std::cout << "After remove_prefix(6): " << trimmed << std::endl;

    // Modifying the owner can reallocate its buffer and leave the view
    // pointing at freed memory, so copy into a string when the data must
    // outlive its source.
    std::string copy(second);
    owned = "something else entirely";
    std::cout << "Copy survives the change: " << copy << std::endl;

    // A view is not guaranteed to be null-terminated, so do not pass .data()
    // to a C function expecting a C string.

    return 0;
}
