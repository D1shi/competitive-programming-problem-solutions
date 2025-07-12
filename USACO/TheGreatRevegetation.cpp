#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

    int N, M; cin >> N >> M;
    string out = "";
    
    vector<pair<int, int>> cows(M);
    vector<set<int>> taken(N);
    
    // take in input, make sure to zero index
    for (auto& [f1, f2] : cows) { cin >> f1 >> f2; f1--; f2--; }
    
    for (int i = 0; i < N; i++) {
        // find grass
        int g;
        for (g = 1; g <= 4; g++) if (!taken[i].count(g)) break;
        
        // add to output
        out += to_string(g);

        // disable it on all other fields paired with this one
        for (auto [f1, f2] : cows) {
            if (f1 == i) taken[f2].insert(g);
            if (f2 == i) taken[f1].insert(g);
        }
    }

    cout << out;
}