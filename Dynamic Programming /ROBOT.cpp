#include <bits/stdc++.h>
#define fmax 1003
#define ll long long
using namespace std;

ll n;
ll duLieu[fmax][fmax];
ll f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      cin >> duLieu[i][j];
  
  duLieu[0][0] == 1 ? f[0][0] = 1 : f[0][0] = 0;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      if(i != n || j != n)
        f[i][j] = duLieu[i][j] + max(f[i - 1][j], f[i][j - 1]) * 2;
  
  cout << f[n - 1][n - 1];
  return 0;
}

/*Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007654s 			0 MB		 [đúng]
test 2 :	0.008134s 			0 MB		 [đúng]
test 3 :	0.008563s 			0 MB		 [đúng]
test 4 :	0.008521s 			0 MB		 [đúng]
test 5 :	0.008523s 			0 MB		 [đúng]
test 6 :	0.008709s 			0 MB		 [đúng]
test 7 :	0.007065s 			0 MB		 [đúng]
test 8 :	0.008074s 			0 MB		 [đúng]
test 9 :	0.007792s 			0 MB		 [đúng]*/
