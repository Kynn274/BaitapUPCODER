#include <bits/stdc++.h>
#define fmax 1003
#define MOD 1000000007
#define ll long long
using namespace std;

ll m, n;
char a[fmax][fmax];
ll _max(-1e9);

bool check(ll x, ll y){
  return (0 <= x && x < m && 0 <= y && y < n && a[x][y] == '1');
}

void tim_cho_dung(ll x, ll y){
  ll x1, y1, x2, y2, iC1(0);
  ll tong(0);
  
  // Nhánh trái
  x1 = x;
  x2 = x - 1;
  y1 = y2 = y - 1;
  while(check(x1, y1) && check(x2, y2)){
    iC1++;
    x1 --; y1 --; x2 --; y2 --;
  }

  if(check(x1, y1)) 
    tong += (iC1 * 2 + 1);
  else 
    tong += iC1 * 2;
  
  // Nhánh trên 
  iC1 = 0;
  y1 = y;
  y2 = y + 1;
  x1 = x2 = x - 1;
  while(check(x1, y1) && check(x2, y2)){
    iC1++;
    x1 --; y1 ++; x2 --; y2 ++;
  }

  if(check(x1, y1)) 
    tong += (iC1 * 2 + 1);
  else 
    tong += iC1 * 2;
    
  // Nhánh phải
  iC1 = 0;
  y1 = y2 = y + 1;
  x1 = x;
  x2 = x + 1;
  while(check(x1, y1) && check(x2, y2)){
    iC1++; 
    x1 ++; y1 ++; x2 ++; y2 ++;
  }

  if(check(x1, y1)) 
    tong += (iC1 * 2 + 1);
  else 
    tong += iC1 * 2;
    
  // Nhánh dưới
  iC1 = 0;
  y1 = y;
  y2 = y - 1;
  x1 = x2 = x + 1;
  while(check(x1, y1) && check(x2, y2)){
    iC1++; 
    x1 ++; y1 --; x2 ++; y2 --;
  }

  if(check(x1, y1)) 
    tong += (iC1 * 2 + 1);
  else 
    tong += iC1 * 2;
  
  _max = max (_max, tong);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> m >> n;
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < n; j++)
      cin >> a[i][j];
      
  for(ll i = 0; i < m; i++)
    for(ll j = 0; j < n; j++)
      if(check(i, j))
        tim_cho_dung(i, j);
    
  cout << _max + 1;
  return 0;
}
/*
Đúng 18/18
#######################
Thông tin chi tiết
test 1 :	0.007364s 			0 MB		 [đúng]
test 2 :	0.007692s 			0 MB		 [đúng]
test 3 :	0.008040s 			0 MB		 [đúng]
test 4 :	0.019963s 			0 MB		 [đúng]
test 5 :	0.008116s 			0 MB		 [đúng]
test 6 :	0.008786s 			0 MB		 [đúng]
test 7 :	0.007788s 			0 MB		 [đúng]
test 8 :	0.008103s 			0 MB		 [đúng]
test 9 :	0.007211s 			0 MB		 [đúng]
test 10 :	0.006314s 			0 MB		 [đúng]
test 11 :	0.009569s 			0 MB		 [đúng]
test 12 :	0.008373s 			0 MB		 [đúng]
test 13 :	0.008139s 			0 MB		 [đúng]
test 14 :	0.006964s 			0 MB		 [đúng]
test 15 :	0.008576s 			0 MB		 [đúng]
test 16 :	0.007477s 			0 MB		 [đúng]
test 17 :	0.008477s 			0 MB		 [đúng]
test 18 :	0.008098s 			0 MB		 [đúng]

*/
