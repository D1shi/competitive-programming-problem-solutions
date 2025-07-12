#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

    int N; cin >> N;
    map<string, int> cows = {
        {"Bessie", 0}, 
        {"Elsie", 0}, 
        {"Daisy", 0}, 
        {"Gertie", 0}, 
        {"Annabelle", 0}, 
        {"Maggie", 0},
        {"Henrietta", 0}
    };

    for (size_t i = 0; i < N; i++) {
        string cow; int milk; cin >> cow >> milk;
        cows[cow] += milk;
    }

    map<int, vector<string>> leaderboard;
    for (const auto& [cow, milk] : cows) {
        if (leaderboard.count(milk)) leaderboard[milk].push_back(cow);
        else leaderboard[milk] = {cow};
    }

    if (leaderboard.size() < 2) { cout << "Tie"; return 0; }
    
    auto it = leaderboard.begin();
    advance(it, 1);
    
    if (it->second.size() > 1) cout << "Tie";
    else cout << it->second[0];
}