#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

ll m, n;                        // DÒNG, CỘT
ll a[fmax][fmax];               // MẢNG ĐỀ
ll g[fmax][fmax];               // MẢNG ĐÁNH DẤU
ll sl(0);                       // ĐẾM NẤM TỪNG TRƯỜNG HỢP
ll iC(0);                       // ĐẾM SỐ TRƯỜNG HỢP HỢP LỆ
ll dx[] = {0, 1};
ll dy[] = {1, 0};

void xuly(ll x, ll y){
  if(x == m && y == n){
    if(sl - 1 >= 2)
      iC++;
  }else{
    for(ll i = 0; i < 2; i++){
      ll _x = x + dx[i];
      ll _y = y + dy[i];
      if(1 <= _x && _x <= m && 1 <= _y && _y <= n && a[_x][_y] != -1 && g[_x][_y] == 0){
        if(a[_x][_y] != a[x][y])
          sl++;
        g[_x][_y] = 1;
        xuly(_x, _y);
        g[_x][_y] = 0;
        if(a[_x][_y] != a[x][y])
          sl--;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> m >> n;
  for(ll i = 1; i <= m; i++)
    for(ll j = 1; j <= n; j++)
      cin >> a[i][j];
  
  g[1][1] = 1;
  xuly(1, 1);
  if(iC == 0) 
    cout << -1;
  else 
    cout << iC;

  return 0;
}
/*
Đúng 7/7
#######################
Thông tin chi tiết
test 1 :	0.007397s 			0 MB		 [đúng]
test 2 :	0.006521s 			0 MB		 [đúng]
test 3 :	0.006964s 			0 MB		 [đúng]
test 4 :	0.009059s 			0 MB		 [đúng]
test 5 :	0.010218s 			0 MB		 [đúng]
test 6 :	0.008276s 			0 MB		 [đúng]
test 7 :	0.007411s 			0 MB		 [đúng]
*/
