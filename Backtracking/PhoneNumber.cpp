#include <bits/stdc++.h>
#define fmax 1003
#define ll long long
using namespace std;

char dienThoai[][5] = {
{},
{},
{'a', 'b', 'c'},
{'d', 'e', 'f'},
{'g', 'h', 'i'},
{'j', 'k', 'l'},
{'m', 'n', 'o'},
{'p', 'q', 'r', 's'},
{'t', 'u', 'v'},
{'w', 'x', 'y', 'z'}};

string s;
ll kichThuoc;
ll duLieu[fmax];
char f[fmax];

void xuLy(ll p){
  if(p == kichThuoc){
    for(ll i = 0; i < kichThuoc; i++)
      cout << f[i];
    cout << ' ';
  }else{
    ll n;
    if(duLieu[p] == 7 || duLieu[p] == 9) n = 4;
    else n = 3;
    for(ll i = 0; i < n; i++){
      f[p] = dienThoai[duLieu[p]][i];
      xuLy(p + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string tmp;
  cin >> s;
  
  kichThuoc = s.size();
  for(ll i = 0; i < kichThuoc; i++){
    tmp += s[i];
    duLieu[i] = stoll(tmp);
    tmp.clear();
  }
  
  xuLy(0);
  
  return 0;
}
/*
Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007333s 			0 MB		 [đúng]
test 2 :	0.006633s 			0 MB		 [đúng]
test 3 :	0.007058s 			0 MB		 [đúng]
test 4 :	0.017257s 			0 MB		 [đúng]
test 5 :	0.007118s 			0 MB		 [đúng]
test 6 :	0.006620s 			0 MB		 [đúng]
test 7 :	0.006823s 			0 MB		 [đúng]
test 8 :	0.007218s 			0 MB		 [đúng]
test 9 :	0.390809s 			0 MB		 [đúng]
*/
