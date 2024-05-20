#include <bits/stdc++.h>
#define ll long long
#define fmax 1003
using namespace std;

ll n;
ll a[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll ans = 0;
  cin >> n;
  for(auto &x : a) cin >> x;
  
  for(ll i = 0; i < n; i++){
    f[i] = max(f[i], a[i]);
    for(ll j = i + 2; j < n; j++)
      f[j] = max(f[j], f[i] + a[j]);
  }
  
  for(ll i = 0; i < n; i++)
    ans = max(ans, f[i]);
    
  cout << ans;
  
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.006949s 			0 MB		 [đúng]
test 2 :	0.007903s 			0 MB		 [đúng]
test 3 :	0.007683s 			0 MB		 [đúng]
test 4 :	0.007826s 			0 MB		 [đúng]
test 5 :	0.007813s 			0 MB		 [đúng]
test 6 :	0.009458s 			0 MB		 [đúng]
test 7 :	0.007000s 			0 MB		 [đúng]
test 8 :	0.007515s 			0 MB		 [đúng]
test 9 :	0.008322s 			0 MB		 [đúng]
test 10 :	0.007220s 			0 MB		 [đúng]
*/
