#include <iostream>
using namespace std;

// intersect function to find intersect between 2 "lines" of [a, b] and [c, d]
int inter(int a, int b, int c, int d) {
    int low = max(a, c); // lower bound
    int up = min(b, d);  // upper bound
    return max(0, up - low + 1);
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int low = 5, high = 49, power = 1, out = 0;

		while (power < 100000000) {
			power *= 10;
			low += 4 * power;
			high = 5 * power - 1;
			out += inter(low, high, 2, N);
		}
		
		cout << out << endl;
	}
}