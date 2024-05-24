#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll k;
ll fa[fmax];
ll fb[fmax];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
  cin >> k;
  fa[0] = 1;
  fb[0] = 0;
  for(ll i = 1; i <= k; i++){
    fb[i] = fa[i - 1] + fb[i - 1];
    fa[i] = fb[i - 1];
  }
  cout << fa[k] << ' ' << fb[k];
  return 0;
}
/*
Đúng 13/13
#######################
Thông tin chi tiết
test 1 :	0.007303s 			0 MB		 [đúng]
test 2 :	0.007315s 			0 MB		 [đúng]
test 3 :	0.007187s 			0 MB		 [đúng]
test 4 :	0.008662s 			0 MB		 [đúng]
test 5 :	0.008079s 			0 MB		 [đúng]
test 6 :	0.007256s 			0 MB		 [đúng]
test 7 :	0.007254s 			0 MB		 [đúng]
test 8 :	0.006858s 			0 MB		 [đúng]
test 9 :	0.006723s 			0 MB		 [đúng]
test 10 :	0.006563s 			0 MB		 [đúng]
test 11 :	0.007125s 			0 MB		 [đúng]
test 12 :	0.007751s 			0 MB		 [đúng]
test 13 :	0.007240s 			0 MB		 [đúng]
*/
