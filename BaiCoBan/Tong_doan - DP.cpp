#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

// TỔNG ĐOẠN

ll n, t;
ll a[fmax];
ll s[fmax];
ll l, r;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++)
    cin >> a[i];
  for(ll i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  
  cin >> t;
  while(t--){
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
  
  return 0;
}
