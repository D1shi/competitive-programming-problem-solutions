#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll T; cin >> T;

    while (T--) {
        ll x, y; cin >> y >> x;
        ll layer = max(x, y), anchor = layer * layer;
        bool even = layer % 2 == 0;
        
        if (y == layer) {
            if (!even) anchor = (layer - 1) * (layer - 1) + 1;
            anchor += ((x - 1) * (even ? -1 : 1));
        } else {
            if (even) anchor = (layer - 1) * (layer - 1) + 1;
            anchor -= ((y - 1) * (even ? -1 : 1));
        }

        cout << anchor << endl;
    }
}