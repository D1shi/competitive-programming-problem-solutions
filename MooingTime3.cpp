#include <bits/stdc++.h>
using namespace std;

typedef long long int;

int main() {
    int N, T; string S; cin >> N >> T >> S;

    while (T--) {
        int L, U, out = -1; // L & U are min lower and max upper
        cin >> L >> U; L--;

        for (int mid = L + 1; mid < U - 1; mid++) {
            int lower = L, upper = U - 1;

            // try to stay as close to edges as possible when increasing bounds
            while (lower < mid && S[mid] == S[lower]) lower++;
            while (upper > mid && S[mid] != S[upper]) upper--;
            
            // check constraints & update if it fits
            if (S[mid] == S[lower] || S[mid] != S[upper]) continue;
            out = max((mid - lower) * (upper - mid), out);
        }
        
        if (out == 0) out = -1;
        cout << out << endl;
    }
}