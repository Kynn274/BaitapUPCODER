#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int _n, tmp;
  vector<int> s;
  for(int i = 0; i < n; i++){
    cin >> _n;
    for(int j = 0; j < _n; j++){
      cin >> tmp;
      s.push_back(tmp);
    }
    
    for(int j = 0; j < _n - 1; j++)
      for(int t = j + 1; t < _n; t++)
        if(s[t] < s[j]) swap(s[t], s[j]);
    
    tmp = 1e9;
    for(int j = 1; j < _n; j++)
      tmp = min(tmp, abs(s[j] - s[j - 1]));
    cout << tmp << endl;
    s.clear();
  }
}
