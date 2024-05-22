#include <bits/stdc++.h>
#define MOD 10000007 
#define fmax 10000007
#define ll long long
using namespace std;

ll n;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll tmp;
  ll _max(-1e9);
  ll iC(0);
  
  cin >> n;
  while(n != 0){
    tmp = n;
    while(tmp != 0){
      _max = max(_max, tmp % 10);
      tmp /= 10;
    }
    n -= _max;
    _max = -1e9;
    iC++;
  }
  cout << iC;
  
  return 0;
}
/*
Đúng 14/14
#######################
Thông tin chi tiết
test 1 :	0.006250s 			0 MB		 [đúng]
test 2 :	0.006897s 			0 MB		 [đúng]
test 3 :	0.006432s 			0 MB		 [đúng]
test 4 :	0.006081s 			0 MB		 [đúng]
test 5 :	0.005933s 			0 MB		 [đúng]
test 6 :	0.005787s 			0 MB		 [đúng]
test 7 :	0.005739s 			0 MB		 [đúng]
test 8 :	0.006330s 			0 MB		 [đúng]
test 9 :	0.007148s 			0 MB		 [đúng]
test 10 :	0.015925s 			0 MB		 [đúng]
test 11 :	0.024836s 			0 MB		 [đúng]
test 12 :	0.023429s 			0 MB		 [đúng]
test 13 :	0.023434s 			0 MB		 [đúng]
test 14 :	0.006302s 			0 MB		 [đúng]

*/
