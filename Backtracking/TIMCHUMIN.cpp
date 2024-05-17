#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll n, m;
char duLieu[fmax][fmax];
string s;
string tmp;

void xuLy(ll x, ll y){
    if(x == m - 1 && y == n - 1)
      s.size() == 0 ? s = tmp : s > tmp ? s = tmp : s = s;
    else{
      if(0 <= x && x < m && 0 <= y && y < n){
        tmp += duLieu[x][y];
        xuLy(x + 1, y);
        xuLy(x, y + 1);
        tmp.resize(tmp.size() - 1);
      }
    }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> m >> n;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < n; j++)
      cin >> duLieu[i][j];
  
  xuLy(0, 0);
  cout << s << duLieu[m - 1][n - 1];
  return 0;
}

/*
Đúng 4/4
#######################
Thông tin chi tiết
test 1 :	0.006243s 			0 MB		 [đúng]
test 2 :	0.007473s 			0 MB		 [đúng]
test 3 :	0.008185s 			0 MB		 [đúng]
test 4 :	1.356445s 			0 MB		 [đúng]
*/
