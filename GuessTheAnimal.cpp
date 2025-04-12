#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

    int N, out = 0; cin >> N;
    map<int, set<string>> animals;

    for (size_t i = 0; i < N; i++) {
        string trait; int K; cin >> trait >> K;
        animals[i] = {};
        for (size_t j = 0; j < K; j++) { cin >> trait; animals[i].insert(trait); }
    }
    
    for (auto [_1, t1] : animals) {
        for (auto [_2, t2] : animals) {
            if (_1 >= _2) continue;
            t1.merge(t2);

            // +1 for unqiue trait
            out = max(out, static_cast<int>(t2.size()) + 1);
        }
    }

    cout << out;
}