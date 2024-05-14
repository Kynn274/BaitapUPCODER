#include <bits/stdc++.h>
#define fmax 102
#define ll long long
using namespace std;

ll f[fmax][fmax];

ll to_hop(ll n, ll k){
  if(n == k || k == 0) return 1;
  if(k > n) return 0;
  if(f[n][k] != -1) return f[n][k];
  
  f[n][k] = to_hop(n - 1, k) + to_hop(n - 1, k - 1);
  return f[n][k];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll k, n;
  cin >> n >> k;
  
  memset(f, -1, sizeof f);
  cout << to_hop(n, k);
  return 0;
}

/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007381s 			0 MB		 [đúng]
test 2 :	0.009968s 			0 MB		 [đúng]
test 3 :	0.010213s 			0 MB		 [đúng]
test 4 :	0.008631s 			0 MB		 [đúng]
test 5 :	0.013067s 			0 MB		 [đúng]
test 6 :	0.007794s 			0 MB		 [đúng]
test 7 :	0.011374s 			0 MB		 [đúng]
test 8 :	0.008240s 			0 MB		 [đúng]
test 9 :	0.008209s 			0 MB		 [đúng]
test 10 :	0.009216s 			0 MB		 [đúng]
*/
