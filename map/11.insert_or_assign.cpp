/**
 * C++17 added two members that cover the gaps between insert() and operator[]:
 *
 *   insert_or_assign  always ends with the new value, and reports whether the
 *                     key was created or overwritten
 *   try_emplace       only inserts when the key is missing, and does not build
 *                     the value at all otherwise
 *
 * try_emplace matters when the value is expensive to construct or cannot be
 * copied, where insert() would build a value just to throw it away.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> config = {{"host", "localhost"}};

    auto assigned = config.insert_or_assign("host", "example.com");
    std::cout << "host was created? " << std::boolalpha << assigned.second << std::endl;
    std::cout << "host = " << config["host"] << std::endl;

    auto created = config.insert_or_assign("port", "8080");
    std::cout << "port was created? " << created.second << std::endl;

    // try_emplace leaves an existing entry alone
    auto attempt = config.try_emplace("host", "ignored.example");
    std::cout << "host inserted again? " << attempt.second << std::endl;
    std::cout << "host = " << config["host"] << std::endl;

    for (const auto& [key, value] : config) {
        std::cout << key << " = " << value << std::endl;
    }

    return 0;
}
