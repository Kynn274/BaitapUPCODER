#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

// ĐỀ THI PHÂN TÍCH THIẾT KẾ GIẢI THUẬT 2018 - 2019

ll n;
ll a[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll ans(0);
  cin >> n;
  for(ll i = 0; i < n; i++)
    cin >> a[i];
    
  for(ll i = 0; i < n; i++){
    f[i] = max(a[i], f[i]);
    for(ll j = i + 2; j < n; j++){
      f[j] = max(f[i] + a[j], f[j]);
      ans = max(ans, f[j]);
    }
  }

  cout << ans;
  
  return 0;
}
