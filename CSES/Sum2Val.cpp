#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    map<int, int> indexes;

    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (indexes.count(K - n)) {
            cout << indexes[K - n] + 1 << " " << i + 1;
            return 0;
        }

        indexes[n] = i;
    }

    cout << "IMPOSSIBLE";
}