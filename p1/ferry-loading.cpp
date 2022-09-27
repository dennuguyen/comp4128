#include <iostream>

void solution() {
    int n, t, m;
    std::cin >> n >> t >> m;
    int cars[m];
    for (int i = 0; i < m; i++) {
        std::cin >> cars[i];
    }

    int mtrips = 0;
    int mtime = 0;
    int cn = 0;
    for (int i = 0; i < m; i++) {
        cn++;

        if (cn == n) {
            mtime = cars[i] + t;
            mtrips++;
            if (i != m) cn = 0;
        }
    }

    if (cn < n) {
        mtime = cars[m - 1] + t;
        mtrips++;
    }

    std::cout << mtime << " " << mtrips << "\n";
}

int main() {
    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++) {
        solution();
    }
}