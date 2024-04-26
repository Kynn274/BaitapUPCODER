#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<int> s(6,0);
  vector<int> v(6,0);
  v[0] = 500000;
  v[1] = 200000;
  v[2] = 100000;
  v[3] = 50000;
  v[4] = 20000;
  v[5] = 10000;
  
  int tong = 0;
  for(int i = 0; i < 6; i++)
    if(n >= v[i]){
      tong += n / v[i];
      s[i] = n / v[i];
      n %= v[i];
    }
  
  cout << tong << endl;
  for(int i = 0; i < 6; i++)
    if(s[i] != 0)
      cout << s[i] << ' ' << v[i] / 1000 << ".000" << endl;
  return 0;
}
