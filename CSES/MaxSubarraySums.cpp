#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;

    vector<ll> pfx (N + 1);
    for (size_t i = 1; i <= N; ++i) {
        ll n; cin >> n;
        pfx[i] = pfx[i - 1] + n;
    }
    
    ll out = pfx[1], lower = 0;
    for (size_t i = 1; i <= N; ++i) {
        out = max(pfx[i] - lower, out);
        lower = min(pfx[i], lower);
    }

    cout << out;
}