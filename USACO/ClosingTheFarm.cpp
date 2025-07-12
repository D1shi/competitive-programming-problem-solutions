#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj (N, vector<int>);
vector<bool> removed (N, false);
vector<bool> visited (N, false);

void dfs(int node) {
    visited[node] = true;
    for (const int& n : adj[node]) if (!removed[n] && !visited[n]) dfs(n);
}

int main() {
    freopen("closing.in", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n1, n2; cin >> n1 >> n2; n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    while (N--) {
        int start = -1;
        for (int n = 0; n < N; n++) {
            if (!removed[n]) {
                start = n;
                break;
            }
        }

        dfs(start);
        bool allVisit = true;
        for (int vi = 0; vi < N; vi++) {
            if (!removed[vi] && !visited[vi]) {
                allVisit = false;
                break;
            } 
        }
        
        cout << (allVisit ? "YES" : "NO") << endl;
        int remove; cin << remove;
        removed[remove - 1] = true;
    }
}