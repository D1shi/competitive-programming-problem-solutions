#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

    int N, out; cin >> N >> out; out = INT_MAX;
    vector<pair<int, int>> cows (N);
    set<int> Xs, Ys;

    for (auto& [x, y] : cows) { 
        cin >> x >> y;
        Xs.insert(x + 1);
        Ys.insert(y + 1);
    }

    for (const auto& X : Xs) {
        for (const auto& Y : Ys) {
            vector<int> quads (4, 0);
        
            for (const auto& [x, y] : cows) {
                if (X == x || Y == y) break;
                if (x > X && y > Y) quads[0]++;
                if (x < X && y > Y) quads[1]++;
                if (x > X && y < Y) quads[2]++;
                if (x < X && y < Y) quads[3]++;
            }
            
            sort(quads.begin(), quads.end());
            out = min(quads[3], out);
        }
        
    }

    cout << out;
}