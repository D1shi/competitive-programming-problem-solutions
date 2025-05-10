#include <bits/stdc++.h>
using namespace std;

// returns digit sum and -1 if invalid for base
int check(int N, int B) {
    int out = 0; digits.clear();

    while (N > 0) {
        if (N % 10 >= B) return -1;
        out += N % 10;
        N /= 10;
    }

    return out;
}

int main() {
    int N, B, S; cin >> N >> B >> S;
    int n = s, out = 0, i = 0;

    while (i < N) {
        int sum = check(n, B); 
        cout << sum << " " << n << " " << i << " " << out << endl;
        n++;
        if (sum == -1) continue;

        out += sum; i++;
        cout << sum << " " << n << " " << i << " " << out << endl;
    }

    cout << out;
}