#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;

    while (N--) {
        size_t a, b; cin >> a >> b; 
        cout << (((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0) ? "NO" : "YES") << endl;
    }
}