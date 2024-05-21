#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1003
#define ll long long
using namespace std;

ll n, s;
ll a[fmax], b[fmax];
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s;
  for(ll i = 1; i <= n; i++) cin >> a[i];
  for(ll i = 1; i <= n; i++) cin >> b[i];
  
  for(ll i = 1; i <= n; i++)
    for(ll j = s; j >= 1; j--)
      if(j >= a[i])
        f[j] = max(f[j], f[j - a[i]] + b[i]);
    
  cout << f[s];
  return 0;
}
/*
Đúng 14/14
#######################
Thông tin chi tiết
test 1 :	0.006573s 			0 MB		 [đúng]
test 2 :	0.008944s 			0 MB		 [đúng]
test 3 :	0.011869s 			0 MB		 [đúng]
test 4 :	0.028140s 			0 MB		 [đúng]
test 5 :	0.031103s 			0 MB		 [đúng]
test 6 :	0.007529s 			0 MB		 [đúng]
test 7 :	0.140386s 			0 MB		 [đúng]
test 8 :	0.157759s 			0 MB		 [đúng]
test 9 :	0.149641s 			0 MB		 [đúng]
test 10 :	0.199475s 			0 MB		 [đúng]
test 11 :	0.147200s 			0 MB		 [đúng]
test 12 :	0.179684s 			0 MB		 [đúng]
test 13 :	0.007343s 			0 MB		 [đúng]
test 14 :	0.197613s 			0 MB		 [đúng]
*/
