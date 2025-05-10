#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    vector<string> sequences {"ABC", "BABC", "CCAABB"};
    vector<int> scores (3, 0);

    int N; cin >> N;
    string S; cin >> S;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 3; j++) {
            const string seq = sequences[j];
            if (S[i] == seq[i % seq.size()]) scores[j]++;
        }
    }

    int biggestScore = -1;
    for (const int& n : scores) biggestScore = max(n, biggestScore);
    cout << biggestScore << endl;

    if (scores[0] == biggestScore) cout << "Adrian" << endl;
    if (scores[1] == biggestScore) cout << "Bruno" << endl;
    if (scores[2] == biggestScore) cout << "Goran" << endl;
}