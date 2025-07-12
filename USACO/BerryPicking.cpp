#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
    int N, K; cin >> N >> K;

    vector<int> trees (N);
    for (int& t : trees) cin >> t;

    sort(trees.begin(), trees.end());
    int min = trees[max(0, trees.size() - K)];
    reverse(trees.begin(), trees.end());

    vector<int> baskets;

    for (const int& t : trees) {
        if (baskets.size() == K) break;

        if (t % 2 == 0 && t / 2 > min && baskets.size() + 2 < K) {
            min = t / 2;
            baskets.push_back(t / 2);
            baskets.push_back(t / 2);
        } 
        else baskets.push_back(t);
    }

    sort(baskets.begin(), baskets.end());
    if (baskets.size() % 2 == 1) {
        baskets.push_back(static_cast<int>(baskets[0] / 2));
        baskets.push_back(static_cast<int>(ceil(baskets[0] / 2)));
        baskets.erase(0);
    }

    int berries = 0;
    for (size_t i = 0; i < K / 2; i++) berries += baskets[i];
    
    cout << berries;
}