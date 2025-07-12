#include <bits/stdc++.h>
using namespace std;

int N, U; 

int findChanges(vector<vector<bool>> grid) {
    vector<vector<int>> quad (N/2, vector<int> (N/2));
    int out = 0;

    for (size_t i = 0; i < N/2; i++) {
        int mI = N - i - 1;
        for (size_t j = 0; j < N/2; j++) {
            int mJ = N - j - 1;

            int tiles = grid[i][j] + grid[mI][j] + grid[i][mJ] + grid[mI][mJ];

            if (tiles < 2) { // want to be empty, if empty, no need to add changes
                out += tiles;
            }

            else if (tiles > 2) { // want to be full
                out += !grid[i][j];
                out += !grid[mI][j];
                out += !grid[i][mJ];
                out += !grid[mI][mJ];
            }

            else out += N/2;
        }
    }

    return out;
}

int main() {
    cin >> N >> U;
    vector<vector<bool>> grid (N, vector<bool> (N));

    for (size_t i = 0; i < N; i++) {
        string row; cin >> row;
        for (size_t j = 0; j < N; j++) grid[i][j] = row[j] == '#';
    }

    cout << findChanges(grid) << endl;

    for (size_t u = 0; u < U; u++) {
        int i, j; cin >> i >> j;
        grid[i - 1][j - 1] = !grid[i - 1][j - 1];
        cout << findChanges(grid) << endl;
    }
    
}

