#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1003
#define ll long long
using namespace std;

ll n, w;
ll a[fmax], b[fmax];
ll f[fmax][fmax];
vector<ll> item;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> w;
  for(ll i = 1; i <= n; i++) cin >> a[i];
  for(ll i = 1; i <= n; i++) cin >> b[i];

  for(ll i = 1; i <= n; i++)
    for(ll j = a[i]; j <= w; j++)
      f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);

  ll i(n), j(w);
  while(i > 0 && j > 0 && f[i][j] != 0){
    if(f[i][j] != f[i - 1][j]){
      item.push_back(i);
      j -= a[i];
      i --;
    }else{
      i --;
    }
  }
  
  ll v(0);
  for(ll i = 0; i < item.size(); i++){
    cout << item[i] << ' ';
    v += b[item[i]];
  }
  
  cout << '\n' << v << ' ' << w;
  
  return 0;
}

/*
Đúng 3/3
#######################
Thông tin chi tiết
test 1 :	0.006842s 			0 MB		 [đúng]
test 2 :	0.007155s 			0 MB		 [đúng]
test 3 :	0.007051s 			0 MB		 [đúng]
*/
