#include <bits/stdc++.h>
#define fmax 102
#define ll long long
using namespace std;

ll k, n;
ll f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  
  f[0][0] = 1;
  for(ll i = 0; i <= n; i++){
    f[i][i] = f[i][0] = 1;
    for(ll j = 1; j <= i; j++)
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
  }

  cout << f[n][k];
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007400s 			0 MB		 [đúng]
test 2 :	0.008710s 			0 MB		 [đúng]
test 3 :	0.008823s 			0 MB		 [đúng]
test 4 :	0.008214s 			0 MB		 [đúng]
test 5 :	0.008013s 			0 MB		 [đúng]
test 6 :	0.007710s 			0 MB		 [đúng]
test 7 :	0.008235s 			0 MB		 [đúng]
test 8 :	0.008308s 			0 MB		 [đúng]
test 9 :	0.008192s 			0 MB		 [đúng]
test 10 :	0.007953s 			0 MB		 [đúng]

*/
