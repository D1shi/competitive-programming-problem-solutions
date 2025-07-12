#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t T; cin >> T;
    while (T--) {
        size_t n; cin >> n; 
        cout << ((n % 4 == 0) ? "Bob" : "Alice") << endl;
    }
}