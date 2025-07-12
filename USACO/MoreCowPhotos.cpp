#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int N, maxHeight = -1; cin >> N;

        vector<int> cows (N);
        for (auto& c : cows) { 
            cin >> c;
            maxHeight = max(c, maxHeight);
        }
        
        set<int> seenHeights, pairHeights;
        for (const auto& c : cows) { 
            // if this height is the max or already has a pair, skip
            if (pairHeights.count(c) || c == maxHeight) continue;

            if (seenHeights.count(c)) { // if we've seen this height before, add to pair heights
                seenHeights.erase(c);
                pairHeights.insert(c);
            } else seenHeights.insert(c); // otherwise, add to seen heights
        }

        cout << pairHeights.size() * 2 + 1 << endl; // add one to account for the biggest cow
    }
}