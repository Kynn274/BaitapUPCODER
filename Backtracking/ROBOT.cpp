#include <bits/stdc++.h>
#define fmax 1003
#define ll long long
using namespace std;

ll n;
ll duLieu[fmax][fmax];
ll f[fmax][fmax];
ll ketQua(-1e9);

void xuLy(ll i, ll j, ll tong){
  if(i == n - 1 && j == n - 1){
    ketQua = max(ketQua, tong * 2 + duLieu[i][j]);
  }else{
    if(i < n && j < n){
      tong = tong * 2 + duLieu[i][j];
      xuLy(i + 1, j, tong);
      xuLy(i, j + 1, tong);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      cin >> duLieu[i][j];
  
  xuLy(0, 0, 0);
  cout << ketQua;
  return 0;
}
/*
Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007291s 			0 MB		 [đúng]
test 2 :	0.009061s 			0 MB		 [đúng]
test 3 :	0.007391s 			0 MB		 [đúng]
test 4 :	0.007700s 			0 MB		 [đúng]
test 5 :	0.008693s 			0 MB		 [đúng]
test 6 :	0.011180s 			0 MB		 [đúng]
test 7 :	0.022471s 			0 MB		 [đúng]
test 8 :	0.060811s 			0 MB		 [đúng]
test 9 :	0.211001s 			0 MB		 [đúng]*/
