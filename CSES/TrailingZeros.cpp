#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    size_t N, out = 0; cin >> N;
    for (size_t power = 5; N / power >= 1; power *= 5) {
        out += N / power;
    }

    cout << out;
}