#include <bits/stdc++.h>
#define fmax 1000006;
#define ll long long
using namespace std;

void doics10_2(ll n){
  if(n / 2 == 0)  cout << n % 2;
  else{
    doics10_2(n / 2);
    cout << n % 2;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  
  cin >> n;
  doics10_2(n);
  
  return 0;
}
/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.006670s 			0 MB		 [đúng]
test 2 :	0.007571s 			0 MB		 [đúng]
test 3 :	0.006772s 			0 MB		 [đúng]
test 4 :	0.006332s 			0 MB		 [đúng]
test 5 :	0.006376s 			0 MB		 [đúng]
*/
