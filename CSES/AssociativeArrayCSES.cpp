#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    map<int, int> nums;

    while (Q--) {
        int command; cin >> command;
        if (command == 0) {
            int k, v; cin >> k >> v;
            nums[k] = v;
        } else if (command == 1) {
            int k; cin >> k;
            cout << nums[k];
            if (Q != 1) cout << endl;
        }
    }
}