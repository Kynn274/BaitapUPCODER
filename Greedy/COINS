#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

ll n, s;
ll a[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ifstream ip ("COINS.INP");
  ofstream op ("COINS.OUT");
  
  ip >> n >> s;
  for(ll i = 1; i <= n; i++) ip >> a[i];
  
  memset(f, 60, sizeof f);
  ll _max = f[0];
  
  for(ll i = 1; i <= n; i++){
    f[a[i]] = 1;
    for(ll j = a[i]; j <= s; j++)
      f[j] = min(f[j - a[i]] + 1, f[j]);
  }
  
  f[s] == _max ? op << -1 : op << f[s];
  ip.close();
  op.close();
  return 0;
}
/*
Đúng 15/15
#######################
Thông tin chi tiết
test 1 :	0.019437s 			0 MB		 [đúng]
test 2 :	0.018528s 			0 MB		 [đúng]
test 3 :	0.020958s 			0 MB		 [đúng]
test 4 :	0.018495s 			0 MB		 [đúng]
test 5 :	0.188817s 			0 MB		 [đúng]
test 6 :	0.025474s 			0 MB		 [đúng]
test 7 :	0.016525s 			0 MB		 [đúng]
test 8 :	0.017041s 			0 MB		 [đúng]
test 9 :	0.187316s 			0 MB		 [đúng]
test 10 :	0.168633s 			0 MB		 [đúng]
test 11 :	0.131733s 			0 MB		 [đúng]
test 12 :	0.168918s 			0 MB		 [đúng]
test 13 :	0.016062s 			0 MB		 [đúng]
test 14 :	0.131590s 			0 MB		 [đúng]
test 15 :	0.015593s 			0 MB		 [đúng]
*/
