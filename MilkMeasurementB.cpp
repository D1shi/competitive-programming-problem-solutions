#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

    int N, out = 0; cin >> N;
    map<int, pair<string, int>> changes;
    vector<string> ranks {"Bessie", "Elsie", "Mildred"};
    map<string, int> cows;
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;

    for (int i = 0; i < N; i++) {
        int day, amount; string name;
        cin >> day >> name >> amount;

        changes[day] = make_pair(name, amount);
    }
    
    for (auto [_, info] : changes) {
        cows[info.first] += info.second;

        // find winner
        int maxMilk = 0;
		for (auto [_, milk] : cows) maxMilk = max(maxMilk, milk);

        // if winning, add
        vector<string> nextR;
        for (auto [name, milk] : cows) if (milk == maxMilk) nextR.push_back(name);
		
        out += nextR != ranks;
        ranks = nextR;
    }

    cout << out;
}