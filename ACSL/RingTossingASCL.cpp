#include <bits/stdc++.h>
using namespace std;


vector<int> scoreTosses(vector<string> pTosses) {
    vector<int> output;

    for (auto tosses : pTosses) {
        int score = 0;
        for (auto toss : tosses) {
            switch (toss) {
                case 'A': case 'R': 
                    score++; 
                    break;

                case 'O': case 'G': 
                    score += 3; 
                    break;
                
                default:
                    score += 6;
                    break;
            }
        }
        output.push_back(score);
    }

    return output;
}


int main() {
    vector<string> pTosses(2);
    for (auto &tosses : pTosses) cin >> tosses;

    for (int s : scoreTosses(pTosses)) cout << s << " ";

    return 0;
}
