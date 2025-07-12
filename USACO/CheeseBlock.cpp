#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q, out = 0; cin >> N >> Q;

	vector<vector<int>> xy (N, vector<int>(N, N));
	vector<vector<int>> yz (N, vector<int>(N, N));
	vector<vector<int>> xz (N, vector<int>(N, N));

	while (Q--) {
		int x, y, z; cin >> x >> y >> z;

		xy[x][y] -= 1;
		yz[y][z] -= 1;
		xz[x][z] -= 1;

		if (xy[x][y] == 0) out++;
		if (yz[y][z] == 0) out++;
		if (xz[x][z] == 0) out++;

		cout << out << endl;
	}
}