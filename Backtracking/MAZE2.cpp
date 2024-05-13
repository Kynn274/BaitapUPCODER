#include <bits/stdc++.h>
#define fmax 1002
#define ll long long
using namespace std;

ll n;
ll f[fmax][fmax];
ll p[fmax][fmax];
ll dx[] = {1, 0, 0, -1};
ll dy[] = {0, 1, -1, 0};

bool check(ll x, ll y){
  return (0 <= x && x < n && 0 <= y && y < n && p[x][y] == 0 && f[x][y] == 1);
}

void dichuyen(ll x, ll y, string s, bool & b){
  if(x == n - 1 && y == n - 1){
    cout << s << '\n';
    b = 1;
  }
  else{
    for(ll i = 0; i < 4; i++){
      ll _x = x + dx[i];
      ll _y = y + dy[i];
      if(check(_x, _y)){
        if(i == 0) s += "X";
        if(i == 1) s += "P";
        if(i == 2) s += "T";
        if(i == 3) s += "L";
        p[_x][_y] = 1;
        dichuyen(_x, _y, s, b);
        p[_x][_y] = 0;
        s.resize(s.size() - 1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    cin >> n;
    for(ll i = 0; i < n; i++)
      for(ll j = 0; j < n; j++)
        cin >> f[i][j];
    
    string s = "";
    bool b = 0;
    p[0][0] = 1;
    dichuyen(0, 0, s, b);
    if(b == 0) cout << -1 << '\n';
  
  return 0;
}
/*
Đúng 8/8
#######################
Thông tin chi tiết
test 1 :	0.007043s 			0 MB		 [đúng]
test 2 :	0.007191s 			0 MB		 [đúng]
test 3 :	0.007580s 			0 MB		 [đúng]
test 4 :	0.030701s 			0 MB		 [đúng]
test 5 :	0.007586s 			0 MB		 [đúng]
test 6 :	0.006603s 			0 MB		 [đúng]
test 7 :	0.007363s 			0 MB		 [đúng]
test 8 :	0.006305s 			0 MB		 [đúng]
*/
