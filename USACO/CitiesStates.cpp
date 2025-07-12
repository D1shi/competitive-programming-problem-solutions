#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

    int N, out = 0; cin >> N;
    map<string, vector<string>> states;

    for (size_t i = 0; i < N; i++) {
        string city, state; cin >> city >> state;
        city = city.substr(0, 2);

        // add city to state
        if (states.count(state)) states[state].push_back(city);
        else states[state] = {city};
    }

    // add to output for each city
    for (auto [state, cities] : states) for (auto city : cities) if (states.count(city)) out += count(states[city].begin(), states[city].end(), state); 
    
    cout << out / 2;
}