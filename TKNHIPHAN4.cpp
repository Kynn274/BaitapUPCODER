#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long _min = 1e9;
long long _max = -1e9;

void binary_search(vector<long long> &v, long long s, long long e){
  long long m = (s + e) / 2;
  
  if(m != s ){
    binary_search(v, s, m);
    binary_search(v, m, e);
  }else{
    _min = min(_min, v[m]);
    _max = max(_max, v[m]);
  }
}

int main() {
  long long n, s ,e;
  cin >> n >> s >> e;
  
  vector<long long> v(n);
  vector<long long> v1;
  for(long long i = 0    ; i < n; i++) cin >> v[i];
  for(long long i = s - 1; i < e; i++) v1.push_back(v[i]);
  
  binary_search(v1, 0, e - s + 1);
  cout << _min << ' ' << _max;
  return 0;
}
