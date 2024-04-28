#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int> a1, vector<int> a2, vector<int> & a){
  int m = a1.size();
  int n = a2.size();
  int i(0), j(0);
  a.clear();
  
  while(i < m && j < n)
    if(a1[i] < a2[j]) 
      a.push_back(a1[i++]);
    else
      a.push_back(a2[j++]);
      
  while(i < m) a.push_back(a1[i++]);
  while(j < n) a.push_back(a2[j++]);
}

void merge_sort(vector<int> & a){
  int s = 0;
  int e = a.size();
  int m = (s + e) / 2;
  
  if(m != s){
    vector<int> a1;
    vector<int> a2;
    for(int i = 0; i < m; i++) a1.push_back(a[i]);
    for(int i = m; i < e; i++) a2.push_back(a[i]);
    merge_sort(a1);
    merge_sort(a2);
    merge(a1, a2, a);
  }
}
int main() {
  vector<int> v;
  int n(0), tmp;
  
  while(cin >> tmp){
    v.push_back(tmp);
    n++;
  }
  
  merge_sort(v);
  
  if(n % 2 != 0){
    v.push_back(0);
    n++;
  }
  
  vector<int> Ky;
  vector<int> ChiGai;
  
  int i(0);
  while(i < n){
    ChiGai.push_back(v[i++]);
    Ky.push_back(v[i++]);
  }
  
  int len = n / 2;
  for(int i = 0; i < len; i++){
    cout << Ky[i]     << ' ';
    cout << ChiGai[i] << ' ';
  }
  return 0;
}
