#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> children;

void dfs(int node) {
    for (const int& other : adj[node]) {
        dfs(other);
        children[node] += 1 + children[other];
    }
}

int main() {
    int N; cin >> N;

    adj = vector<vector<int>> (N);
    children = vector<int> (N);
    for (size_t i = 1; i < N; ++i) {
        int parent; cin >> parent; parent--;
        adj[parent].push_back(i);
    }

    dfs(0);
    for (const int& c : children) cout << c << " ";
}