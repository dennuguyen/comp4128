#include <bitset>
#include <iostream>
#include <string>
using namespace std;

void print(uint64_t value, int n_bits) {
    for (int i = n_bits - 1; i >= 0; i--) {
        int bit = (value >> i) & 1;
        cerr << bit;
    }
    cerr << endl;
}

int str2bit(string s, int n) {
    int ss = 0;
    for (int i = 0; i < n; i++) {
        ss |= (s[i] == 'a' ? 0 : 1) << i;
    }
    print(ss, n);
    return ss;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    cerr << ("a" < "b") << endl;
    cerr << ("ab" < "ab") << endl;
    cerr << ("aba" < "abb") << endl;
    cerr << ("ab" < "ba") << endl;
    cerr << ("a" < "ba") << endl;
    cerr << ("a" < "ab") << endl;
    cerr << ("ba" < "ab") << endl;

    // int ss = str2bit(s, n);
    // int tt = str2bit(t, n);

    // cout << tt - ss - 1 + 2 * n;
}
