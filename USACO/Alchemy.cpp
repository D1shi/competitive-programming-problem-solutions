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
        vector<int> recipe(M);
        for (int& m : recipe) cin >> m;
        recipes[L] = recipe;
    }

    int currentM = N - 1;
    bool running = true;

    while (true) {
        bool making = true;
        
        for (const int& m : recipes[currentM]) {
            if (metals[m] == 0) {
                if (m == 0 || !recipes.count(m)) {
                    running = false;
                } else {
                    making = false;
                    currentM = m;
                }
                break;
            }
        }
        
        if (!running) break;
        if (!making) continue;

        for (const int& m : recipes[currentM]) metals[m]--;
        metals[currentM]++; currentM = N - 1;
    }
    
    cout << metals[N - 1];
}