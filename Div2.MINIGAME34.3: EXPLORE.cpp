#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge (vector<long long> a1, vector<long long> a2, vector<long long> & a){
  long long m = a1.size(), n = a2.size();
  long long i = 0, j = 0;
  a.clear();
  
  while(i < m && j < n)
    if(abs(a1[i]) < abs(a2[j])) a.push_back(a1[i++]);
    else a.push_back(a2[j++]);
  while(i < m) a.push_back(a1[i++]);
  while(j < n) a.push_back(a2[j++]);
}

void merge_sort(vector<long long> & a){
  long long s = 0;
  long long e = a.size();
  long long m = (s + e)/2;
  
  if(m != s){
    vector<long long> a1;
    vector<long long> a2;
    for(long long i = 0; i < m; i++) a1.push_back(a[i]);
    for(long long i = m; i < e; i++) a2.push_back(a[i]);
    
    merge_sort(a1);
    merge_sort(a2);
    merge(a1, a2, a);
  }
}

int main() {
  long long n, t;
  cin >> t >> n;
  vector<long long> x(n);
  for(long long i = 0; i < n; i++) cin >> x[i];
  
  merge_sort(x);
  
  long long iC = 0;
  long long  i = 0;
  long long _x = 0;
  while(t - abs(x[i] - _x) > 0){
    t -= abs(x[i] - _x);
    _x = x[i];
    iC++;
    i++;
  }
  
  cout << iC;
  return 0;
}
