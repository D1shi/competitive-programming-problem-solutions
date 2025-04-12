#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

    int out = 0, N, M, C; cin >> N >> M >> C;

    vector<int> cows (N);
    for (int& c : cows) cin >> c;

    sort(cows.begin(), cows.end());

    
    
    cout << out;
}