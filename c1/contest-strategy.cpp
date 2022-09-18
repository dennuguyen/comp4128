#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    uint64_t n, m, k;
    cin >> n >> m >> k;

    vector<pair<uint64_t, uint64_t>> pt;
    for (uint64_t i = 0; i < n; i++) {
        uint64_t p, t;
        cin >> p >> t;
        pt.emplace_back(make_pair(p, t));
    }

    sort(pt.begin(), pt.end(), [](auto l, auto r) { return l.first > r.first; });

    uint64_t tt = m * k;
    uint64_t s = 0;
    for (uint64_t i = 0; i < pt.size() && tt > 0; i++) {
        uint64_t ts = pt[i].second > tt ? tt : pt[i].second;
        tt -= ts;
        s += pt[i].first * ts;
    }
    cout << s;
}