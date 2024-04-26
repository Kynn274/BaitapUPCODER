#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<long long> a1, vector<long long> a2, vector<long long> &a){
  long long m = a1.size();
  long long n = a2.size();
  long long i = 0, j = 0;
  
  a.clear();
  while(i < m && j < n){
    if(a1[i] < a2[j]) a.push_back(a1[i++]);
    else a.push_back(a2[j++]);
  }
  
  while(i < m) a.push_back(a1[i++]);
  while(j < n) a.push_back(a2[j++]);
}

void merge_sort(vector<long long> & a){
  long long s = 0;
  long long e = a.size();
  long long m = (s + e) / 2;
  
  if(m != s){
    vector<long long> a1;
    vector<long long> a2;
    
    for(int i = 0; i < m; i++) a1.push_back(a[i]);
    for(int i = m; i < e; i++) a2.push_back(a[i]);
    
    merge_sort(a1);
    merge_sort(a2);
    merge(a1, a2, a);
  }
}

int main() {
  int m;
  int n;
  long long tmp;
  vector<long long> v;
  vector<long long> cho;
  
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> n;
    for(int j = 0; j < n; j++){
      cin >> tmp;
      v.push_back(tmp);
      cho.push_back(tmp * 2);
    }
    
    merge_sort(v);
    merge_sort(cho);
    
    long long dem = 0;
    for(int j = 0; j < n; j++)
      if(v[j] <= cho[j]){
        for(int t = j + 1; t < n; t++)
          cho[t] -= v[j];
        dem++;
      }
    cout << "Case #" << i + 1 << ": " << dem << endl;
    v.clear();
    cho.clear();
  }
  
  
  return 0;
}
