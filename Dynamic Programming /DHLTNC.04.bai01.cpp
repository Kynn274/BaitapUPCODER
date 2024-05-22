#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

ll n;
ll a[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> a[i];
  
  ll ans(1);      
  for(ll i = 0; i < n; i++){
    f[i] = 1;
    for(ll j = 0; j < i; j++)
      if(a[j] <= a[i])
        f[i] = max(f[i], f[j] + 1);
    ans = max(ans, f[i]);
  }
  
  cout << ans;
  return 0;
}
/*
Đúng 3/3
#######################
Thông tin chi tiết
test 1 :	0.006309s 			0 MB		 [đúng]
test 2 :	0.006809s 			0 MB		 [đúng]
test 3 :	0.006345s 			0 MB		 [đúng]*/
