#include <bits/stdc++.h>
using namespace std;

struct Event { 
    int time, cow; 
    bool starting;
};

bool operator< (const Event& e1, const Event& e2) { return e1.time < e2.time; }


int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

    int N, T = 0; cin >> N;

    vector<Event> events; 
    
    int t; 
    for (size_t i = 0; i < N; i++) {
        cin >> t; events.push_back({t, i, true});
        cin >> t; events.push_back({t, i, false});
    }

    sort(events.begin(), events.end());
    
    int out = 0, prevT = 0;
    set<int> working;
    vector<int> cover(N, 0);

    for (Event e : events) {
        if (!working.empty()) out += e.time - prevT;

        if (working.size() == 1) cover[*working.begin()] += e.time - prevT;

        if (e.starting) working.insert(e.cow);
        else working.erase(e.cow);
        
        prevT = e.time;
    }

    cout << out - *min_element(cover.begin(), cover.end());
}