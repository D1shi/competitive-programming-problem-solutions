#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ifstream fin("pairup.in");
	ofstream fout("pairup.out");
	int N;
	vector<pii> V;
	fin >> N;
	for (int i = 0; i < N; i++) {
		int num_cows, milk_time;
		fin >> num_cows >> milk_time;
		V.push_back(pii(milk_time, num_cows));
	}
	sort(V.begin(), V.end());
	int M = 0, left = 0, right = N - 1;

	while (left <= right) {
		// the maximum amount of cows we can group together.
		int sub = min(V[left].second, V[right].second);
		if (left == right) sub /= 2;
		M = max(M, V[left].first + V[right].first);
		V[left].second -= sub;
		V[right].second -= sub;

		// once there are no more cows available in our
		// pair, we can increment/decrement the left/right
		// pointer(s).
		if (V[left].second == 0) left++;
		if (V[right].second == 0) right--;
	}
	fout << M << "\n";
}