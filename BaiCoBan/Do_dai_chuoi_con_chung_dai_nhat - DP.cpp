#include <bits/stdc++.h>
#define fmax 3003
#define MOD 1000000007
#define ll long long
using namespace std;

// ĐỘ DÀI CHUỖI CON CHUNG DÀI NHẤT

string a, b;
ll f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  
  ll ans(0);
  
  ll m = a.size();
  ll n = b.size();
  for(ll i = 0; i <= m; i++)
    for(ll j = 0; j <= n; j++){
      if(i == 0 || j == 0)
        f[i][j] = 0;
      else if(a[i - 1] == b[j - 1])
        f[i][j] = f[i - 1][j - 1] + 1;
      else 
        f[i][j] = max(f[i][j - 1], f[i - 1][j]);
      ans = max (ans, f[i][j]);
    }
  cout << ans;
  return 0;
}
