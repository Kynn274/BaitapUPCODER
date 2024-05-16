#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll lastNum(ll n){
  if(n <= 9) return n;
  else{
    ll tmp(0);
    while(n != 0){
      tmp += n % 10;
      n /= 10;
    }
    return lastNum(tmp);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n;
  cin >> n;
  cout << lastNum(n);
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.010613s 			0 MB		 [đúng]
test 2 :	0.009907s 			0 MB		 [đúng]
test 3 :	0.020611s 			0 MB		 [đúng]
test 4 :	0.009420s 			0 MB		 [đúng]
test 5 :	0.010248s 			0 MB		 [đúng]
test 6 :	0.012053s 			0 MB		 [đúng]
test 7 :	0.010002s 			0 MB		 [đúng]
test 8 :	0.009924s 			0 MB		 [đúng]
test 9 :	0.009812s 			0 MB		 [đúng]
test 10 :	0.012101s 			0 MB		 [đúng]
*/
