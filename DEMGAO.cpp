#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long a, b, k;
  cin >> a >> b >> k;
  
  if(k > b){
    cout << 0;
    return 0;
  }
  
  long long iC = 1;
  long long _max = b / k;
  long long _min;
  if(max(a, k) % k == 0) _min = max(a, k) / k;
  else _min = max(a, k) / k + 1;
  
  cout << _max - _min + 1;
  
  return 0;
}
