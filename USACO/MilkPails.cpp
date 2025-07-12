#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

    int X, Y, M, out = 0; cin >> X >> Y >> M;

    for (int i = 0; i < M; i++) {
        if (X * i > M) break;
        for (int j = 0; j < M; j++) {
            if (X * i + Y * j > M) break;
            out = max(out, (X * i + Y * j));
        }
    }
    
    cout << out;
}