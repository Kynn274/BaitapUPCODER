#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll n, m;
char duLieu[fmax][fmax];
string f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> m >> n;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < n; j++)
      cin >> duLieu[i][j];
  
  for(ll i = 0; i < n; i++)
    f[0][i] = f[0][i - 1] + duLieu[0][i];
  
  for(ll i = 1; i < m; i++)
    f[i][0] = f[i - 1][0] + duLieu[i][0];
  
  for(ll i = 1; i < m; i++)
    for(ll j = 1; j < n; j++)
      f[i][j] = min(f[i - 1][j], f[i][j - 1]) + duLieu[i][j];
  
  cout << f[m - 1][n - 1];
  return 0;
}
/*
Đúng 4/4
#######################
Thông tin chi tiết
test 1 :	0.006691s 			0 MB		 [đúng]
test 2 :	0.006941s 			0 MB		 [đúng]
test 3 :	0.008007s 			0 MB		 [đúng]
test 4 :	0.008262s 			0 MB		 [đúng]
*/
