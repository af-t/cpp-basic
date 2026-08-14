# String Operations in C++

This directory contains examples using `std::string` in C++. Each file
demonstrates one operation or concept.

## List of Files

1. **[basic.cpp](00.basic.cpp)**: Constructing strings, `size()` and reading a full line.
2. **[concat.cpp](01.concat.cpp)**: Joining strings with `+`, `+=` and `append`.
3. **[access_chars.cpp](02.access_chars.cpp)**: Character access with `operator[]`, `at()`, `front()` and `back()`.
4. **[substr.cpp](03.substr.cpp)**: Extracting parts of a string with `substr`.
5. **[find.cpp](04.find.cpp)**: Searching, and why the result must be compared against `npos`.
6. **[replace.cpp](05.replace.cpp)**: Replacing one occurrence and replacing all of them.
7. **[compare.cpp](06.compare.cpp)**: Value comparison, lexicographic order and a case-insensitive check.
8. **[to_number.cpp](07.to_number.cpp)**: Converting to and from numbers, including the partial-parse trap.
9. **[split.cpp](08.split.cpp)**: Splitting on whitespace and on a delimiter.
10. **[trim.cpp](09.trim.cpp)**: Removing surrounding whitespace, including the all-whitespace case.
11. **[case_conversion.cpp](10.case_conversion.cpp)**: Upper and lower case, and why the `unsigned char` cast is required.
12. **[stringstream_build.cpp](11.stringstream_build.cpp)**: Building and parsing strings with `std::stringstream`.
13. **[string_view.cpp](12.string_view.cpp)**: Referring to characters without copying, and the lifetime it costs.

Several of these files implement helpers that the standard library does not
provide before C++20, such as splitting and trimming.
