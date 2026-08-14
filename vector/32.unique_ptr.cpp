#include <iostream>
#include <vector>
#include <string>
#include <memory>  // Untuk std::unique_ptr
#include <utility>  // Untuk std::move

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

int main() {
    std::vector<std::unique_ptr<Person>> people;

    // Menggunakan std::make_unique (C++14) untuk membuat objek unik di dalam vector
    people.push_back(std::make_unique<Person>("Alice", 30));
    people.push_back(std::make_unique<Person>("Bob", 25));

    // Menampilkan data
    for (const auto& person : people) {
        std::cout << person->name << " is " << person->age << " years old." << std::endl;
    }

    return 0;
}
