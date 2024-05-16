#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll kickThuoc;
ll danhDau[fmax][fmax];
ll duLieu[fmax][fmax];
ll s1, s2;
ll e1, e2;

bool hopLe(ll x, ll y){
  return (1 <= x && x <= kickThuoc && 1 <= y && y <= kickThuoc && danhDau[x][y] == 0);
}

void duyetMang(ll i, ll j){
  cout << i << ' ' << j << '\n';
  if(danhDau[i][j] == 1){
    if(duLieu[i][j + 1] == 0 && hopLe(i, j + 1)){
      danhDau[i][j + 1] = 1;
      duyetMang(i, j + 1);
    }
    if(duLieu[i][j - 1] == 0 && hopLe(i, j - 1)){
      danhDau[i][j - 1] = 1;
      duyetMang(i, j - 1);
    }
    if(duLieu[i + 1][j] == 0 && hopLe(i + 1, j)){
      danhDau[i + 1][j] = 1;
      duyetMang(i + 1, j);
    }
    if(duLieu[i - 1][j] == 0 && hopLe(i - 1, j)){
      danhDau[i - 1][j] = 1;
      duyetMang(i - 1, j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ifstream ip ("LINE.inp");
  ofstream op ("LINE.out");
  
  ip >> kickThuoc;
  ip >> s1 >> e1 >> s2 >> e2;
  
  for(ll i = 1; i <= kickThuoc; i++)
    for(ll j = 1; j <= kickThuoc; j++)
      ip >> duLieu[i][j];
  
  danhDau[s1][e1] = 1;
  duyetMang(s1, e1);
      
  if(danhDau[s2][e2] == 1) op << "YES";
  else op << "NO";
  
  return 0;
}

/*
Đúng 23/23
#######################
Thông tin chi tiết
test 1 :	0.006589s 			0 MB		 [đúng]
test 2 :	0.006542s 			0 MB		 [đúng]
test 3 :	0.007488s 			0 MB		 [đúng]
test 4 :	0.006622s 			0 MB		 [đúng]
test 5 :	0.006032s 			0 MB		 [đúng]
test 6 :	0.006204s 			0 MB		 [đúng]
test 7 :	0.007565s 			0 MB		 [đúng]
test 8 :	0.008067s 			0 MB		 [đúng]
test 9 :	0.008450s 			0 MB		 [đúng]
test 10 :	0.006498s 			0 MB		 [đúng]
test 11 :	0.008917s 			0 MB		 [đúng]
test 12 :	0.010570s 			0 MB		 [đúng]
test 13 :	0.009032s 			0 MB		 [đúng]
test 14 :	0.008076s 			0 MB		 [đúng]
test 15 :	0.008060s 			0 MB		 [đúng]
test 16 :	0.009181s 			0 MB		 [đúng]
test 17 :	0.008162s 			0 MB		 [đúng]
test 18 :	0.008971s 			0 MB		 [đúng]
test 19 :	0.008070s 			0 MB		 [đúng]
test 20 :	0.008757s 			0 MB		 [đúng]
test 21 :	0.008017s 			0 MB		 [đúng]
test 22 :	0.007009s 			0 MB		 [đúng]
test 23 :	0.007666s 			0 MB		 [đúng]
*/
