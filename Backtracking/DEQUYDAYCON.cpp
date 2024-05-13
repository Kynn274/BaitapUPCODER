#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

ll n, S, iC(0);
ll a[fmax];
ll f[fmax];

void xuly(vector<ll> v, ll tong, ll i){
  if(tong == S){
    iC++;
    for(ll i = 0; i < v.size(); i++)
      cout << v[i] << ' ';
    cout << '\n';
  }else{
    if(tong < S && i < n){
      tong += a[i];
      v.push_back(a[i]);
      xuly(v, tong, i + 1);
      v.pop_back();
      tong -= a[i];
      xuly(v, tong, i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> S;
  for(ll i = 0; i < n; i++) 
    cin >> a[i];
    
  for(ll i = 0; i < n - 1; i++)
    for(ll j = i + 1; j < n; j++)
      if(a[j] < a[i]) 
        swap(a[i], a[j]);
    
  vector<ll> v;
  xuly(v, 0, 0);
  if(iC == 0) cout << -1;
  
  return 0;
}

/*
Đúng 6/6
#######################
Thông tin chi tiết
test 1 :	0.006496s 			0 MB		 [đúng]
test 2 :	0.008920s 			0 MB		 [đúng]
test 3 :	0.007428s 			0 MB		 [đúng]
test 4 :	0.006616s 			0 MB		 [đúng]
test 5 :	0.008004s 			0 MB		 [đúng]
test 6 :	0.006548s 			0 MB		 [đúng]
*/
