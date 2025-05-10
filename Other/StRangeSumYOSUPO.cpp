#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q; cin >> N >> Q;

    vector<ll> nums (N);
    vector<ll> sums (N + 1, 0);

    for (size_t i = 1; i <= N; i++) {
        cin >> nums[i - 1];
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    
    while (Q--) {
        ll l, r; cin >> l >> r;
        cout << sums[r] - sums[l] << endl;
    }
}