#include <bits/stdc++.h>
#define MOD 10000007 
#define fmax 10004
#define ll long long
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  while(cin >> n){
    if(n == 0) return 0;
    else{
      ll a[fmax];
      ll f[fmax];
      ll s(-1e9);

      for(ll i = 0; i < n; i++) cin >> a[i];
      f[0] = a[0];
      for(ll i = 0; i < n; i++){
        f[i] = max(f[i - 1] + a[i], a[i]);
        s = max(s, f[i]);
      }
      if(s > 0) cout << "The maximum winning streak is " << s << ".\n";
      else cout << "Losing streak.\n";
    }
    
  }
  
  return 0;
}
/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.007959s 			0 MB		 [đúng]
test 2 :	0.010641s 			0 MB		 [đúng]
test 3 :	0.007802s 			0 MB		 [đúng]
test 4 :	0.006640s 			0 MB		 [đúng]
test 5 :	0.006447s 			0 MB		 [đúng]
*/
