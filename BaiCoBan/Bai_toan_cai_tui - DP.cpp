#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

// BÀI TOÁN CÁI TÚI

ll n, S;                      // Số lượng vật phẩm, Số kí tối đa
ll r[fmax];                   // Mảng chứa giá trị vật
ll w[fmax];                   // Mảng chứa cân nặng vật
ll f[fmax];                   // Mảng chứa giá trị lớn nhất
ll g[fmax];                   // Mảng ghi nhớ giá trị lớn nhất

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll ans(0);
  
  cin >> n >> S;
  for(ll i = 1; i <= n; i++)
    cin >> w[i] >> r[i];
  
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  
  for(ll i = 1; i <= n; i++){
    for(ll j = w[i]; j <= S; j++){
      f[j] = max(g[j], g[j - w[i]] + r[i]);
      ans = max(ans, f[j]);
    }
    for(ll j = w[i]; j <= S; j++)
      g[j] = f[j];
  }
    
  cout << ans;
  
  return 0;
}
