#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

ll n;
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  f[1] = f[2] = 1;
  for(ll i = 3; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];
  cout << f[n];
  
  return 0;
}
/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.007102s 			0 MB		 [đúng]
test 2 :	0.009647s 			0 MB		 [đúng]
test 3 :	0.007010s 			0 MB		 [đúng]
test 4 :	0.008169s 			0 MB		 [đúng]
test 5 :	0.008118s 			0 MB		 [đúng]
*/
