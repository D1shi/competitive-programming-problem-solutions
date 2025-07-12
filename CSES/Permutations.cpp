#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    for (size_t i = 2; i <= N; i += 2) cout << i << " ";
    for (size_t i = 1; i <= N; i += 2) cout << i << " ";
}