#include <bits/stdc++.h>
#define fmax 102
#define ll long long
using namespace std;

ll n, k, s, iC(0);
ll f[fmax][fmax];

void xuly(ll tong, ll dem, ll i){
  if(dem == k && tong == s)
    iC++;
  else{
    if(tong < s && dem < k && i <= n){
      xuly(tong + i, dem + 1, i + 1);   // nếu cộng thêm phần tử
      xuly(tong, dem, i + 1);           // nếu không cộng thêm phần tử
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll ans(0);
  
  cin >> n >> k >> s;
  xuly(0, 0, 1);
  cout << iC;
  
  return 0;
}

/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.006756s 			0 MB		 [đúng]
test 2 :	0.007031s 			0 MB		 [đúng]
test 3 :	0.006915s 			0 MB		 [đúng]
test 4 :	0.007453s 			0 MB		 [đúng]
test 5 :	0.012965s 			0 MB		 [đúng]
test 6 :	0.007167s 			0 MB		 [đúng]
test 7 :	0.006802s 			0 MB		 [đúng]
test 8 :	0.009419s 			0 MB		 [đúng]
test 9 :	0.007317s 			0 MB		 [đúng]
test 10 :	0.008737s 			0 MB		 [đúng]
*/
