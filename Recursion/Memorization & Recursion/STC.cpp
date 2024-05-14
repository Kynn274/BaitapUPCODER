#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

ll f[fmax];

// Max 202 

ll xuly(ll n, ll _min){
  ll tong(0);
  ll m = n / 2;
  f[n] = 0;
  if(n <= 2) return 0;
  if(_min >= m) return 1;
  for(ll i = _min; i <= m; i++){
    if(n - i > i)
      f[n] = (f[n] + (xuly(n - i, i + 1))) % MOD;
  }
  return f[n];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n;
  cin >> n;
  cout << xuly(n, 1) << '\n';
  for(ll i = 1; i <= n; i++)
    cout << i << ' ' << f[i] << '\n';
  return 0;
}
