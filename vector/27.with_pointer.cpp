#include <iostream>
#include <vector>
#include <string>
#include <utility>  // Untuk std::move

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

int main() {
    std::vector<Person*> people;

    // Menyimpan pointer ke objek Person
    people.push_back(new Person("Alice", 30));
    people.push_back(new Person("Bob", 25));

    // Menampilkan data
    for (const Person* person : people) {
        std::cout << person->name << " is " << person->age << " years old." << std::endl;
    }

    // Membersihkan memori
    for (Person* person : people) {
        delete person;
    }

    return 0;
}
