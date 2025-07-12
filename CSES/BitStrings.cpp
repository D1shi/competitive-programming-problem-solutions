#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    size_t N, out = 1; cin >> N;
    while (N--) out = (out * 2) % 1000000007;
    cout << out << endl;
}