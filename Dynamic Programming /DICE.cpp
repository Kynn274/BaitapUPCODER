#include <bits/stdc++.h>
#define MOD 1000000007
#define fmax 1000006
#define ll long long
using namespace std;

int n;
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ifstream ip ("DICE.INP");
  ofstream op ("DICE.OUT");
  
  ip >> n;
  memset(f, 0, sizeof f);

  f[0] = 1;
  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= min((int) i, 6); j++)
      f[i] = (f[i] + f[i - j]) % MOD;
    
  op << f[n];
  return 0;
}
/*
Đúng 20/20
#######################
Thông tin chi tiết
test 1 :	0.018607s 			0 MB		 [đúng]
test 2 :	0.016364s 			0 MB		 [đúng]
test 3 :	0.017424s 			0 MB		 [đúng]
test 4 :	0.017049s 			0 MB		 [đúng]
test 5 :	0.017577s 			0 MB		 [đúng]
test 6 :	0.018975s 			0 MB		 [đúng]
test 7 :	0.017047s 			0 MB		 [đúng]
test 8 :	0.019545s 			0 MB		 [đúng]
test 9 :	0.018635s 			0 MB		 [đúng]
test 10 :	0.018274s 			0 MB		 [đúng]
test 11 :	0.017807s 			0 MB		 [đúng]
test 12 :	0.017181s 			0 MB		 [đúng]
test 13 :	0.028291s 			0 MB		 [đúng]
test 14 :	0.079364s 			0 MB		 [đúng]
test 15 :	0.184139s 			0 MB		 [đúng]
test 16 :	0.118672s 			0 MB		 [đúng]
test 17 :	0.113963s 			0 MB		 [đúng]
test 18 :	0.019134s 			0 MB		 [đúng]
test 19 :	0.112211s 			0 MB		 [đúng]
test 20 :	0.017699s 			0 MB		 [đúng]
*/
