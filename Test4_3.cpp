#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  int vt;
  int size(n);
  vector<long long> result;
  
  for(int i = 0; i < n; i++)  cin >> a[i];
  
  long long tmp(1e9);
  while(size > 1){
    for(int i = 1; i < size; i++)
      if(a[i - 1] + a[i] < tmp){
        tmp = a[i - 1] + a[i];
        vt = i;
      }
    
    result.push_back(tmp);
    
    a[vt - 1] = tmp;
    for(int i = vt; i < size - 1; i++)
      a[i] = a[i + 1];
    
    size--;
    tmp = 1e9;
  }
  
  long long tong(0);
  for(int i = 0; i < result.size(); i++) tong += result[i];
  cout << tong;
}
