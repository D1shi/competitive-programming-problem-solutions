#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<vector<bool>> beats (N, vector<bool>(N, false));
    for (size_t i = 0; i < N; i++) {
        string row; cin >> row;
        for (size_t j = 0; j < row.size(); j++) {
            if (row[j] == 'W') beats[i][j] = true;
            if (row[j] == 'L') beats[j][i] = true;
        }     
    }
    
    for (size_t i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x--; y--;

        int winning = 0;
        for (int b = 0; b < N; b++) if (beats[b][x] && beats[b][y]) winning++;
        
        cout << pow(N, 2) - pow(N - winning, 2) << endl;
    }
}