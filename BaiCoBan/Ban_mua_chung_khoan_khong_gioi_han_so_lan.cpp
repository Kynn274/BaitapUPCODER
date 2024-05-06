#include <bits/stdc++.h>
#define fmax 1003
using namespace std;

long long n, fee;
long long a[fmax];

long long stock(){
  long long _min(1e9);
  long long _max(-1e9);
  long long tong(0);
  long long tien(0);
  for(long long i = 0; i < n; i++){
    _min = min(_min, a[i]);
    _max = max(_max, a[i]);
    if(_max > a[i + 1] && _max - _min > fee){
      tien = _max - _min - fee;
      _max = a[i + 1];
      _min = a[i + 1];
      tong += tien;
    }
  }
  
  return tong;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> fee;
  for(long long i = 0; i < n; i++) cin >> a[i];
  
  cout << stock();
  return 0;
}
