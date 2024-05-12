#include <bits/stdc++.h>
#define fmax 3003
#define MOD 1000000007
#define ll long long
using namespace std;

// CHUỖI ĐỐI XỨNG DÀI NHẤT

string a, b;
ll f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  ll m = a.size();
  ll n = b.size();
  ll ans (0);
  
  reverse(b.begin(), b.end());
  
  for(ll i = 1; i <= m; i++)
    for(ll j = 1; j <= n; j++){
      if(a[i - 1] == b[j - 1])
        f[i][j] = f[i - 1][j - 1] + 1;
      else 
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      ans = max(ans, f[i][j]);
    }
  
  cout << ans;
  

  return 0;
}
