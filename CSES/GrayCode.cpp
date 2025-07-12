#include <bits/stdc++.h>
using namespace std;

void graycode(int n, vector<string>& out) {
    for (int i = 0; i < (1 << n); i++) {
        int gray = i ^ (i >> 1);
        string code = "";
        for (int j = n - 1; j >= 0; j--) code += (gray & (1 << j)) ? '1' : '0';
        out.push_back(code);
    }
}

int main() {
    size_t n; cin >> n;
    vector<string> out; graycode(n, out);
    for (string code : out) cout << code << endl;
    return 0;
}