#include <bits/stdc++.h>
#define fmax 1000006;
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n;
  ll dem = 1;
  cin >> n;
  ll f[n][n];
  
  for(ll i = 0; i < n; i++){
    if(i % 2 == 0)
      for(ll j = 0; j < n - 1; j++)
        f[i][j] = dem++;
    else
      for(ll j = n - 2; j >= 0; j--)
        f[i][j] = dem++;
    
  }
  
  for(ll i = n - 1; i >= 0; i--){
    f[i][n - 1] = dem++;
  }
  
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++)
      cout << f[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.006431s 			0 MB		 [đúng]
test 2 :	0.007704s 			0 MB		 [đúng]
test 3 :	0.006860s 			0 MB		 [đúng]
test 4 :	0.007805s 			0 MB		 [đúng]
test 5 :	0.007508s 			0 MB		 [đúng]
test 6 :	0.007903s 			0 MB		 [đúng]
test 7 :	0.008120s 			0 MB		 [đúng]
test 8 :	0.007404s 			0 MB		 [đúng]
test 9 :	0.007209s 			0 MB		 [đúng]
test 10 :	0.007366s 			0 MB		 [đúng]
*/
