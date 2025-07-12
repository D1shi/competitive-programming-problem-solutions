#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

    int N, out = 0; cin >> N;
    vector<vector<bool>> cows (N, vector<bool> (N, false)); 
    for (auto& cRow : cows) {
        string in; cin >> in;
        for (int i = 0; i < N; i++) cRow[i] = (in[i] == '1');
    }

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (cows[i][j]) { // if current cow is flipped
                for (int a = 0; a <= i; ++a) for (int b = 0; b <= j; ++b) cows[a][b] = !cows[a][b];
                out++;
            }
        }
    }

    cout << out;
}