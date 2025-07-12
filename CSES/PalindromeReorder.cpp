#include <bits/stdc++.h>
using namespace std;

int main() {
    string inp; cin >> inp;

    map<char, int> freq;
    for (char c : inp) freq[c]++;

    int odd = count_if(freq.begin(), freq.end(), [](const auto& p) { return p.second % 2; });

    if ((!(inp.size() % 2) && odd != 0) || (inp.size() % 2 && odd != 1)) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    string half = "", mid = "";
    for (auto& [c, cnt] : freq) {
        if (cnt % 2) mid = c;
        half += string(cnt / 2, c);
    }

    string rev = half;
    reverse(rev.begin(), rev.end());
    cout << half + mid + rev;
}
