#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

ll n;
ll f[fmax];
ll g[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  f[1] = 4;
  for(ll i = 2; i <= n; i++){
    if(i % 2 != 0)
      f[i] = (f[i - 1] + 1 + i) % MOD;
    else 
      f[i] = (f[i - 1] + 2 + 4 * i) % MOD;
  }
  
  g[1] = f[1];
  for(ll i = 2; i <= n; i++)
    g[i] = (g[i - 1] + f[i]) % MOD;
  
  cout << g[n];
    
  return 0;
}
