#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    vector<vector<int>> out = vector<vector<int>>(m1.size(), vector<int> (m2[0].size(), 0));

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m1[0].size(); ++k) {
                out[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return out;
}

int main() {
    vector<vector<int>> m = {
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 0}
    };

    auto m2 = multiplyMatrix(m, m);

    for (const auto& row : m2) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}