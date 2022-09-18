// A word is nice if there exists a substring of it of length 26 where each letter of the alphabet
// appears only once.
//
// Replace all the questions marks with uppercase letters s.t. the resulting word
// is nice then print the string.
//
// If there is no nice substring, then print -1.

#include <array>
#include <iostream>

// Modified sliding window.
int main() {
    // seen[letter] = index in given
    std::array<int, 26> seen;  // 200 to leave enough room
    int unique = 0;

    // Get input.
    std::string given;
    std::cin >> given;

    std::string output = "-1";

    // Update what is seen from input.
    for (int i = 0; i < given.size(); i++) {
        if (unique == 26) {
            std::cout << output << std::endl;
            return;
        }
    }

    std::cout << output << std::endl;
}
