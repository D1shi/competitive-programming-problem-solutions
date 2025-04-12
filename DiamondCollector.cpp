#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

    int N, K, out = 0; cin >> N >> K;
    
    vector<int> diamonds(N);
    for (int& n : diamonds) cin >> n;
    
    for (int x : diamonds) {
        int amount = 0;
        for (int y : diamonds) if (x <= y && y <= x + K) amount++;

        out = max(out, amount);
    }

    cout << out;
}
