#include <bits/stdc++.h>
using namespace std;
using int = long long;

int main() {
    int N, M; string direct; 
    cin >> N >> M >> direct;

    map<int, int> trades;
    vector<int> cows (N);
    vector<int> caps;

    for (int& c : cows) cin >> c;
    caps = cows;
    
    while (M--) {
        vector<int> nCows = cows;
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
    for (const int& c : cows) out += c;
    cout << out;
}