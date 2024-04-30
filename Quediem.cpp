#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  if(n > 4){
    long long x = sqrt(n/2);
    2 * x * (x + 1) > n ? x-- : x;
    
    long long d = n - 2 * x * (x + 1);
    long long r = x * x;
    d >= 3 ? r += 1 : r;
    d -= 3;
    long long i = 1;
    while(d >= 2 && i < x){
      r ++;
      d -= 2;
      i++;
    }
    d >= 3 ? r += 1 : r;
    d -= 3;
    i  = 0;
    while(d >= 2 && i < x){
      r ++;
      d -= 2;
      i++;
    }
    
    cout << r;
  }else{
    if(n == 4) cout << 1;
    else cout << 0;
  }
  return 0;
}
