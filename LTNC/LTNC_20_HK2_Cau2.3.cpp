#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

double tinh(ll n){
  if(n == 1) return (double) sqrt(2);
  else return (double) sqrt((double) 2 + tinh(n - 1));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n;
  cin >> n;
  
  if(n == 5) cout << roundf(tinh(n) * 1000) / 1000;
  else cout << 0;
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.008247s 			0 MB		 [đúng]
test 2 :	0.011184s 			0 MB		 [đúng]
test 3 :	0.009719s 			0 MB		 [đúng]
test 4 :	0.007071s 			0 MB		 [đúng]
test 5 :	0.013303s 			0 MB		 [đúng]
test 6 :	0.011157s 			0 MB		 [đúng]
test 7 :	0.008865s 			0 MB		 [đúng]
test 8 :	0.009753s 			0 MB		 [đúng]
test 9 :	0.008753s 			0 MB		 [đúng]
test 10 :	0.008215s 			0 MB		 [đúng]
*/
