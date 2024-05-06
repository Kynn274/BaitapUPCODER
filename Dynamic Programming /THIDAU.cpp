#include <bits/stdc++.h>
#define fmax 1003
using namespace std;

long long n, k;
long long f[fmax];
long long a[fmax];
long long b[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for(long long i = 1; i <= n; i++) cin >> a[i];
  memset(b, 0, sizeof b);
  for(long long i = 1; i <= n; i++) cin >> b[a[i]];
  
  long long last_day = a[n];
  long long ans = 0;
  memset(f, 0, sizeof f);
  
  for(long long i = 1; i <= n; i++){
    f[a[i]] = max(f[a[i]], b[a[i]]);
    for(long long j = a[i] + k; j <= last_day; j++){
      f[j] = max(f[j], f[a[i]] + b[j]);
    }
  }
  
  for(long long i = 1; i <= n; i++)
    ans = max(ans, f[a[i]]);
    
  cout << ans;
  return 0;
}
