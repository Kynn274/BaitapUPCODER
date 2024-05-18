#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll m, n;                                        // cột, dòng
char duLieu[fmax][fmax];                        // Mảng đầu vào
bool unavai[fmax][fmax];                        // Mảng kiểu tra ô đã đi
string s;                                       // Chuối đầu vào
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
bool accepted = 0;                              // Biến kiểm tra

void xuLy(ll x, ll y, ll p){
  // Nếu kí tự bằng kí tự cuối chuỗi, p là con trỏ
  if(duLieu[x][y] == s[p] && p == s.size() - 1){
    accepted = 1;                               // accepted = 1 -> tìm được           
    return;
  }else{
    for(ll i = 0; i < 4; i++){
      ll _x = x + dx[i];
      ll _y = y + dy[i];
      if(0 <= _x && _x < n && 0 <= _y && _y < m && duLieu[_x][_y] == s[p + 1] && unavai[_x][_y] == 0){
        unavai[_x][_y] = 1;
        xuLy(_x, _y, p + 1);
        unavai[_x][_y] = 0;
      }
    } 
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < m; j++)
      cin >> duLieu[i][j];
      
  cin >> s;
      
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < m; j++)
      if(duLieu[i][j] == s[0]){
        unavai[i][j] = 1;
        xuLy(i, j, 0);
        unavai[i][j] = 0;
      }
    
  accepted == 1 ? cout << "YES" : cout << "NO";
  return 0;
}
/*
Đúng 21/21
#######################
Thông tin chi tiết
test 1 :	0.007279s 			0 MB		 [đúng]
test 2 :	0.008157s 			0 MB		 [đúng]
test 3 :	0.007472s 			0 MB		 [đúng]
test 4 :	0.006991s 			0 MB		 [đúng]
test 5 :	0.007136s 			0 MB		 [đúng]
test 6 :	0.007018s 			0 MB		 [đúng]
test 7 :	0.006798s 			0 MB		 [đúng]
test 8 :	0.006451s 			0 MB		 [đúng]
test 9 :	0.009956s 			0 MB		 [đúng]
test 10 :	0.007545s 			0 MB		 [đúng]
test 11 :	0.008447s 			0 MB		 [đúng]
test 12 :	0.007490s 			0 MB		 [đúng]
test 13 :	0.007708s 			0 MB		 [đúng]
test 14 :	0.006974s 			0 MB		 [đúng]
test 15 :	0.006595s 			0 MB		 [đúng]
test 16 :	0.006893s 			0 MB		 [đúng]
test 17 :	0.007992s 			0 MB		 [đúng]
test 18 :	0.009344s 			0 MB		 [đúng]
test 19 :	0.007944s 			0 MB		 [đúng]
test 20 :	0.007678s 			0 MB		 [đúng]
test 21 :	0.034762s 			0 MB		 [đúng]
*/
