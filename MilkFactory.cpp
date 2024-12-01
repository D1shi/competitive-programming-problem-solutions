#include <bits/stdc++.h>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	int connections[N] = {0};

	for (int _  = 0; _ < N - 1; _++) {
		int n1, n2;
		cin >> n1 >> n2;
		connections[--n1]++;
	}

	int out = -1;
	for (int i = 0; i < N - 1; i++) {
		if (connections[i] == 0) {
			if (out == -1) out = i;
			else {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	if (out == -1) {
		cout << out << endl;
		return 0;
	}

	cout << out + 1 << endl;
}