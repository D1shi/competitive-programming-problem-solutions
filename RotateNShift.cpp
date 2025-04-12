#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, T; cin >> N >> K >> T;
    vector<int> cows (N), active (K);
    for (size_t i = 0; i < N; i++) cows[i] = i;
    for (auto& i : active) cin >> i;
    
    while (T--) {
        vector<int> newCows = cows;

        for (size_t i = 0; i < K - 1; i++) newCows[active[i + 1]] = cows[active[i]];
        newCows[active[0]] = cows[active[K - 1]];

        for (auto& i : active) { i++; if (i == N) i = 0; } 

        cows = newCows;
    }

    for (const auto& c : cows) cout << c << " ";
}