#include <bits/stdc++.h>
#define fmax 1003
#define ll long long
using namespace std;

ll n, k;
ll f[fmax];
ll iC(0);

void xuLy(ll p){
  if(p == k){
    iC++;
    for(ll i = 0; i < k; i++)
      cout << f[i] << ' ';
    cout << '\n';
  }else
    for(ll i = f[p - 1] + 1; i <= n; i++){
      f[p] = i;
      xuLy(p + 1);
    }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  xuLy(0);
  cout << iC;
  return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007440s 			0 MB		 [đúng]
test 2 :	0.008120s 			0 MB		 [đúng]
test 3 :	0.008633s 			0 MB		 [đúng]
test 4 :	0.008460s 			0 MB		 [đúng]
test 5 :	0.008939s 			0 MB		 [đúng]
test 6 :	0.035402s 			0 MB		 [đúng]
test 7 :	0.008611s 			0 MB		 [đúng]
test 8 :	0.037348s 			0 MB		 [đúng]
test 9 :	0.008278s 			0 MB		 [đúng]
test 10 :	0.026263s 			0 MB		 [đúng]
*/
