#include <bits/stdc++.h>
using namespace std;

struct Cow {
    vector<int> connections;
    char type;
    int component;
};

vector<bool> visited;
vector<Cow> cows;

void dfs(int cI, int comp) {
    visited[cI] = true;
    Cow& cow = cows[cI];
    cow.component = comp;

    for (const auto& other : cow.connections) {
        if (visited[other] || cow.type != cows[other].type) continue;
        dfs(other, comp);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M; string types;
    cin >> N >> M >> types;

    cows = vector<Cow> (N);
    visited = vector<bool> (N, false);

    for (size_t i = 0; i < N; ++i) cows[i].type = types[i];
    for (size_t i = 0; i < N - 1; ++i) {
        int f1, f2; cin >> f1 >> f2;
        cows[--f1].connections.push_back(--f2);
        cows[f2].connections.push_back(f1);
    }

    size_t curr = 0;
    for (size_t i = 0; i < N; i++) {
        if (visited[i]) continue;
        dfs(i, curr); curr++;
    }

    while (M--) {
        int s, e; char type; 
        cin >> s >> e >> type;
        Cow c1 = cows[--s], c2 = cows[--e];

        cout << ((c1.component == c2.component && c1.type != type) ? '0' : '1');
    }
}