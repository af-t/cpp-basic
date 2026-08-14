# Map Operations in C++

This directory contains examples using `std::map` and its relatives in C++.
Each file demonstrates one operation or concept.

## List of Files

1. **[basic.cpp](00.basic.cpp)**: Creating a map, adding entries and iterating in key order.
2. **[insert_vs_subscript.cpp](01.insert_vs_subscript.cpp)**: Why `operator[]` can grow a map while `insert` never overwrites.
3. **[find_and_count.cpp](02.find_and_count.cpp)**: Looking a key up without modifying the map.
4. **[iteration.cpp](03.iteration.cpp)**: Iterating with structured bindings and editing values in place.
5. **[erase.cpp](04.erase.cpp)**: Removing entries by key, by iterator and while iterating.
6. **[at_and_missing_key.cpp](05.at_and_missing_key.cpp)**: Bounds-checked access with `at()` on a const map.
7. **[custom_comparator.cpp](06.custom_comparator.cpp)**: Changing the ordering, and with it what counts as the same key.
8. **[multimap.cpp](07.multimap.cpp)**: Storing duplicate keys and reading them back with `equal_range`.
9. **[unordered_map.cpp](08.unordered_map.cpp)**: Hash-based lookup and what is given up for it.
10. **[word_frequency.cpp](09.word_frequency.cpp)**: Counting occurrences and ranking the results.
11. **[struct_as_key.cpp](10.struct_as_key.cpp)**: Using a custom type as a key via `operator<`.
12. **[insert_or_assign.cpp](11.insert_or_assign.cpp)**: The C++17 members `insert_or_assign` and `try_emplace`.
13. **[range_queries.cpp](12.range_queries.cpp)**: Range lookups with `lower_bound` and `upper_bound`.

A `std::map` keeps its keys sorted and offers O(log n) lookup. Reach for
`std::unordered_map` when the ordering is not needed and lookups dominate.
