#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int start, end, buckets;
};

int main() {
    freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

    int N; cin >> N;

    vector<Cow> cows (N);
    set<int> times;

    for (Cow& cow : cows) {
        cin >> cow.start >> cow.end >> cow.buckets;
        times.insert({cow.start, cow.end});
    }

    int out = -1;
    for (const int& t : times) {
        int curr = 0;
        for (Cow& cow : cows) if (cow.start <= t && cow.end >= t) curr += cow.buckets;
        out = max(curr, out);
    }

    cout << out;
}