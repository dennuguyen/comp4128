#include <iostream>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int curr = 0;
        for (auto const& i : t) {
            if (s[curr] == i) {
                curr++;
            }
        }
        cout << (curr == s.size() ? "Yes\n" : "No\n");
    }
}