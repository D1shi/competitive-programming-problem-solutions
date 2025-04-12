#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int N, Q; cin >> N >> Q;
	int A[2], B[2]; 
	cin >> A[0] >> A[1] >> B[0] >> B[1];

	vector<int> cows(N);
	for (int i = 0; i < N; i++) cows[i] = i + 1;

	vector<vector<int>> seen;
	set<vector<int>> seenSet;

	while (!seenSet.count(cows)) {
		seen.push_back(cows); seenSet.insert(cows);
		reverse(cows.begin() + A[0] - 1, cows.begin() + A[1]);
		reverse(cows.begin() + B[0] - 1, cows.begin() + B[1]);
	}

	cows = seen[Q % seen.size()];
	
	for (int cow : cows) cout << cow << endl;
}