#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1003
#define ll long long
using namespace std;

ll n, m;
ll a[fmax][fmax];
ll f[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> m >> n;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < n; j++)
      cin >> a[i][j];
      
  f[0][0] = a[0][0];
  for(ll i = 1; i < n; i++) f[0][i] = f[0][i - 1] + a[0][i];
  for(ll i = 1; i < m; i++) f[i][0] = f[i - 1][0] + a[i][0];
  
  for(ll i = 1; i < m; i++)
    for(ll j = 1; j < n; j++)
      f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
  
  cout << f[m - 1][n - 1] << '\n';
  vector<ll> x;
  vector<ll> y;
  
  x.push_back(m - 1);
  y.push_back(n - 1);
  ll i = m - 1, j = n - 1;
  while(j != 0 && i != 0){
    f[i - 1][j] < f[i][j - 1] ? j-- : i--;
    x.push_back(i);
    y.push_back(j);
  }
  
  while(i != 0){
    x.push_back(--i);
    y.push_back(0);
  }
  while(j != 0){
    x.push_back(0);
    y.push_back(--j);
  }
  for(i = x.size() - 1; i >= 0; i--)
    cout << x[i] + 1 << ' ' << y[i] + 1 << '\n';
  return 0;
}
/*
Đúng 27/27
#######################
Thông tin chi tiết
test 1 :	0.006796s 			0 MB		 [đúng]
test 2 :	0.010535s 			0 MB		 [đúng]
test 3 :	0.009054s 			0 MB		 [đúng]
test 4 :	0.011776s 			0 MB		 [đúng]
test 5 :	0.011672s 			0 MB		 [đúng]
test 6 :	0.010076s 			0 MB		 [đúng]
test 7 :	0.008220s 			0 MB		 [đúng]
test 8 :	0.008331s 			0 MB		 [đúng]
test 9 :	0.008491s 			0 MB		 [đúng]
test 10 :	0.008214s 			0 MB		 [đúng]
test 11 :	0.007322s 			0 MB		 [đúng]
test 12 :	0.015158s 			0 MB		 [đúng]
test 13 :	0.092488s 			0 MB		 [đúng]
test 14 :	0.073408s 			0 MB		 [đúng]
test 15 :	0.146847s 			0 MB		 [đúng]
test 16 :	0.070079s 			0 MB		 [đúng]
test 17 :	0.077798s 			0 MB		 [đúng]
test 18 :	0.195452s 			0 MB		 [đúng]
test 19 :	0.189104s 			0 MB		 [đúng]
test 20 :	0.017208s 			0 MB		 [đúng]
test 21 :	0.012423s 			0 MB		 [đúng]
test 22 :	0.011396s 			0 MB		 [đúng]
test 23 :	0.030361s 			0 MB		 [đúng]
test 24 :	0.039285s 			0 MB		 [đúng]
test 25 :	0.047927s 			0 MB		 [đúng]
test 26 :	0.030932s 			0 MB		 [đúng]
test 27 :	0.026894s 			0 MB		 [đúng]

*/
