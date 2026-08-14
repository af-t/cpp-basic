#include <iostream>
#include <vector>
#include <string>
#include <utility>  // Untuk std::move

/**
 * More Efficient than `push_back'
 *
 * emplace_back allows us to create objects in place,
 * avoiding the overhead of copying or moving.
 */

struct Person {
    std::string name;
    int age;

    // Parameter diambil by value lalu dipindahkan, jadi tidak ada salinan tambahan
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

int main() {
    std::vector<Person> people;

    // emplace_back lebih efisien daripada push_back karena langsung membangun objek di dalam vector
    people.emplace_back("Alice", 30);
    people.emplace_back("Bob", 25);

    for (const auto& person : people) {
        std::cout << person.name << " is " << person.age << " years old." << std::endl;
    }

    return 0;
}
