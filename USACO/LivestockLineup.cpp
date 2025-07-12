#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

const vector<string> COWS = {"Beatrice", "Belinda", "Bella",
    "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main() {
  map<string, int> COWID;
	for (int i = 0; i < COWS.size(); i++) COWID[COWS[i]] = i;
    
  int R; cin >> R;
	vector<vector<int>> neighbors(COWS.size());
	for (int r = 0; r < R; r++) {
		string cow1;
		string cow2;
		string trash;
		cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

		neighbors[COWID[cow1]].push_back(COWID[cow1]);
		neighbors[COWID[cow1]].push_back(COWID[cow1]);
	}
}