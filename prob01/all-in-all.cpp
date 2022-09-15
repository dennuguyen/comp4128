#include <iostream>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int curr = 0;
    for (auto const& i : t) {
        if (s[curr] == i) {
            curr++;
        }
    }
    std::cout << (curr == s.size() ? "Yes" : "No") << std::endl;
}