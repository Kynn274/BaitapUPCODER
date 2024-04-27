#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
void xuly (int j, vector<int> v){
  if(v.size() == k){
    for(int i = 0; i < v.size(); i++) cout << v[i] << ' '; 
    cout << endl;
  }else{
    for(int i = 1; i <= n; i++){
      if(i > j){
        v.push_back(i);
        xuly(i, v);
        v.pop_back();
      }
    }
  }
}

int main() {
  cin >> n >> k;
  
  string s;
  vector<int> v;
  xuly(0, v);
  
  return 0;
}
