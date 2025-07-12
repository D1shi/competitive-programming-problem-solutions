#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

    int N, t = 0, out = INT_MAX; cin >> N;

    pair<int, int> pos {0, 0};
    map<pair<int, int>, int> visited;
    visited[pos] = 0;

    for (size_t i = 0; i < N; i++) {
        int dist; char c; cin >> c >> dist;
        pair<int, int> change;

        switch (c) {
            case 'N': change = {0, 1}; break;
            case 'E': change = {1, 0}; break;
            case 'S': change = {0, -1}; break;
            case 'W': change = {-1, 0}; break;
            default: break;
        }

        for (size_t i = 0; i < dist; i++) {
            pos.first += change.first;
            pos.second += change.second;

            if (visited.count(pos)) out = min(t - visited[pos], out);
            visited.insert_or_assign(pos, t);
            t++;
        }
                
    }
    
    if (out != INT_MAX) cout << out;
    else cout << -1;
}