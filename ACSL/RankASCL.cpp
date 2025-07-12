#include <bits/stdc++.h>
using namespace std;

int N, orgin;
vector<vector<int>> adj;
vector<bool> cyclic, visited;

void dfs(int n) {
    visited[n] = true;
    if (n == orgin) {
        cyclic[n] = true;
        return;
    }
    
    for (const auto& other : adj[n]) if (!visited[other]) dfs(other);
}

int main() {
    int K, out = 0; cin >> N >> K;
    adj = vector<vector<int>> (N);
    visited = vector<bool> (N, false);
    cyclic = vector<bool> (N, false);

    while (K--) {
        int a, b, sA, sB; cin >> a >> b >> sA >> sB; a--; b--;
        if (sA > sB) adj[b].push_back(a);
        else adj[a].push_back(b);
    }

    for (int i = 0; i < N; i++) {
		orgin = i;
		visited = vector<bool> (N, false);
		for (int other : adj[i]) dfs(other);
	}

    for (const auto& n : cyclic) out += n;
    cout << out;
}