#include <cmath>
#include <iostream>
using namespace std;

void solution() {
    int n, t, m;
    cin >> n >> t >> m;
    int cars[m];
    for (int i = 0; i < m; i++) {
        cin >> cars[i];
    }

    int ntrips = (int)ceil((double)m / n);
    int mtime = 0;
    for (int i = 0; i < m; i += n) {
        int j = min(i + n - 1, m - 1);
        mtime += 2 * t;
    }
    // mtime += cars[m - 1];
    // mtime -= t;

    cout << mtime << " " << ntrips << "\n";
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        solution();
    }
}