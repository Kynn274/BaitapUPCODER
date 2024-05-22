#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 10000007
#define ll long long
using namespace std;

ll n, m;
ll a, b, k;
ll f[fmax];
ll ans(-1e9);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  while(m--){
    cin >> a >> b >> k;
    f[a] += k;
    f[b + 1] -= k;
  }

  for(ll i = 1; i <= n; i++){
    f[i] += f[i - 1];
    ans = max(ans, f[i]);
  }
  cout << ans;
  
  return 0;
}

/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.006591s 			0 MB		 [đúng]
test 2 :	0.007967s 			0 MB		 [đúng]
test 3 :	0.009151s 			0 MB		 [đúng]
test 4 :	0.006652s 			0 MB		 [đúng]
test 5 :	0.022062s 			0 MB		 [đúng]
test 6 :	0.022185s 			0 MB		 [đúng]
test 7 :	0.025910s 			0 MB		 [đúng]
test 8 :	0.372087s 			0 MB		 [đúng]
test 9 :	0.370666s 			0 MB		 [đúng]
test 10 :	0.365965s 			0 MB		 [đúng]
*/
