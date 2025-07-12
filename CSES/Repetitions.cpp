#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    int count = 1, out = -1; 
    char prev = '_';

    for (char& c : S) {
        if (c != prev) { 
            out = max(count, out);
            count = 1;
        }
        else count++;
        
        prev = c;
    }

    out = max(count, out);
    cout << out;
}