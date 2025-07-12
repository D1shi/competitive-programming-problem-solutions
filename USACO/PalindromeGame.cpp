#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    
    while (T--) {
        string N; cin >> N;

        if (N.back() == '0') cout << "E";
        else cout << "B";

        cout << endl;
    }
}