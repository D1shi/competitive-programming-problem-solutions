#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll target = (N * (N + 1)) / 2;
    vector<ll> s1, s2;

    if (target % 2 != 0 || N == 1) {
        cout << "NO";
        return 0;
    }

    target /= 2;
    cout << "YES" << endl;

    for (int n = N; n > 0; --n) {
        if (target >= n) {
            s1.push_back(n);
            target -= n;
        } else s2.push_back(n);
    }

    cout << s1.size() << endl;
    for (auto& n : s1) cout << n << " ";
    cout << endl;

    cout << s2.size() << endl;
    for (auto& n : s2) cout << n << " ";
}