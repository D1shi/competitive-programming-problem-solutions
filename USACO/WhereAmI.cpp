#include <bits/stdc++.h>
using namespace std;

int main() {
    // link io to files for old compiler
    freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

    int N;
    string order;
    cin >> N >> order;

    for (int l = 1; l <= N; l++) {
        bool out = true;
        set<string> seen;

        for (int i = 0; i <= N - l; i++) {
            string subS = order.substr(i, l);
            out = !seen.count(subS);
            if (!out) break;
            seen.insert(subS);
        }

        if (out) { cout << l << endl; break; }
    }
}