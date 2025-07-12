#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

    int N, G, out = 0; cin >> N >> G;
    
    map<int, pair<int, int>> changes;
    vector<int> winners;
    map<int, int> cows;

    for (int i = 0; i < N; i++) {
        int day, amount, name;
        cin >> day >> name >> amount;

        changes[day] = make_pair(name, amount);
    }
    
    for (auto [_, info] : changes) {
        vector<int> newWin; int maxMilk = 0;
        
        if (cows.count(info.first)) cows[info.first] += info.second;
        else cows[info.first] = G + info.second;
        
        for (auto [_, amount] : cows) maxMilk = max(maxMilk, amount);
        for (auto [name, amount] : cows) if (amount == maxMilk) newWin.push_back(name);

        out += winners != newWin;
        winners = newWin;
    }

    cout << out << endl;
}