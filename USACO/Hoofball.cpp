#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> cows;
set<int> visited;

int pass(int i, int prev) {
    if (visited.count(i)) return prev;
    visited.insert(i);

    int curr = cows[i], 
        l = max(i - 1, 0), left = cows[l], 
        r = min(i + 1, N - 1), right = cows[r];

    if (curr - left < right - curr && left != curr) return pass(l, i);
    else if (right - curr > left - curr && right != curr) return pass(r, i);
    else return pass(l, i);
}

int main() {
    freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
    cin >> N;

    cows = vector<int> (N);
    for (int& c : cows) cin >> c;

    sort(cows.begin(), cows.end());

    int l = 0, u = N - 1, out = 0; // lower, upper which are the cows we're gonna check next
    while (visited.size() != N) {
        l = pass(l, l); out++; 
        if (visited.size() == N) break;
        u = pass(u, u); out++;
    }

    cout << out;
}