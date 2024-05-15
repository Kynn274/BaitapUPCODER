#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

ll n;
ll tick[fmax][fmax];          // Mảng đánh dấu
ll read[fmax][fmax];          
vector<ll> vx;
vector<ll> vy;


// Hàm đánh dấu vị trí cấm đi
void tick_it(ll x, ll y, bool flag){
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      // Đánh dấu hàng ngang, hàng dọc, đường chéo
      if(i == x || j == y || abs(x - i) == abs(y - j)) 
        if(flag == 0)
          tick[i][j] = 1;   
        else
          tick[i][j] = 0;
}

// Hàm xuất bàn cờ
void print_it(vector<ll> x, vector<ll> y){
  ll len = x.size();
  char table[n][n];
  
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      table[i][j] = '.';
      
  for(ll i = 0; i < len; i++)
    table[x[i]][y[i]] = 'Q';
  
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++)
      cout << table[i][j];
    cout << '\n';
  }
}

// Hàm xử lý thuật toán chính
void xuly(ll x){
  if(vx.size() == n){
    print_it(vx, vy);
    cout << '\n';
  }else{
    for(ll i = 0; i < n; i++){
      ll y = i;                                         // Kiểm tra theo dòng
      if(0 <= y && y < n && tick[x][y] == 0){
        vx.push_back(x);
        vy.push_back(y);
        tick_it(x, y, 0);                               // flag (biến cuối) đại diện cho bàn cờ đã được đáng dấu chưa
        xuly(x + 1);
        tick_it(x, y, 1);
        vx.pop_back();
        vy.pop_back();
        if(vx.size() != 0)                              // Đánh dấu lại cả mảng
          for(ll j = 0; j < vx.size(); j++)
            tick_it(vx[j], vy[j], 0);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  cin >> n;
  
  for(ll i = 0; i < n; i++){
    memset(tick, 0, sizeof tick);
    vx.push_back(0);
    vy.push_back(i);
    tick_it(0, i, 0);
    xuly(1);
    tick_it(0, i, 1);
    vx.clear();
    vy.clear();
  }
  return 0;
}
/*
Đúng 7/7
#######################
Thông tin chi tiết
test 1 :	0.022801s 			0 MB		 [đúng]
test 2 :	0.129672s 			0 MB		 [đúng]
test 3 :	0.051098s 			0 MB		 [đúng]
test 4 :	0.555620s 			0 MB		 [đúng]
test 5 :	0.032475s 			0 MB		 [đúng]
test 6 :	0.024932s 			0 MB		 [đúng]
test 7 :	0.036288s 			0 MB		 [đúng]
*/
