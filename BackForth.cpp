#include <bits/stdc++.h>
using namespace std;

void simulate(int T1, int T2, vector<int> B1, vector<int> B2, int day, set<int>& possible) {
    if (day == 4) { possible.insert(T1); return; }

    sort(B1.begin(), B1.end());
    sort(B2.begin(), B2.end());

    int prev = -1;
    for (size_t i = 0; i < B1.size(); i++) {
        if (B1[i] == prev) continue;

        vector<int> NB1 = B1, NB2 = B2;
        
        NB1.erase(NB1.begin() + i);
        NB2.push_back(B1[i]);

        simulate(T2 + B1[i], T1 - B1[i], NB2, NB1, day + 1, possible);
        prev = B1[i];
    }
    
}

int main() {
    freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

    vector<int> B1 (10), B2 (10);
    set<int> possible;
    for (int& b : B1) cin >> b;
    for (int& b : B2) cin >> b;

    simulate(1000, 1000, B1, B2, 0, possible);
    cout << possible.size();
}



