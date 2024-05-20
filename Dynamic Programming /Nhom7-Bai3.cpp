#include <bits/stdc++.h>
#define ll long long
#define fmax 1003
using namespace std;

ll n(1), w, x;
ll a[fmax];
ll f[fmax][fmax];                                                         // Kết quả
ll s[fmax][fmax];                                                         // Lưu vết

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll ans(0);
  cin >> w;
  while(cin >> x) a[n++] = x;
  memset(f, 0, sizeof f);
  
  for(ll i = 1; i < n; i++){
    s[i][i] = 0;
    for(ll j = a[i]; j <= w; j++)
      if(f[i - 1][j - a[i]] + a[i] <= j)
        f[i][j] = max(f[i - 1][j - a[i]] + a[i], f[i - 1][j]);
  }
  
  cout << "Khoi luong toi da la: " << f[n - 1][w] << "\n";
  
  vector<ll> item;
  ll i = n - 1, j = w;
  while(f[i][j] != 0 && i >= 1){
    if(f[i][j] != f[i - 1][j]){
      item.push_back(a[i]);
      j -= a[i];
    }
    i--;
  }
  cout << "Nhung vat can chon la: ";
  for(i = item.size() - 1; i >= 0; i--) cout << item[i] << ' ';
  return 0;
}
/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.017790s 			0 MB		 [đúng]
test 2 :	0.020022s 			0 MB		 [đúng]
test 3 :	0.020786s 			0 MB		 [đúng]
test 4 :	0.017466s 			0 MB		 [đúng]
test 5 :	0.017057s 			0 MB		 [đúng]
*/
