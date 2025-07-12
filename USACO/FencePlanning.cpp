#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y, i;
    vector<int> connected;
};

vector<Cow> cows;
vector<vector<int>> networks;
vector<bool> visited;

void dfs(int i) {
    networks.back().push_back(i);
    visited[i] = true;
    for (const auto& cow : cows[i].connected) if (!visited[cow]) dfs(cow);
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    int N, M; cin >> N >> M;
    vector<int> empty; 

    cows = vector<Cow>(N);
    visited = vector<bool>(N, false);
    for (size_t i = 0; i < N; i++) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].i = i; cows[i].connected = {};
    }

    for (size_t i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cows[a].connected.push_back(b);
        cows[b].connected.push_back(a);
    }
    
    while (accumulate(visited.begin(), visited.end(), 0) != N) {
        networks.push_back(empty);
        size_t i = 0;
        for (; i < N; i++) if (!visited[i]) break;
        dfs(i);
    }

    int out = INT_MAX;
	for (vector<int> net : networks) {
		int min_x = INT_MAX;
		int max_x = 0;
		int min_y = INT_MAX;
		int max_y = 0;
		for (int i : net) {
			min_x = min(min_x, cows[i].x);
			max_x = max(max_x, cows[i].x);
			min_y = min(min_y, cows[i].y);
			max_y = max(max_y, cows[i].y);
		}
		out = min(out, 2 * (max_x - min_x) + 2 * (max_y - min_y));
	}
	
    freopen("fenceplan.out", "w", stdout);
	cout << out;
}