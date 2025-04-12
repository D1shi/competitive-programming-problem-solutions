#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M; string direct; 
    cin >> N >> M >> direct;

    map<int, int> trades;
    vector<ll> cows (N);
    vector<ll> caps;

    for (ll& c : cows) cin >> c;
    caps = cows;
    
    while (M--) {
        vector<ll> nCows = cows;
        for (size_t i = 0; i < N; i++) {
            if (cows[i] > 0) {
                nCows[i]--;

                if (direct[i] == 'L') nCows[(i - 1 + N) % N]++;
                else nCows[(i + 1) % N]++;
            }
        }
        
        for (size_t i = 0; i < N; i++) nCows[i] = min(nCows[i], caps[i]);
        cows = nCows;
    }
    
    int out = 0;
    for (const ll& c : cows) out += c;
    cout << out;
}