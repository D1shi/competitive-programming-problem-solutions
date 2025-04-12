#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crossroad.in", "r", stdin);
	freopen("crossroad.out", "w", stdout);

    int N, out = 0; cin >> N;
    map<int, bool> cows;
    
    for (int i = 0; i < N; i++) {
        int cow; bool pos; cin >> cow >> pos;

        if (cows.count(cow) && cows[cow] != pos) out++;
        cows.insert_or_assign(cow, pos);
    }
    
    cout << out;
}