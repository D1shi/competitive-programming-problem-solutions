#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N;

    vector<int> metals (N);
    for (int& m : metals) cin >> m;

    cin >> K; 
    map<int, vector<int>> recipes;
    for (size_t i = 0; i < K; i++) {
        int L, M; cin >> L >> M; L--; 
        recipes.insert(make_pair(L, vector<int> (M)));
        for (int& m : recipes[L]) { cin >> m; m--; }
    }

    int currentM = N - 1;
    bool running = true;
    while (running) {
        bool making = true;
        
        for (const int& m : recipes[currentM]) {
            if (metals[m] == 0) {
                if (m == 0 || !recipes.count(m)) {
                    running = false;
                    break;
                } else {
                    making = false;
                    currentM = m;
                    break;
                }
            }
        }
        
        if (!running) break;
        if (!making) continue;

        for (const int& m : recipes[currentM]) metals[m]--;
        metals[currentM]++; currentM = N - 1;
    }
    
    cout << metals[N - 1];
}