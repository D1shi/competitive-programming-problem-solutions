#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

    int N, L, out = 0; cin >> N >> L;
    vector<string> spotty(N), normal(N);

    for (auto& c : spotty) cin >> c;
    for (auto& c : normal) cin >> c;

    for (int i = 0; i < L; i++) {
        unordered_set<char> found; bool good = true;
        for (auto c : spotty) found.insert(c[i]);
        for (auto c : normal) {
            if (found.find(c[i]) != found.end()) { good = false; break; }
        }

        if (good) out++;
    }

    cout << out;
}