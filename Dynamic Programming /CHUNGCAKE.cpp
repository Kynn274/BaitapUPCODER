#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

int n, s;
ll a[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> s;
  for(ll i = 1; i <= n; i++) cin >> a[i];
  
  memset(f, 0, sizeof f);

  for(ll i = 1; i <= n; i++)
    for(ll j = s; j >= a[i]; j--)
      f[j] = max(f[j], f[j - a[i]] + a[i]);

  cout << f[s];
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.016481s 			0 MB		 [đúng]
test 2 :	0.016750s 			0 MB		 [đúng]
test 3 :	0.016504s 			0 MB		 [đúng]
test 4 :	0.015876s 			0 MB		 [đúng]
test 5 :	0.016311s 			0 MB		 [đúng]
test 6 :	0.017540s 			0 MB		 [đúng]
test 7 :	0.016650s 			0 MB		 [đúng]
test 8 :	0.016681s 			0 MB		 [đúng]
test 9 :	0.016854s 			0 MB		 [đúng]
test 10 :	0.019231s 			0 MB		 [đúng]
*/

