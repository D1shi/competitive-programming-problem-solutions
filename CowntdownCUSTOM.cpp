#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, out = 0; cin >> D;

    for (; D > 0; ++out) {
        int days = D, sum = 0;
        while (days > 0) {
            sum += days % 10;
            days /= 10;
        }

        D -= sum;
    }

    cout << out;
}