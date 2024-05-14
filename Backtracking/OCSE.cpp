#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

ll m, n;
ll a[fmax][fmax];
ll c[fmax][fmax];
ll _max(-1e9);
ll iC(0);
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};

bool check(ll x, ll y){
  return (0 <= x && x < m && 0 <= y && y < n && c[y][x] == 0 && a[y][x] == 0);
}

void an_rau(ll x, ll y){
  for(ll i = 0; i < 4; i++){
    ll _x = x + dx[i];
    ll _y = y + dy[i];
    if(check(_x, _y)){
      c[_y][_x] = 1;
      an_rau(_x, _y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll x, y;
  cin >> n >> m >> y >> x;
  
  for(ll i = 0; i < n; i++) 
    for(ll j = 0; j < m; j++)
      cin >> a[i][j];
  
  c[y - 1][x - 1] = 1;
  an_rau(x - 1, y - 1);
  
  for(ll i = 0; i < n; i++) 
    for(ll j = 0; j < m; j++)
      if(c[i][j] == 1)
        iC++;
  cout << iC << '\n';
  return 0;
}
/*
Đúng 8/8
#######################
Thông tin chi tiết
test 1 :	0.007261s 			0 MB		 [đúng]
test 2 :	0.007613s 			0 MB		 [đúng]
test 3 :	0.007807s 			0 MB		 [đúng]
test 4 :	0.007841s 			0 MB		 [đúng]
test 5 :	0.006414s 			0 MB		 [đúng]
test 6 :	0.006495s 			0 MB		 [đúng]
test 7 :	0.006909s 			0 MB		 [đúng]
test 8 :	0.007521s 			0 MB		 [đúng]
*/
