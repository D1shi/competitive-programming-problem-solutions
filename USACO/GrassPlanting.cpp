#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int grass[N] = {0};

	for (int i = 0; i < N - 1; i++) {
		int f1, f2; cin >> f1 >> f2;
		// -- to 0 index
		f1--; grass[f1]++;
		f2--; grass[f2]++;
	}

	int out = 0;
	for (auto f : grass) out = max(out, f);

	cout << out + 1 << endl;
}