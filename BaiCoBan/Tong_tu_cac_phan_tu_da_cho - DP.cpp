#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#define fmax 1000006
using namespace std;

// SỐ CÁCH TÍNH TỔNG TỪ CÁC PHẦN TỬ ĐÃ CHO

long long n, S;
long long a[fmax];
long long f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> S;
  for(long long i = 1; i <= n; i++) 
    cin >> a[i];
  
  f[0] = 1;
  for(long long i = 1; i <= S; i++)
    for(long long j = 1; j <= n; j++)
      if(a[j] <= i)
        f[i] = f[i] + f[i - a[j]];
  
  cout << f[S];
  return 0;
}
