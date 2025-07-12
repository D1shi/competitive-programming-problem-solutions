#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;

    vector<ll> nums (N);
    for (ll& n : nums) cin >> n;

    ll anchor = -1, out = 0;
    for (ll& n : nums) {
        if (n > anchor) anchor = n;
        else out += anchor - n;
    }

    cout << out;
}