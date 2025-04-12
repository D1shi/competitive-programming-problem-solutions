#include <bits/stdc++.h>
using namespace std;

bool findPath(int farm, int end, vector<int>& path, vector<vector<int>>& tree, vector<bool>& visited) {
    path.push_back(farm);
    visited[farm] = true;
    
    if (farm == end) return true; 

    for (auto f : tree[farm]) {
        if (!visited[f]) {
            if (findPath(f, end, path, tree, visited)) return true;
        }
    }

    path.pop_back();
    return false;
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M;
    string types;
    cin >> N >> M >> types;

    vector<vector<int>> paths(N);

    for (int i = 0; i < N - 1; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        f1--, f2--;
        paths[f1].push_back(f2);
        paths[f2].push_back(f1);
    }
    
    for (int i = 0; i < M; i++) {
        int s, e;
        char type;
        cin >> s >> e >> type;
        s--, e--;

        vector<int> path;
        vector<bool> visited(N, false);
        findPath(s, e, path, paths, visited);

        bool found = false;
        for (const auto& f : path) {
            if (types[f] == type) {
                found = true;
                break;
            }
        }

        cout << found;
    }
    
    cout << endl;
}
