#include <iostream>

void solution() {
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

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solution();
    }
}