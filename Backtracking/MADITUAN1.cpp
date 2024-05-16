#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll kickThuoc;
ll danhDau[fmax][fmax];
ll demLuot(0);
ll demCach(0);
ll dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
ll dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void xuly(ll x, ll y){
  if(demLuot == kickThuoc * kickThuoc){
    demCach++;
  }else{
    for(ll i = 0; i < 8; i++){
      ll _x = x + dx[i];
      ll _y = y + dy[i];
      if(0 <= _x && _x < kickThuoc && 0 <= _y && _y < kickThuoc && danhDau[_x][_y] == 0){
        danhDau[_x][_y] = 1;
        demLuot++;
        xuly(_x, _y);
        demLuot--;
        danhDau[_x][_y] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> kickThuoc;
  for(ll i = 0; i < kickThuoc; i++)
    for(ll j = 0; j < kickThuoc; j++){
      danhDau[i][j] = 1;
      demLuot++;
      xuly(i, j);
      demLuot--;
      danhDau[i][j] = 0;
    }
    
  cout << demCach;
  return 0;
}

/*
test 1 :	4.189327s 			0 MB		 [đúng]
test 2 :	0.011018s 			0 MB		 [đúng]
*/
