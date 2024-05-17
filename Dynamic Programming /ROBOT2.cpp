#include <bits/stdc++.h>
#define fmax 1003
#define ll long long
using namespace std;

// BÀI TOÁN CHƯA ĐẢM BẢO DỮ LIỆU CÓ ĐƯỜNG ĐI TỪ Ô (0, 0) TỚI Ô (N - 1, N - 1)
ll n;
ll duLieu[fmax][fmax];
ll availb[fmax][fmax];

bool hopLe(ll x, ll y){
  return (0 <= x && x < n && 0 <= y && y < n && duLieu[x][y] != -1);
}

void check_ava(ll x, ll y){
  if(hopLe(x, y)){
    availb[x][y] = 1;
    check_ava(x + 1, y);
    check_ava(x, y + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;

  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      cin >> duLieu[i][j];
  
  check_ava(0, 0);
  
  if(availb[n - 1][n - 1] == 1){
    ll ans(1e9);
    ll f[fmax][fmax];
    
    for(ll i = 0; i < n; i++)
      if(availb[i][0] != -1) f[i][0] = f[i - 1][0] * 2 + duLieu[i][0];
      else break;
        
    for(ll i = 1; i < n; i++)
      if(availb[0][i] != -1) f[0][i] = f[0][i - 1] * 2 + duLieu[0][i];
      else break;
    
    for(ll i = 1; i < n; i++)
      for(ll j = 1; j < n; j++)
        if(availb[i][j] != 0)
          if(availb[i - 1][j] == 0 && availb[i][j - 1] == 0)
            j++;
          else if(availb[i - 1][j] == 0)
            f[i][j] = f[i][j - 1] * 2 + duLieu[i][j];
          else if(availb[i][j - 1] == 0)
            f[i][j] = f[i - 1][j] * 2 + duLieu[i][j];
          else
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) * 2 + duLieu[i][j];
    
    cout << f[n - 1][n - 1];
  }else{
    ll ans(1e9);
    ll f[fmax][fmax];
    
    for(ll i = 0; i < n; i++)
      if(availb[i][0] != 0){
        f[i][0] = f[i - 1][0] * 2 + duLieu[i][0];
        if(availb[i + 1][0] == 0 && availb[i][1] == 0 || i + 1 == n && availb[i][1] == 0)
          ans = min(ans, f[i][0]);
      }
      else break;
        
    for(ll i = 0; i < n; i++)
      if(availb[0][i] != 0){
        f[0][i] = f[0][i - 1] * 2 + duLieu[0][i];
        if(availb[0][i + 1] == 0 && availb[1][i] == 0 || i + 1 == n && availb[1][i]== 0)
          ans = min(ans, f[0][i]);
      }
      else break;
    
    for(ll i = 1; i < n; i++)
      for(ll j = 1; j < n; j++)
        if(availb[i][j] != 0){
          if(availb[i - 1][j] == 0 && availb[i][j - 1] == 0)
            j++;
          else if(availb[i - 1][j] == 0)
            f[i][j] = f[i][j - 1] * 2 + duLieu[i][j];
          else if(availb[i][j - 1] == 0)
            f[i][j] = f[i - 1][j] * 2 + duLieu[i][j];
          else
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) * 2 + duLieu[i][j];
          if(availb[i - 1][j] == 0 && availb[i][j - 1] == 0)
            if(availb[i + 1][j] == 0 && availb[i][j + 1] == 0 || i + 1 == n && availb[i][j + 1] == 0 || j + 1 == n && availb[i + 1][j] == 0)
              ans = min(ans, f[i][0]);
        }
      cout << ans;
  }
  return 0;
}
/*
Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007496s 			0 MB		 [đúng]
test 2 :	0.007621s 			0 MB		 [đúng]
test 3 :	0.007129s 			0 MB		 [đúng]
test 4 :	0.009047s 			0 MB		 [đúng]
test 5 :	0.007830s 			0 MB		 [đúng]
test 6 :	0.009740s 			0 MB		 [đúng]
test 7 :	0.024493s 			0 MB		 [đúng]
test 8 :	0.110357s 			0 MB		 [đúng]
test 9 :	0.057550s 			0 MB		 [đúng]
*/
