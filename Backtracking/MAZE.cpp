#include <bits/stdc++.h>
#define fmax 1002
#define ll long long
using namespace std;

ll t;
ll n;
ll f[fmax][fmax];

void dichuyen(ll x, ll y, string s, bool & b){
  if(x == n - 1 && y == n - 1){
    cout << s << '\n';
    b = 1;
  }
  else if(x < n - 1 || y < n - 1){
    if(f[x + 1][y] == 1){
      s += "X";
      dichuyen(x + 1, y, s, b);
      s.resize(s.size() - 1);
    }
    if(f[x][y + 1] == 1){
      s += "P";
      dichuyen(x, y + 1, s, b);
      s.resize(s.size() - 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> t;
  while(t--){
    cin >> n;
    for(ll i = 0; i < n; i++)
      for(ll j = 0; j < n; j++)
        cin >> f[i][j];
    
    string s = "";
    bool b = 0;
    dichuyen(0, 0, s, b);
    if(b == 0) cout << -1 << '\n';
  }
  return 0;
}

/*
Đúng 6/6
#######################
Thông tin chi tiết
test 1 :	0.007847s 			0 MB		 [đúng]
test 2 :	0.007901s 			0 MB		 [đúng]
test 3 :	0.007166s 			0 MB		 [đúng]
test 4 :	0.007986s 			0 MB		 [đúng]
test 5 :	0.007200s 			0 MB		 [đúng]
test 6 :	0.008562s 			0 MB		 [đúng]
*/
