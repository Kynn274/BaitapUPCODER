#include <bits/stdc++.h>
#define fmax 1000006;
#define ll long long
using namespace std;

ll n, k;
ll f[10];
string s;
vector<string> v;

void xuly(ll i){
  if(i == n){
    for(ll j = 0; j < n; j++)
      s += to_string(f[j]);
    v.push_back(s);
    s.clear();
  }else{
    for(ll j = 1; j <= k; j++){
      f[i] = j;
      xuly(i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> k >> n;
  s = "";
  xuly(0);
  cout << v.size() << '\n';
  for(string i : v)
    cout << i << '\n';
  
  return 0;
}
/*
Đúng 17/17
#######################
Thông tin chi tiết
test 1 :	0.006374s 			0 MB		 [đúng]
test 2 :	0.008058s 			0 MB		 [đúng]
test 3 :	0.007937s 			0 MB		 [đúng]
test 4 :	0.008133s 			0 MB		 [đúng]
test 5 :	0.007327s 			0 MB		 [đúng]
test 6 :	0.006900s 			0 MB		 [đúng]
test 7 :	0.007827s 			0 MB		 [đúng]
test 8 :	0.007369s 			0 MB		 [đúng]
test 9 :	0.009004s 			0 MB		 [đúng]
test 10 :	0.007708s 			0 MB		 [đúng]
test 11 :	0.007309s 			0 MB		 [đúng]
test 12 :	0.007149s 			0 MB		 [đúng]
test 13 :	0.008189s 			0 MB		 [đúng]
test 14 :	0.012888s 			0 MB		 [đúng]
test 15 :	0.012971s 			0 MB		 [đúng]
test 16 :	0.006517s 			0 MB		 [đúng]
test 17 :	0.008978s 			0 MB		 [đúng]

*/
