#include <iostream>
#include <vector>
#include <cmath>
#define num 1000000007
using namespace std;


int main() {
  long long n;
  cin >> n;

  vector<long long> a;
  for(long long i = 0; i <= n; i++) a.push_back(0);
  a[0] = 1;
  
  long long i = 1;
  while (i <= n){
    long long j = i;
    while (j <= n){
      a[j] += (a[j - i] % num);
      j++;
    }
    i++;
  }
  
  cout << a[n];
  return 0;
}
