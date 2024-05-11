#include <cstdio>
#include <iostream>
#define fmax 102
#define MOD 1000000007
using namespace std;

// ĐƯỜNG ĐI TRÊN LƯỚI

long long n;
char a[fmax][fmax];
long long f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(long long i = 1; i <= n; i++)
    for(long long j = 1; j <= n; j++)
      cin >> a[i][j];
      
  f[1][1] = 1;
  for(long long i = 2; i <= n; i++)
    a[1][i] == '*' ? f[1][i] = 0 : f[1][i] = f[1][i - 1] % MOD;
  
  for(long long i = 2; i <= n; i++)
    a[i][1] == '*' ? f[i][1] = 0 : f[i][1] = f[i - 1][1] % MOD;
    
  for(long long i = 2; i <= n; i++)
    for(long long j = 2; j <= n; j++)
      a[i][j] == '*' ? f[i][j] = 0 : f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;

  cout << f[n][n];
  return 0;
}
