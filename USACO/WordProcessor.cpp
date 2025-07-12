#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

    int N, pref, curr = 0; 
    cin >> N >> pref;

    for (size_t i = 0; i < N; i++) {
        string word; cin >> word;
        curr += word.length();

        if (curr > pref) {
            cout << endl << word;
            curr = 0;
        } else cout << word << " ";
    }
}