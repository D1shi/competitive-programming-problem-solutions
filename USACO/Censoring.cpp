#include <iostream>
using namespace std;

int main() {
	string S, bad; cin >> S >> bad;
	size_t pos = S.find(bad);

    while (pos != string::npos) {
        S.replace(pos, bad.size(), "");
		pos = S.find(bad);
    }

	cout << S << endl;
}
