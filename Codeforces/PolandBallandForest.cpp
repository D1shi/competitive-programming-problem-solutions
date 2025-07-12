#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<unordered_set<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (const int& other : adj[node]) if (!visited[other]) dfs(other);
}

int main() {
    int N, out = 0; cin >> N;

    adj = vector<unordered_set<int>> (N);
    visited = vector<bool> (N, false);
    for (size_t i = 1; i < N; ++i) {
        int parent; cin >> parent; parent--;
        adj[i].insert(parent);
        adj[parent].insert(i);
    }

    for (size_t i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            ++out;
        }
    }

    cout << out;
}