#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
int out = 0;

bool colUsed[8] = {};
bool diag1Used[15] = {};
bool diag2Used[15] = {};

void backtrack(int row) {
    if (row == 8) {
        ++out;
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '*') continue;

        int d1 = row + col;
        int d2 = row - col + 7;

        if (colUsed[col] || diag1Used[d1] || diag2Used[d2]) continue;

        colUsed[col] = diag1Used[d1] = diag2Used[d2] = true;
        backtrack(row + 1);
        colUsed[col] = diag1Used[d1] = diag2Used[d2] = false;
    }
}

int main() {
    for (int i = 0; i < 8; ++i) cin >> board[i];

    backtrack(0);
    cout << out << '\n';
}
