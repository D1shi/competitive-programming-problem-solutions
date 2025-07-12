#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S; sort(S.begin(), S.end());
    vector<string> strings;
    
    do strings.push_back(S);
    while (next_permutation(S.begin(), S.end()));

    cout << strings.size() << endl;
    for (const string& s : strings) cout << s << endl;
}