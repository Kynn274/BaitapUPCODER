#include <bits/stdc++.h>
#define fmax 1000006;
#define ll long long
using namespace std;

ll M(0), q, x, v, p, flag;
vector<vector<ll> > value(1002);

void find_and_set(vector<ll> & f, ll & s, ll & e){
    ll m = (s + e) / 2;
    if(m != s){
        find_and_set(f, s, m);
        find_and_set(f, m, e);
    }else{
        if(f[m] == x) f[m] += v;
    }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<ll> f;
  
  cin >> q;
  while(q--){
    cin >> flag;
    if(flag == 1){
      cin >> x;
      f.push_back(x);
      value[x].push_back(f.size() - 1);
    }
    else if(flag == 2){
      cin >> x >> v;
      ll len = value[x].size();
      for(ll j = 0; j < len; j++)
        f[value[x][j]] += v;
    }
    else if(flag == 3){
      cin >> p;
      cout << f[p - 1] << '\n';
    }
  }
  
  return 0;
}

/*
Đúng 10/20
#######################
Thông tin chi tiết
test 1 :	0.006954s 			0 MB		 [đúng]
test 2 :	0.008117s 			0 MB		 [đúng]
test 3 :	0.025224s 			0 MB		 [đúng]
test 4 :	0.024580s 			0 MB		 [đúng]
test 5 :	0.023317s 			0 MB		 [đúng]
test 6 :	0.028325s 			0 MB		 [đúng]
test 7 :	0.023077s 			0 MB		 [đúng]
test 8 :	0.023389s 			0 MB		 [đúng]
test 9 :	0.029629s 			0 MB		 [đúng]
test 10 :	0.024366s 			0 MB		 [đúng]
test 11 :	TLE     			0 MB		'[Time limit exceeded]'
test 12 :	TLE     			0 MB		'[Time limit exceeded]'
test 13 :	TLE     			0 MB		'[Time limit exceeded]'
test 14 :	TLE     			0 MB		'[Time limit exceeded]'
test 15 :	TLE     			0 MB		'[Time limit exceeded]'
test 16 :	TLE     			0 MB		'[Time limit exceeded]'
test 17 :	TLE     			0 MB		'[Time limit exceeded]'
test 18 :	TLE     			0 MB		'[Time limit exceeded]'
test 19 :	TLE     			0 MB		'[Time limit exceeded]'
test 20 :	TLE     			0 MB		'[Time limit exceeded]'

*/
