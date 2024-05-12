#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

// TỔNG TẤT CẢ CÁC TẬP CON

ll n, S;
ll a[fmax];
ll f[fmax];
ll g[fmax];
bool _f[fmax];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    S += a[i];
  }
  
  for(ll i = 0; i < n; i++){
    for(ll j = a[i]; j <= S; j++)
        f[j] = max(g[j], g[j - a[i]] + a[i]);
    for(ll j = 1; j <= S; j++)
      g[j] = f[j];
  }
    
  for(ll i = 1; i <= S; i++)
    _f[f[i]] = 1;
  
  ll iC(0);
  for(ll i = 1; i <= S; i++)
    if(_f[i] == 1) 
      iC ++;
  
  cout << iC << '\n';
  for(ll i = 1; i <= S; i++)
    if(_f[i] == 1) 
      cout << i << ' ';
  return 0;
}
