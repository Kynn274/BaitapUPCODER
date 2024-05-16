#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll f[fmax];
string sum (string a, string b){
  while(a[0] == '0' && a.size() != 1) a.erase(0, 1);
  while(b[0] == '0' && b.size() != 1) b.erase(0, 1);

  while(a.size() < b.size()) a.insert(0, "0");
  while(b.size() < a.size()) b.insert(0, "0");

  string tmp1;
  string tmp2;
  ll len = a.size();
  for(ll i = len - 1; i >= 0; i--){
    tmp1 += a[i];
    tmp2 += b[i];
    f[i] = stoll(tmp1) + stoll(tmp2) + f[i + 1] / 10;
    f[i + 1] %= 10;
    tmp1.clear();
    tmp2.clear();
  }
  
  string ketQua;
  for(ll i = 0; i < len; i++){
    ketQua += to_string(f[i]);
  }
  
  return ketQua;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  string s, a, t;
  cin >> s;
  
  ll i = 0;
  while(i < s.size()){
    if('0' <= s[i] && s[i] <= '9')
      a += s[i];
    else{
      if(a.size() != 0){
        t = sum(a, t);
        a.clear();
      }
    }
    i++;
  }
  
  if(a.size() != 0){
    t = sum(a, t);
    a.clear();
  }
  
  cout << t;
  return 0;
}
/*
Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007032s 			0 MB		 [đúng]
test 2 :	0.006558s 			0 MB		 [đúng]
test 3 :	0.012429s 			0 MB		 [đúng]
test 4 :	0.125713s 			0 MB		 [đúng]
test 5 :	0.116704s 			0 MB		 [đúng]
test 6 :	0.760177s 			0 MB		 [đúng]
test 7 :	0.147825s 			0 MB		 [đúng]
test 8 :	0.040062s 			0 MB		 [đúng]
test 9 :	0.007681s 			0 MB		 [đúng]
*/
