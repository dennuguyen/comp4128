#include <iostream>
#include <vector>

void solution() {
    // Get length of input.
    int n;
    std::cin >> n;

    // Get int array input.
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int in;
        std::cin >> in;
        a.push_back(in);
    }

    // Get the max by size alternating subsequence.
    int sum = 0;
    int max = a[0];
    bool prev_sign = a[0] > 0 ? true : false;  // true/+, false/-
    for (int i = 0; i < n; i++) {
        // Check if sign has changed.
        bool curr_sign = a[i] > 0 ? true : false;
        if (curr_sign == prev_sign) {
            max = a[i] > max ? a[i] : max;
        } else {
            sum += max;
            max = a[i];
        }

        prev_sign = curr_sign;
    }
    sum += max;
    std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solution();
    }
}