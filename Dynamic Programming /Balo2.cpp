#include <bits/stdc++.h>
#define fmax 102
using namespace std;

long long f[fmax][fmax];
long long a[fmax], c[fmax];
long long t1[fmax], t2[fmax];
long long n, w;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  long long ans = 0;
  long long vt;
  cin >> n >> w;
  for(long long i = 1; i <= n; i++)
    cin >> a[i] >> c[i];
  
  for(long long i = 0; i <= w; i++)
    f[0][i] = 0;
    
  for(long long i = 1; i <= n; i++){
    f[i][0] = 0;
    for(long long j = 1; j <= w; j++){
      if(j >= a[i])
        if(f[i - 1][j - a[i]] + c[i] > f[i - 1][j]){
          f[i][j] = f[i - 1][j - a[i]] + c[i];
          t1[j] = i;
          t2[j] = j - a[i];
        }
      f[i][j] = max(f[i][j], f[i - 1][j]);
      if(ans < f[i][j]){
        ans = f[i][j];
        vt = j;
      }
    }
  }
  
  cout << ans << endl;
  bool item[n];
  while(vt != 0){
    item[t1[vt]] = 1;
    vt = t2[vt];
  }
  
  for(long long i = 1; i <= n; i++)
    item[i] == 1? cout << 1 << ' ' : cout << 0 << ' ';

  return 0;
}
