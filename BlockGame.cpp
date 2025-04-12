#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

    int N; cin >> N;
    vector<int> letters (26);

    for (size_t i = 0; i < N; i++) {
        string w1, w2; cin >> w1 >> w2;
        vector<int> fr1 (26, 0), fr2 (26, 0);
        
        for (const auto& c : w1) fr1[c - 'a']++;
        for (const auto& c : w2) fr2[c - 'a']++;
        
        for (size_t i = 0; i < 26; i++) letters[i] += max(fr1[i], fr2[i]);
    }
    
    for (const auto& o : letters) cout << o << endl;
}