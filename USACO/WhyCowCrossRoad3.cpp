#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

	int N; cin >> N;
	vector<pair<int, int>> cows(N);

	for (auto& [arrival, dur] : cows) cin >> arrival >> dur;
	sort(cows.begin(), cows.end());

	int curr_time = 0;
	for (auto [arrival, dur] : cows) {
		curr_time = max(curr_time, arrival);
		curr_time += dur;
	}

	cout << curr_time << endl;
}