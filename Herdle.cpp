#include <bits/stdc++.h>
using namespace std;

int main() {
    string correct = "", guess = "", add;

    for (size_t i = 0; i < 3; i++) { cin >> add; correct += add; }
    for (size_t i = 0; i < 3; i++) { cin >> add; guess += add; }
    
    int g = 0;
    vector<int> guessOcc (26, 0);
    vector<int> correctOcc (26, 0);

    for (size_t i = 0; i < 9; i++) {
        char cL = correct[i], gL = guess[i];

        if (cL == gL) g++;

        correctOcc[cL - 'A']++;
        guessOcc[gL - 'A']++;
    }
    
    int y = 0;
    for (char c = 0; c < 26; c++) y += min(correctOcc[c], guessOcc[c]);

    cout << g << endl << y - g;
}
