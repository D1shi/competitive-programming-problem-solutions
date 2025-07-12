#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> people (N), apartments (M);

    for (ll& p : people) cin >> p;
    for (ll& a : apartments) cin >> a;

    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    ll pI = 0, aI = 0, out = 0;
    while (pI < N && aI < M) {
        ll p = people[pI], a = apartments[aI];

        if ((a - K) <= p && p <= (a + K)) {
            pI++; aI++; out++;
        } else if (p > (a + K)) aI++;
        else pI++;
    }

    cout << out;
}