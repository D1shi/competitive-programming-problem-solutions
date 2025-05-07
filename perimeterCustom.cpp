#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> paper (101, vector<int> (101, 0));

    while (N--) {
        int x, y; cin >> x >> y;
        for (size_t i = 0; i < 10; i++) for (size_t j = 0; j < 10; j++) paper[i +y][j +x]++;
    }
    
    int perimeter = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (size_t y = 0; y < 101; y++) {
        for (size_t x = 0; x < 101; x++) {
            if (paper[y][x] <= 0) continue;
            cout << x << " " << y << endl;

            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 101 && ny < 101 && nx >= 0 && ny >= 0 && paper[ny][nx] == 0) perimeter++;
            }
        }
        
    }
    
    cout << perimeter << endl;
}