#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const string r = "A23456789TJQKA";
const array<string, 21> combs = {"12345", "12346", "12347", "12356", "12357", "12367", "12456",
                                 "12457", "12467", "12567", "13456", "13457", "13467", "13567",
                                 "14567", "23456", "23457", "23467", "23567", "24567", "34567"};
const array<string, 10> outs = {"",         "straight flush", "four of a kind",  "full house",
                                "flush",    "straight",       "three of a kind", "two pair",
                                "one pair", "high card"};

unsigned long index(size_t i, size_t pos) { return (unsigned long)(combs[i][pos] - '0') - 1; }

int poker(array<pair<char, char>, 5> cards) {
    map<char, int> seen_ranks;
    map<char, int> seen_suits;

    for (auto card : cards) {
        seen_ranks[card.first]++;
        seen_suits[card.second]++;
    }

    array<int, 5> cnt = {0};
    string str;
    str.reserve(5);
    for (auto [k, v] : seen_ranks) {
        cnt[v]++;
        str += k;
    }

    int sig = 9;

    if (cnt[2] == 1) {
        sig = 8;
    }

    if (cnt[2] == 2) {
        sig = 7;
    }

    if (cnt[3] == 1) {
        sig = 6;
    }

    bool is_straight = false;
    for (auto it = r.begin(); it + 4 != r.end(); it++) {
        auto tmp_r = string(it, it + 5);
        sort(tmp_r.begin(), tmp_r.end());
        if (str == tmp_r) {
            is_straight = true;
            sig = 5;
            break;
        }
    }

    bool is_flush = false;
    if (any_of(seen_suits.begin(), seen_suits.end(), [](auto i) { return i.second >= 5; })) {
        is_flush = true;
        sig = 4;
    }

    if (cnt[3] == 1 && cnt[2] == 1) {
        sig = 3;
    }

    if (cnt[4] == 1) {
        sig = 2;
    }

    if (is_flush && is_straight) {
        sig = 1;
    }

    return sig;
}

int main() {
    vector<pair<char, char>> c;
    for (int i = 0; i < 7; i++) {
        string card;
        cin >> card;
        c.emplace_back(make_pair(card[0], card[1]));
    }

    int sig = 9;
    for (int i = 0; i < combs.size(); i++) {
        int tsig =
            poker({c[index(i, 0)], c[index(i, 1)], c[index(i, 2)], c[index(i, 3)], c[index(i, 4)]});
        if (tsig < sig) {
            sig = tsig;
        }
    }
    cout << outs[sig];
}