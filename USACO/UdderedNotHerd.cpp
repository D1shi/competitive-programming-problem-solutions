#include <bits/stdc++.h>
using namespace std;

int main() {
    int out = 1;
    string S, said; cin >> S >> said;
    map<char, int> alphabet;
    
    for (int i = 0; i < S.length(); i++) alphabet[S[i]] = i;

    int last;
    for (char curr : said) {
        if (alphabet[curr] <= last) out++;
        last = alphabet[curr];
    }

    cout << out;
}