#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    ll curr = 0, out = 0; 
    vector<ll> sums;

    for (size_t i = 0; i < N; i++) {
        ll n; cin >> n; curr += n;

        if (curr == K) out++;
        if (find(sums.begin(), sums.end(), curr - K) != sums.end()) out++;

        sums.push_back(curr);
    }

    cout << out;
}