#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<string> rows (N);
    vector<vector<bool>> has_star (N, vector<bool>(N));

    for (auto &row : rows) cin >> row;
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (rows[y][x] == 'B') {
                if (y - Y < 0 || x - X < 0) return -1;
                has_star[y][x] = has_star[y - Y][x - X] = 1;
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (rows[y][x] == 'W' && has_star[y][x]) return -1;
            else if (rows[y][x] == 'G') {
                if (has_star[y][x] || (y >= Y && x >= X && has_star[y - Y][x - X])) continue;
                has_star[y][x] = true;
            }
        }
    }

    int ans = 0;
    for (const auto &row : has_star) ans += accumulate(begin(row), end(row), 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}