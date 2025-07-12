#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

    string S; int out = 0; cin >> S;
    set<char> inside;

	for (const auto& c : S) {
		if (inside.count(c)) { // if entered field
			inside.remove(c);
			out += inside.size();
		} else { // if entering field
			inside.insert(c);
		}
	}
	
	cout << out;
}