#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("div7.in", "r", stdin);
    ll N; cin >> N;

    vector<ll> sums (N + 1, 0);
    vector<int> mods (N + 1, 0);

    for (size_t i = 1; i <= N; i++) {
        ll c; cin >> c;
        sums[i] = sums[i - 1] + c;
        mods[i] = sums[i] % 7;
    }

    ll out = 0;
    for (size_t r = 0; r < 7; r++) {
        ll lower = -1, upper = -1;
        for (size_t i = 0; i <= N; i++) {
            if (mods[i] == r) {
                if (lower == -1) lower = i;
                upper = i;
            }
        }

        out = max(upper - lower, out);
    }

    freopen("div7.out", "w", stdout);
    cout << out << endl;
}