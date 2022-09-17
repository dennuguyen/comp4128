#include <iostream>
#include <string>
#include <vector>

using namespace std;

string compress(vector<int> tile) {
    string out;
    for (auto cnt : tile) {
        out += cnt > 4 ? "*" : ".";
    }
    return out;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> img;  // white=. black=*
    vector<int> num_blacks;
    num_blacks.resize(n);
    for (int i = 0; i < 3 * m; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 3 * n; j++) {
            cerr << j << " " << (int)(j / 3) << " " << num_blacks.size() << "\n";
            num_blacks.at((int)(j / 3)) += line[j] == '*' ? 1 : 0;
        }
        if ((i + 1) % 3 == 0) {
            cout << compress(num_blacks) << "\n";
            num_blacks.clear();
        }
    }
}