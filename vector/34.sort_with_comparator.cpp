/**
 * std::sort accepts a custom comparator, which must define a strict weak
 * ordering: comp(a, a) has to be false, otherwise the behaviour is undefined.
 *
 * std::sort is not stable. Use std::stable_sort when elements that compare
 * equal must keep their original relative order.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Untuk std::sort dan std::stable_sort

struct Person {
    std::string name;
    int age;
};

void print(const std::string& title, const std::vector<Person>& people) {
    std::cout << title << std::endl;
    for (const auto& person : people) {
        std::cout << "  " << person.name << " (" << person.age << ")" << std::endl;
    }
}

int main() {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 30},
        {"Dave", 25}
    };

    // Mengurutkan berdasarkan umur menaik
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
    print("Sorted by age:", people);

    // Mengurutkan berdasarkan umur menurun, lalu nama untuk umur yang sama
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.age != b.age) return a.age > b.age;
        return a.name < b.name;
    });
    print("Sorted by age (descending), then name:", people);

    // stable_sort mempertahankan urutan sebelumnya untuk elemen yang setara
    std::stable_sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.name.size() < b.name.size();
    });
    print("Stable sorted by name length:", people);

    return 0;
}
