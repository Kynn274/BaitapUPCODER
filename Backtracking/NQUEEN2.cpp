#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll duLieu[fmax][fmax];
ll banCo[fmax][fmax];
ll tongDiem(0);
ll ketQua(-1e9);

bool kiemTra(ll x, ll y){
  for(ll i = 0; i < x; i++)                                 // Kiểm tra cột
    if(banCo[i][y] == 1) return 0; 
    
  for(ll i = x, j = y; i >= 0 && j >= 0; i--, j--)          // Kiểm tra chéo trái
    if(banCo[i][j] == 1) return 0;
  
  for(ll i = x, j = y; i >= 0 && j <  8; i--, j++)          // Kiểm tra chéo phải
    if(banCo[i][j] == 1) return 0;
  
  return 1;
}

bool xuLy(ll x){
  if(x == 8){
    ketQua = max(ketQua, tongDiem);
    return true;
  }
  bool check(0);
  for(ll i = 0; i < 8; i++){
    if(kiemTra(x, i)){
      tongDiem += duLieu[x][i];
      banCo[x][i] = 1;
      check |= xuLy(x + 1);
      banCo[x][i] = 0;
      tongDiem -= duLieu[x][i];
    }
  }
  return check;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  memset(banCo, 0, sizeof banCo);
  for(ll i = 0; i < 8; i++)
    for(ll j = 0; j < 8; j++)
      cin >> duLieu[i][j];

  if(!xuLy(0)) cout << 0;
  else cout << ketQua;
  return 0;
}
/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.008947s 			0 MB		 [đúng]
test 2 :	0.010637s 			0 MB		 [đúng]
test 3 :	0.008078s 			0 MB		 [đúng]
test 4 :	0.009328s 			0 MB		 [đúng]
test 5 :	0.072418s 			0 MB		 [đúng]
*/
