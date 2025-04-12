#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> arr (N);
    map<int, int> freq;
    for (auto& n : arr) {
        cin >> n;
        if (freq.count(n)) freq[n]++;
        else freq[n] = 1;
    }

    int reqFound = 0;
    for (int mex = 0; mex <= N; mex++) {
        cout << max(mex - reqFound, freq[mex]) << endl;
        reqFound += (freq[mex] > 0);
    }
}