#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    std::map<int, int> x;  // x[num_rocks]
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        x[r]++;
    }

    uint64_t e, ploc, nrock;
    e = ploc = nrock = 0;
    for (auto [i, j] : x) {
        e += (i - ploc) * nrock;
        ploc = i;
        nrock += j;
    }
    e += (m - ploc) * nrock;
    cout << e;
}