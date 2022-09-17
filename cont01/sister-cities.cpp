#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, double>> s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        string city;
        double temp;
        cin >> city >> temp;
        s.emplace_back(std::make_pair(city, temp));
    }

    std::sort(s.begin(), s.end(), [](auto const& l, auto const& r) { return l.second < r.second; });

    auto p1 = s[n - 1];
    auto p2 = s[0];
    double diff = fabs(p1.second - p2.second);
    string city1 = p1.first;
    string city2 = p2.first;
    for (int i = 0; i < n - 1; i++) {
        p1 = s[i + 1];
        p2 = s[i];
        double tdiff = fabs(p1.second - p2.second);
        if (tdiff <= diff) {
            diff = tdiff;
            city1 = p1.first;
            city2 = p2.first;
        }
    }

    cout << city1 << " " << city2;
}