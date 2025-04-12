#include <bits/stdc++.h>
using namespace std;

int N, M, K;

void update(int& x, int& y, int& dist, int& visited, vector<vector<int>>& mat) {
    if (x < 0 || x >= M || y < 0 || y >= N) return;
    visited++;
    mat[y][x] = max(mat[y][x], dist);
}

int main() {
    int x, y, z; cin >> N >> M >> K;
    vector<int> dx, dy;
    vector<vector<int>> mat (N, vector<int> (N, -1));

    while (K--) {
        cin >> x >> y >> w;
        x--; y--;
        
        if (w == 0) {
            dx = {0, -1, 0, 1};
            dy = {-1, 0, 1, 0};
        } else {
            dx = {0, -1, 0, 1};
            dy = {1, 0, -1, 0};
        }

        int dirIndx = 1, dist = 1;
        int len = 1, left = 2;
        int visited = 0;
        update(x, y, dist, visited, mat);
        while (true) {
            if (visited >= N * M) break;
            if (left == 0) {
                len++;
                left = 2;
            }

            for (size_t _ = 0; _ < len; _++) {
                x += dx[dirIndx];
                y += dy[dirIndx];
                dist++;
                update(x, y, dist, visited, mat);
            }
            
            left--;
            dirIndx = (dirIndx + 1) % 4;
        }
    }

    for (size_t i = 0; i < N; i++) for (size_t j = 0; j < M; j++) cout << mat[i][j] << endl;
    
    
}