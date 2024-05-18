#include <bits/stdc++.h>
#define ll long long
#define fmax 100005
using namespace std;

// BỊ TRÀN MẢNG
ll n, S, P;
ll bongHoa[fmax];
ll f[fmax];                                     
ll f1[fmax];
ll g1[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> S >> P;
  for(ll i = 0; i < n; i++)
    cin >> bongHoa[i];
  
  memset(f, 60, sizeof f);
  memset(f1, 60, sizeof f1);
  ll _max = f[0];
  
  f[0] = 0;
  
    for(ll i = 0; i < n; i++)
      for(ll j = bongHoa[i]; j <= S; j++)
        f[j] = min(f[j], f[j - bongHoa[i]] + P);
  
    if(f[S] == _max) cout << -1;
      else cout << f[S];
  
  return 0;
}
/*
Đúng 7/10
#######################
Thông tin chi tiết
test 1 :	0.026260s 			0 MB		 [đúng]
test 2 :	0.027468s 			0 MB		 [đúng]
test 3 :	0.040218s 			0 MB		 [đúng]
test 4 :	0.040119s 			0 MB		 [đúng]
test 5 :	RE      			0 MB		'[Runtime error]'
test 6 :	0.037967s 			0 MB		 [đúng]
test 7 :	0.059100s 			0 MB		 [đúng]
test 8 :	0.088223s 			0 MB		 [đúng]
test 9 :	RE      			0 MB		'[Runtime error]'
test 10 :	0.350364s 			0 MB		'[sai]'
*/
