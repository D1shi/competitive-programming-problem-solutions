#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    for (size_t K = 1; K <= N; ++K) cout << ((K * K) * (K * K - 1) / 2) - (4 * (K - 1) * (K - 2)) << endl;
}