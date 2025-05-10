#include <iostream>
#include <vector>
using namespace std;

int main() {
  int out = 0, N, i;
  cin >> N;
  int people[N];
  for(int& e : people) cin >> e;

  for(int e : people) {
    int depth = 0;
    
    while(e != -1) {
      e = people[e - 1];
      depth++;
    }
    out = max(out, depth);
  }
  
  cout << out + 1 << endl;

  return 0;
}