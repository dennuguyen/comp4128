#include <iostream>

void solution() {
    int n, t, m;
    std::cin >> n >> t >> m;
    int cars[m];
    for (int i = 0; i < m; i++) {
        std::cin >> cars[i];
    }

    int trips = 0;
    for (int i = 0; i < m; i++) {
        if (i % n == 0) {
            trips++;
        }
    }

    std::cout << cars[m - 1] + t << " " << trips << "\n";
}

int main() {
    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++) {
        solution();
    }
}