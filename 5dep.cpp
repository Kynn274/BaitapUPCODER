#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool snt(long long n){
  if(n < 2) return false;
  if(n == 2 || n == 3 || n == 5) return true;
  for(int i = 2; i <= sqrt(n); i++)
    if(n % i == 0) return false;
  return true;
}

int main() {
  long long n;
  cin >> n;

  long long k;
  k = sqrt(n);
  k = sqrt(k);

  long long dem = 0;
  for(long long i = 2; i <= k; i++)
    if(snt(i)) dem++;
  cout << dem;
  
  return 0;
}
