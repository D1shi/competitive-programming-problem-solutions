#include <bits/stdc++.h>
using namespace std;
typedef size_t ll;

int main() {
    ll N; cin >> N;
    set<ll> nums;

    for (ll i = 0; i < N; i++) {
        ll n; cin >> n;
        nums.insert(n);
    }

    cout << nums.size();
}