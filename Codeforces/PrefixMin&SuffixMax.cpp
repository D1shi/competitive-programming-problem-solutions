#include <bits/stdc++.h>
using namespace std;

void solve(size_t& N, vector<int>& arr) {
    vector<int> pref (N, arr[0]), suff (N, arr[N - 1]);

    for (int i = 1; i < N; ++i) {
        pref[i] = min(pref[i - 1], arr[i]);
        suff[N - i - 1] = max(suff[N - i], arr[N - i - 1]);
    }

    for (int i = 0; i < N; ++i) {
        if (i == 0 || i == N - 1) { cout << 1; continue; }

        cout << !(arr[i] > pref[i] && arr[i] < suff[i]);
    }
}

int main() {
    size_t T; cin >> T;

    while (T--) {
        size_t N; cin >> N;

        vector<int> arr(N);
        for (int& n : arr) cin >> n;

        solve(N, arr);
        cout << endl;
    }
}