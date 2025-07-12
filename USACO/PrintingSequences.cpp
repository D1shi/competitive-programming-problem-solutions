#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
int N, K;
map<tuple<int, int, set<int>>, bool> memo;

// Get how many times the pattern [l..r] repeats
int getRepeatCount(int l, int r) {
    int len = r - l + 1;
    int cnt = 1;
    while (l + cnt * len + len - 1 < (int)seq.size()) {
        bool match = true;
        for (int i = 0; i < len; ++i) {
            if (seq[l + i] != seq[l + cnt * len + i]) {
                match = false;
                break;
            }
        }
        if (!match) break;
        cnt++;
    }
    return cnt;
}

bool dfs(int l, int r, set<int> used) {
    if (l > r) return true;

    auto state = make_tuple(l, r, used);
    if (memo.count(state)) return memo[state];

    // Base case: single element
    if (l == r) {
        memo[state] = (used.count(seq[l]) || (int)used.size() < K);
        return memo[state];
    }

    // Try all possible pattern lengths
    for (int len = 1; l + len - 1 <= r; ++len) {
        int rep = getRepeatCount(l, l + len - 1);
        int total = len * rep;
        if (l + total - 1 > r) continue;

        // Compute PRINT values used in the pattern
        set<int> patternUsed = used;
        for (int i = 0; i < len; ++i) patternUsed.insert(seq[l + i]);
        if ((int)patternUsed.size() > K) continue;

        if (dfs(l, l + len - 1, patternUsed) &&
            dfs(l + total, r, patternUsed)) {
            memo[state] = true;
            return memo[state];
        }
    }

    memo[state] = false;
    return memo[state];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        seq.resize(N);
        for (int i = 0; i < N; ++i) cin >> seq[i];
        memo.clear();
        if (dfs(0, N - 1, {})) cout << "YES\n";
        else cout << "NO\n";
    }
}
