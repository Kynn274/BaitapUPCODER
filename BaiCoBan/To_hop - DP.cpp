#include <cstdio>
#include <iostream>
#define nmax 1000006
#define fmax 102
#define MOD 1000000007
using namespace std;

// TÍNH TỔ HỢP

long long t;
long long n[nmax];
long long k[nmax];
long long f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long _max(-1e9);
  
  cin >> t;
  for(long long i = 1; i <= t; i++){
    cin >> n[i] >> k[i];
    _max = max(_max, n[i]);
  }
  
  for(long long i = 0; i <= _max; i++){            // Tổ hợp theo mô hình Pascal
    f[i][0] = f[i][i] = 1;
    for(long long j = 1; j < i; j++)
      f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
  }
  
  for(long long i = 1; i <= t; i++)
    cout << f[n[i]][k[i]] << endl;
  
  return 0;
}
