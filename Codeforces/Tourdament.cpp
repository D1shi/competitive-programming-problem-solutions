#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t T; cin >> T;
    while (T--) {
        size_t N, i, K; cin >> N >> i >> K;

        vector<int> players (N);
        for (int& p : players) cin >> p;

        if (K >= 2) cout << "YES";
        else {
            bool big = true; --i;

            for (const int& p : players) 
                if (p > players[i]) { big = false; break; }

            cout << (big ? "YES" : "NO");
        }

        cout << endl;
    }
}