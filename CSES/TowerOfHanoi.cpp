#include <bits/stdc++.h>
using namespace std;

void solve(int disk, int start, int end, int middle) {
    if (disk == 1) cout << start << " " << end << endl;
    else {
        solve(--disk, start, middle, end);
        cout << start << " " << end << endl;
        solve(disk, middle, end, start);
    }
}

int main() {
    int N; cin >> N;
    cout << (1 << N) - 1 << endl;
    solve(N, 1, 3, 2);
}