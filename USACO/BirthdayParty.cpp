#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int N, M;

vector<vector<bool>> adj;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int to = 0; to < N; to++) {
		if (adj[v][to] && !visited[to]) { dfs(to); }
	}
}

void solve() {
    vector<pair<int, int>> edges;
    adj = vector<vector<bool>>(N, vector<bool> (N, false));

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
        edges.push_back(make_pair(u, v));
    }

    for (pair<int, int> x : edges) {
        adj[x.f][x.s] = false;
        adj[x.s][x.f] = false;
        visited = vector<bool> (N, false);
        dfs(0);

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                cout << "Yes" << endl;
                return;
            }
        }

        adj[x.f][x.s] = true;
        adj[x.s][x.f] = true;
    }

    cout << "No" << endl;
}

int main() {
    while (cin >> N >> M && (N || M)) solve();
}