#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    bool is1social = false;

    vector<int> cows(N, -1), social(M);
    map<int, int> fixed;

    for (int& c : social) cin >> c;
    for (size_t _ = 0; _ < K; _++) {
        int i, c; cin >> c >> i;
        fixed[c] = i - 1;
        if (c == 1) { cout << i; return 0; }
        cows[i - 1] = c; 
    }
    
    size_t i = N - 1;
    int curr;
    for (curr = M - 1; curr >= 0; --curr) {
        int c = social[curr];

        is1social = c == 1;
        if (is1social) break;

        if (fixed.count(c)) {
            i = fixed[c];
            continue;
        }

        while (cows[i] != -1) --i;
        if (i < 0) break;
        cows[i] = c;
    }

    if (is1social) {
        i = 0;
        for (curr = 0; curr < M; ++curr) {
            int c = social[curr];
    
            if (fixed.count(c)) {
                i = fixed[c];
                continue;
            }
    
            while (cows[i] != -1) ++i;
            cows[i] = c;

            if (c == 1) break;
        }

        cout << i + 1;
        return 0;
    }
    
    for (int oi = 0; oi < N; oi++) {
        if (cows[oi] != -1) continue;

        cout << oi + 1; break;
    }
}