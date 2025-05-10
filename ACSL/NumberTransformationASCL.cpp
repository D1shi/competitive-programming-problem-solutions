#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    int P, D; cin >> P >> D;

    ll output = 0;
    int value = 1;
    int place = 1;
    while (N > 0) {
        int digit = N % 10;
        digit += ((place <= P) ? D : -1 * D);
        digit %= 10;

        output += digit * value;
        place++; value *= 10;
    }

    cout << output;
}