#include <iostream>
#include <vector>

void solution() {
    // Get number of types of coins.
    int n;
    std::cin >> n;

    // Get amount to withdraw.
    int X;
    std::cin >> X;

    // Get coin values
    std::vector<int> C;
    for (int i = 0; i < n; i++) {
        int in;
        std::cin >> in;
        C.push_back(in);
    }

    //
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solution();
    }
}