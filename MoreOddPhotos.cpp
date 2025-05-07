#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, odd = 0, even = 0; cin >> N;

    for (size_t i = 0; i < N; i++) {
        int n; cin >> n;
        if (n % 2 == 0) even++;
        else odd++;
    }
    
    if (odd <= even) cout << odd * 2 << endl;
    else cout << even * 2 + 1 << endl;
}