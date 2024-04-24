#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  
  int i(0), p(1e9), cost(0), vt = 0;
  
  if(n - 1 <= k){
    cout << abs(v[n - 1] - v[0]);
    return 0;
  }
  
  while(i < n - 1){
    int j;
    for(j = i + 1; j <= i + k; j++){
      if(j >= n) break;
      if(v[vt] <= v[j] && v[j] <= v[n - 1] || v[vt] >= v[j] && v[j] >= v[n - 1]){
        p  = abs(v[j] - v[i]);
        vt = j;
      }else{
        if(vt == i){
          p  = abs(v[j] - v[i]);
          vt = j;
        }else{
          if(v[j] < min(v[vt], v[n - 1]))
            if(v[vt] != max(v[vt], v[j])){
              p  = min (p + abs(v[j] - v[vt]), abs(v[j] - v[i]));
              vt = j;
            }
          
            
          if(v[j] > max(v[vt], v[n - 1]))
            if(v[vt] != min(v[vt], v[j])){
              p  = min (p + abs(v[j] - v[vt]), abs(v[j] - v[i]));
              vt = j;
            }
        }
      }
    }
    cost += p;
    i = vt;
    p = 1e9;
  }
  
  cout << cost;
  
  return 0;
}
