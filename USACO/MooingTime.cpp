#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, F; cin >> N >> F;
	string S; cin >> S;
	set<string> out;
	// for every moo in m o o form

	for (char m = 'a'; m <= 'z'; m++) {
		for (char o = 'a'; o <= 'z'; o++) {
			if (m == o) continue;
			int count = 0;

			for (int i = 0; i < N - 2; i++) {
				if (S[i] == m && S[i + 1] == S[i + 2] && S[i + 2] == o) count++;
			}

			if (count == F - 1) {
				int i = 0;
				while (i < N and count < F) {
					if (S[i] == m && S[i + 1] == S[i + 2] && S[i + 2] == o) i += 3;
					else if (S[i - 2] == m && S[i - 1] == o) count++;
					else if (S[i - 1] == m && S[i + 1] == o) count++;
					else if (S[i + 1] == o && S[i + 2] == o) count++;
					else i++;
				}
			}

            string s = "";
            s = s + m + o + o;
			if (count >= F) out.insert(s);
		}
	}
	
	cout << out.size() << endl;
	for (auto moo : out) cout << moo << endl;
}

