#include <bits/stdc++.h>
#define fmax 102
#define MOD 1000000007
using namespace std;

// TÍNH TỔ HỢP

long long t;
long long f[fmax][fmax];

long long combine(long long n, long long k){
  if(n == k || k == 0) return 1;
  if(n < k) return 0;
  if(f[n][k] != -1) return f[n][k];
  f[n][k] = combine(n - 1, k - 1) + combine(n - 1, k);
  return f[n][k];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  memset(f, -1, sizeof f);
  long long n, k;
  
  cin >> t;
  while(t--){
    cin >> n >> k;
    cout << combine(n, k) << endl;
  }
  
  return 0;
}
