#include <bits/stdc++.h>
using namespace std;

set<set<char>> out[4];
vector<string> board (3);

void check(vector<pair<int, int>> coords) {
    set<char> cows;
    for (pair<int, int> c : coords) cows.insert(board[c.first][c.second]);

    if (cows.size() < 3) out[cows.size()].insert(cows);    
}

int main() {
    freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
    for (auto& c : board) cin >> c;
    
    for (int i = 0; i < 3; i++) {
        check({{i, 0}, {i, 1}, {i, 2}});
        check({{0, i}, {1, i}, {2, i}});
    }

    check({{0, 0}, {1, 1}, {2, 2}});
    check({{0, 2}, {1, 1}, {2, 0}});

    cout << out[1].size() << endl << out[2].size() << endl;
}