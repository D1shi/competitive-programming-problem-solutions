#include <bits/stdc++.h>
using namespace std;

void solve(int& N, int& a, int& b) {
    int draws = N - (a + b);
    if (draws < 0) { cout << "NO"; return; }

    vector<int> aOut, bOut (N);
    iota(bOut.begin(), bOut.end(), 1);

    int turn = 0;

    for (size_t i = b + 1; i <= a + b; ++i) {
        aOut.push_back(i);
        if (bOut[turn] >= aOut[turn]) { cout << "NO"; return; }

        ++turn;
    }

    for (size_t i = 1; i <= b; i++) {
        aOut.push_back(i);
        if (bOut[turn] <= aOut[turn]) { cout << "NO"; return; }

        ++turn;
    }

    for (size_t i = a + b + 1; i <= N; i++) {
        aOut.push_back(i);
        if (bOut[turn] != aOut[turn]) { cout << "NO"; return; }

        ++turn;
    }

    cout << "YES" << endl;
    for (const auto& _ : aOut) cout << _ << " "; cout << endl;
    for (const auto& _ : bOut) cout << _ << " "; cout << endl;
}

int main() {
    size_t T; cin >> T;
    while (T--) {
        int N, a, b; cin >> N >> a >> b;
        solve(N, a, b);
    }
}