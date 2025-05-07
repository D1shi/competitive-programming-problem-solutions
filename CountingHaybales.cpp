#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    int N, Q; cin >> N >> Q;

    vector<int> haybales (N);
    for (int& h : haybales) cin >> h;
    
    sort(haybales.begin(), haybales.end());

    freopen("haybales.out", "w", stdout);
    while (Q--) {
        int lTarget, rTarget; 
        cin >> lTarget >> rTarget;

        cout << upper_bound(haybales.begin(), haybales.end(), rTarget) 
            - lower_bound(haybales.begin(), haybales.end(), lTarget) << endl;
    }
}