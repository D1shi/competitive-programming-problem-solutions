#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    int N, Q; cin >> N >> Q;

    vector<vector<int>> sums (3, vector<int> (N + 1, 0));

    for (size_t i = 1; i <= N; i++) {
        int c; cin >> c;
        for (auto& sum : sums) sum[i] = sum[i - 1];
        sums[c - 1][i] += 1;
    }
    
    freopen("bcount.out", "w", stdout);
    while (Q--) {
        int l, r; cin >> l >> r;
        cout << sums[0][r] - sums[0][l - 1] << " ";
        cout << sums[1][r] - sums[1][l - 1] << " ";
        cout << sums[2][r] - sums[2][l - 1] << endl;
    }
}