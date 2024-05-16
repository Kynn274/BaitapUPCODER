#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll tinhTong(ll n){
  if(n == 1) return 1;
  else return n + tinhTong(n - 1);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n;
  cin >> n;
  cout << tinhTong(n);
  return 0;
}

/*Đúng 6/6
#######################
Thông tin chi tiết
test 1 :	0.006679s 			0 MB		 [đúng]
test 2 :	0.006827s 			0 MB		 [đúng]
test 3 :	0.008477s 			0 MB		 [đúng]
test 4 :	0.007520s 			0 MB		 [đúng]
test 5 :	0.007077s 			0 MB		 [đúng]
test 6 :	0.007564s 			0 MB		 [đúng]*/
