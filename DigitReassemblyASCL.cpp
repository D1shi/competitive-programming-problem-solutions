#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long nums[5], N, out;
    for (long long& n : nums) cin >> n;

    // CASE 1
    N = nums[0], out = 0;
    while (N > 0) {
        out++;
        N /= 10;
    }

    cout << out << endl;

    // CASE 2
    N = nums[1], out = 0;
    while (N > 0) {
        out += N % 10;
        N /= 10;
    }

    cout << out << endl;

    // CASE 3
    N = nums[2] / 10, out = 0;
    while (N > 0) {
        out += N % 10;
        N /= 100;
    }
    
    cout << out << endl;

    // CASE 4
    N = nums[3], out = 0;
    string nStr = to_string(N);
    for (auto c : nStr) if (c == '4') out++;
    
    cout << out << endl;
    
    // CASE 5
    N = nums[4];
    nStr = to_string(N);
    reverse(nStr.begin(), nStr.end());
    
    cout << nStr[(nStr.length() / 2) - 1] << endl;
}