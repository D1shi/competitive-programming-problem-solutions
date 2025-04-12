#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, sum = 0; cin >> N;

        vector<int> sleeps (N);
        for (auto& s : sleeps) {
            cin >> s;
            sum += s;
        }

        for (int hours = 0; hours <= sum; hours++) {
            if (hours != 0 && sum % hours != 0) continue;

            int curr = 0;
            bool good = true;
            for (auto s : sleeps) {
                curr += s;
                if (curr > hours) { good = false; break; }
                else if (curr == hours) curr = 0;
            }

            if (good) {
                if (hours == 0) cout << 0;
                else cout << N - sum / hours;

                cout << endl; break;
            }
        } 
    }
    
}