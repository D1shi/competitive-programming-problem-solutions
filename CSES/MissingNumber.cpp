#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll trueSum = (N * (N + 1)) / 2, inpSum = 0;

    for (size_t i = 0; i < N - 1; i++) {
        ll n; cin >> n; inpSum += n;
    }

    cout << trueSum - inpSum;
}