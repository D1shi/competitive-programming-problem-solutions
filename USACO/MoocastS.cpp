#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y, r, i;
};

vector<bool> visited;
vector<Cow> cows;

void dfs(Cow cow) {
    visited[cow.i] = true;

    for (const auto& other : cows) {
        int dist = pow(abs(cow.x - other.x), 2) + pow(abs(cow.y - other.y), 2);
        if (pow(cow.r, 2) >= dist && !visited[other.i]) dfs(other); 
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    int N, out = 0; cin >> N;
    visited = vector<bool> (N, false);
    cows = vector<Cow> (N);
    
    for (size_t i = 0; i < N; i++) {
        cin >> cows[i].x >> cows[i].y >> cows[i].r;
        cows[i].i = i;
    }

    for (const auto& cow : cows) {
        dfs(cow); int curr = 0;
        for (const auto& v : visited) curr += v;
        out = max(curr, out);

        visited = vector<bool> (N, false);
    }

    freopen("moocast.out", "w", stdout);
    cout << out;
}