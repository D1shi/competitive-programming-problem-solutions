#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int startMatch = 0;

    vector<int> cows(N), pref(N);
    for (auto& c : cows) cin >> c;
    for (auto& c : pref) cin >> c;

    vector<int> out (N + 1, 0);
    for (size_t i = 0; i < N; i++) if (cows[i] == pref[i]) startMatch++;

    auto evaluate = [&](int lower, int upper) {
        int matching = startMatch;

        for (; lower > -1 && upper < N; lower--, upper++) {
            // add (new same - old same)
            matching +=
            ((cows[upper] == pref[lower]) + (pref[upper] == cows[lower])) -
            ((cows[upper] == pref[upper]) + (pref[lower] == cows[lower]));

            out[matching]++;
        }
    };

    for (size_t i = 0; i < N; i++) {
        evaluate(i, i);
        evaluate(i, i + 1);
    }
    
    
    for (auto c : out) cout << c << endl;
}