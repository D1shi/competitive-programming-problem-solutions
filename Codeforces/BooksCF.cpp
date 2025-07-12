#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N, T; cin >> N >> T;

    vector<int> books (N);
    for (int& b : books) cin >> b;

    size_t l = 0, r = 0, curr = 0, out = 0;
    while (l < N && r < N) {
        while (r < N) {
			curr += books[r++];
			if (curr > T) { curr -= books[--r]; break; }
		}

		out = max(out, r - l);
		curr -= books[l++];
    }

    cout << out;
}