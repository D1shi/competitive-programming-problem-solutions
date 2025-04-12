#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> combi (501);
    for (size_t i = 0; i < 501; i++) combi[i] = ((i + 1) * (i + 2)) / 2;

    int T; cin >> T;
    while (T--) {
        int N, x = 0, y = 0; cin >> N;
        vector<pair<int, int>> points;

        for (size_t i = 500; i >= 0; i--) {
            while (combi[i] <= N) { 
                N -= combi[i];
            
                for (size_t j = 0; j <= i + 1; j++) {
                    points.push_back({x, y});
                    x++;
                }

                x++; y++;
            }
            
            if (N == 0) break;
        }
       
        cout << points.size() << endl;
        for (const auto& [x, y] : points) cout << x << " " << y << endl;
    }
}