#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

    int N, T = 0; cin >> N;

    vector<pair<int, int>> cows (N);
    for (auto& [s, e] : cows) {
        cin >> s >> e;
        T = max(T, e);
    }

    
    int out = 0;
    for (size_t i = 0; i < N; i++) { 
        int cover = 0;
        
        for (int t = 1; t <= T; t++) {
            for (size_t j = 0; j < N; j++) {
                if (j == i) continue;
                
                if (cows[j].first <= t && t < cows[j].second) {
                    cover++;
                    break;
                }
            }
              
        }

        out = max(out, cover);
    }

    cout << out;
}