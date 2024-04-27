#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for(long long i = 0; i < n; i++) cin >> v[i];
  
  long long _max1(-1e9);
  long long _max2(-1e9);
  long long _min1(1e9);
  long long _min2(1e9);
  long long vtmax;
  long long vtmin;
  
  for(long long i = 0; i < n; i++){
    if(v[i] > _max1){
      _max1 = v[i];
      vtmax = i;
    }
    if(v[i] < _min1){
      _min1 = v[i];
      vtmin = i;
    }
  }
  for(long long i = 0; i < n; i++){
    if(i != vtmax && v[i] > _max2) _max2 = v[i];
    if(i != vtmin && v[i] < _min2) _min2 = v[i];
  }
  
  cout << max(abs(_max2 + _max1), abs(_min1 + _min2));
  return 0;
}
