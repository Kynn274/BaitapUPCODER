#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll m, s;
  cin >> m >> s;
  
  ll f_min[m];
  ll f_max[m];
  ll s_max;
  ll s_min;
  
  for(ll i = 0; i < m; i++){
    f_min[i] = 0;
    f_max[i] = 9;
  }
  
  s_max = 9 * m;
  s_min = 1;
  f_min[0] = 1;
  
  ll i = m - 1;
  while(0 <= i && s_max != s){
    if(s_max - s >= 9){
      f_max[i] = 0;
      s_max   -= 9;
      i--;
    }else{
      f_max[i] -= (s_max - s);
      s_max = s;
    }
  }
      
  i = m - 1;
  while(0 <= i && s_min != s){
    if(s - s_min >= 9){
      f_min[i] = 9;
      s_min   += 9;
      i--;
    }else{
      f_min[i] += (s - s_min);
      s_min = s;
    }
  }
  if(m == 1 && s == 0) cout << 0 << '\n' << 0;
  else{
    if(s_max != s || s_min != s) cout << -1;
    else if(f_min[0] == 0 || f_max[0] == 0) cout << -1;
    else{
      for(ll i : f_min) cout << i;
      cout << '\n';
      for(ll i : f_max) cout << i;
    }
  }
  
  return 0;
}
/*
Đúng 13/13
#######################
Thông tin chi tiết
test 1 :	0.006313s 			0 MB		 [đúng]
test 2 :	0.008155s 			0 MB		 [đúng]
test 3 :	0.013141s 			0 MB		 [đúng]
test 4 :	0.006170s 			0 MB		 [đúng]
test 5 :	0.006619s 			0 MB		 [đúng]
test 6 :	0.006144s 			0 MB		 [đúng]
test 7 :	0.006185s 			0 MB		 [đúng]
test 8 :	0.006380s 			0 MB		 [đúng]
test 9 :	0.007875s 			0 MB		 [đúng]
test 10 :	0.005022s 			0 MB		 [đúng]
test 11 :	0.007667s 			0 MB		 [đúng]
test 12 :	0.006720s 			0 MB		 [đúng]
test 13 :	0.006820s 			0 MB		 [đúng]
*/
