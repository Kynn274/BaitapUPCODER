#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n, k;
  cin >> k >> n;
  
  vector<int> a(n);
  vector<vector<int> > result(k);
  vector<int> tong(k, 0);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j <n; j++)
      if(a[j] > a[i]) swap(a[i], a[j]);
  
  int point(0);
  int tmp(1e9);
  
  result[0].push_back(a[0]);
  tong[0] += a[0];
  for(int i = 1; i < n; i++){
    for(int j = 0; j < k; j++){
      if(tong[j] < tmp){
        tmp = tong[j];
        point = j;
      }
    }
    result[point].push_back(a[i]);
    tong[point] += a[i];
    tmp = 1e9;
  }
  
  for(int i = 0; i < k; i++){
    cout << i + 1 << '|' << tong[i] << '|';
    for(int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << ' ';
    cout << endl;
  }
  
  return 0;
}
