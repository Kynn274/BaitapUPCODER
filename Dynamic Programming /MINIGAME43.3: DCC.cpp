#include <bits/stdc++.h>
#define MOD 10000007 
#define fmax 3003
#define ll long long
using namespace std;

ll m, n;
ll f[fmax][fmax];
char a[fmax];
char b[fmax];

void xuLy(){
  for(ll i = 0; i <= m; i++){
    for(ll j = 0; j <= n; j++)
      if(i == 0 || j == 0)
        f[i][j] = 0;
      else
        if(a[i - 1] == b[j - 1])
          f[i][j] = f[i - 1][j - 1] + 1;
        else 
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
  }
  cout << f[m][n];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> m >> n;
  for(ll i = 0; i < m; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) cin >> b[i];
  
  xuLy();
  return 0;
}
/*
Đúng 50/50
#######################
Thông tin chi tiết
test 1 :	0.006292s 			0 MB		 [đúng]
test 2 :	0.006189s 			0 MB		 [đúng]
test 3 :	0.006120s 			0 MB		 [đúng]
test 4 :	0.006443s 			0 MB		 [đúng]
test 5 :	0.006913s 			0 MB		 [đúng]
test 6 :	0.008190s 			0 MB		 [đúng]
test 7 :	0.006449s 			0 MB		 [đúng]
test 8 :	0.006364s 			0 MB		 [đúng]
test 9 :	0.007297s 			0 MB		 [đúng]
test 10 :	0.006928s 			0 MB		 [đúng]
test 11 :	0.006885s 			0 MB		 [đúng]
test 12 :	0.006217s 			0 MB		 [đúng]
test 13 :	0.006312s 			0 MB		 [đúng]
test 14 :	0.006783s 			0 MB		 [đúng]
test 15 :	0.006638s 			0 MB		 [đúng]
test 16 :	0.007098s 			0 MB		 [đúng]
test 17 :	0.007301s 			0 MB		 [đúng]
test 18 :	0.006646s 			0 MB		 [đúng]
test 19 :	0.008367s 			0 MB		 [đúng]
test 20 :	0.008266s 			0 MB		 [đúng]
test 21 :	0.007551s 			0 MB		 [đúng]
test 22 :	0.007793s 			0 MB		 [đúng]
test 23 :	0.009111s 			0 MB		 [đúng]
test 24 :	0.005997s 			0 MB		 [đúng]
test 25 :	0.008690s 			0 MB		 [đúng]
test 26 :	0.010765s 			0 MB		 [đúng]
test 27 :	0.016910s 			0 MB		 [đúng]
test 28 :	0.016739s 			0 MB		 [đúng]
test 29 :	0.011846s 			0 MB		 [đúng]
test 30 :	0.009726s 			0 MB		 [đúng]
test 31 :	0.034577s 			0 MB		 [đúng]
test 32 :	0.026282s 			0 MB		 [đúng]
test 33 :	0.013043s 			0 MB		 [đúng]
test 34 :	0.014439s 			0 MB		 [đúng]
test 35 :	0.006347s 			0 MB		 [đúng]
test 36 :	0.042071s 			0 MB		 [đúng]
test 37 :	0.010093s 			0 MB		 [đúng]
test 38 :	0.060247s 			0 MB		 [đúng]
test 39 :	0.022678s 			0 MB		 [đúng]
test 40 :	0.006330s 			0 MB		 [đúng]
test 41 :	0.157169s 			0 MB		 [đúng]
test 42 :	0.108840s 			0 MB		 [đúng]
test 43 :	0.114968s 			0 MB		 [đúng]
test 44 :	0.073533s 			0 MB		 [đúng]
test 45 :	0.018325s 			0 MB		 [đúng]
test 46 :	0.006545s 			0 MB		 [đúng]
test 47 :	0.006969s 			0 MB		 [đúng]
test 48 :	0.006405s 			0 MB		 [đúng]
test 49 :	0.006105s 			0 MB		 [đúng]
test 50 :	0.006366s 			0 MB		 [đúng]
*/
