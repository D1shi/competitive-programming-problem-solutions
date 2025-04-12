#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N; ll out = 0; cin >> N;
    vector<int> arr (N + 2), pref (N + 2), cnt (1000005, 0);

    for (size_t i = 1; i <= N; i++) cin >> arr[i];
    
    for (size_t i = 1; i <= N; i++) {
        pref[i] = pref[i - 1];
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 1) pref[i]++;
    }

    cnt = vector<int> (1000005, 0);
    for (size_t i = N; i >= 1; i--) {
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 2) out += pref[i - 1];
    }
    
    for (size_t i = 1; i <= N; i++) if (cnt[i] >= 3) out--;
    cout << out;
}