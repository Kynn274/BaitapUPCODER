#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  long long _max = -1e9;
  vector<long long> v(n);
  for(long long i = 0; i < n; i++){
    cin >> v[i];
    _max = max (_max, v[i]);
  }
  
  vector<bool> v1(_max, 0);
  for(long long i = 0; i < n; i++)
    if(v1[v[i]] == 0){
      cout << v[i] << ' ';
      v1[v[i]] = 1;
    }
    
  return 0;
}
