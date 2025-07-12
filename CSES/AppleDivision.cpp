#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

size_t N;
vector<size_t> apples;

size_t solve(size_t i, ll g1, ll g2) {
    if (i == N) return abs(g1 - g2);

    size_t n = apples[i++],
           testG1 = solve(i, g1 + n, g2),
           testG2 = solve(i, g1, g2 + n);

    return min(testG1, testG2);
}

int main() {
    cin >> N;
    
    apples = vector<size_t> (N);
    for (auto& n : apples) cin >> n;

    cout << solve(0, 0, 0);
}