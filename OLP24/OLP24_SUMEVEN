#include <bits/stdc++.h>
using namespace std;

unsigned long long tong(0), tong1(0), tong2(0);

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long l, r;
  cin >> l >> r;
  
  tong  = (r * (r + 1)) / 2;
  tong1 = (l * (l + 1)) / 2 - l;
  tong2 = tong - tong1;
  
  long long soLuongPhanTu = r - l + 1;
  
  // Trường hợp 1: lẻ lẻ
  if(r % 2 != 0 && l % 2 != 0){
    tong2 -= r;
    soLuongPhanTu -= 1;
    cout << (tong2 - soLuongPhanTu / 2) / 2 + soLuongPhanTu / 2;
  }
  
  // Trường hợp 2: chẵn chẵn
  if(r % 2 == 0 && l % 2 == 0){
    tong2 += r + 1;
    soLuongPhanTu += 1;
    cout << (tong2 - soLuongPhanTu / 2) / 2;
  }
  
  // Trường hợp 3: chẵn lẻ
  if(l % 2 == 0 && r % 2 != 0)
    cout << (tong2 - soLuongPhanTu / 2) / 2;
  
  // Trường hợp 4: lẻ chẵn
  if(l % 2 != 0 && r % 2 == 0)
    cout << (tong2 - soLuongPhanTu / 2) / 2 + soLuongPhanTu / 2;
  
  
  return 0;
}
/**
Đúng 70/70
#######################
Thông tin chi tiết
test 1 :	0.006651s 			0 MB		 [đúng]
test 2 :	0.007562s 			0 MB		 [đúng]
test 3 :	0.008090s 			0 MB		 [đúng]
test 4 :	0.008760s 			0 MB		 [đúng]
test 5 :	0.007802s 			0 MB		 [đúng]
test 6 :	0.007688s 			0 MB		 [đúng]
test 7 :	0.006879s 			0 MB		 [đúng]
test 8 :	0.009100s 			0 MB		 [đúng]
test 9 :	0.007524s 			0 MB		 [đúng]
test 10 :	0.007736s 			0 MB		 [đúng]
test 11 :	0.007383s 			0 MB		 [đúng]
test 12 :	0.007511s 			0 MB		 [đúng]
test 13 :	0.007606s 			0 MB		 [đúng]
test 14 :	0.006811s 			0 MB		 [đúng]
test 15 :	0.006937s 			0 MB		 [đúng]
test 16 :	0.007710s 			0 MB		 [đúng]
test 17 :	0.007161s 			0 MB		 [đúng]
test 18 :	0.007443s 			0 MB		 [đúng]
test 19 :	0.007679s 			0 MB		 [đúng]
test 20 :	0.008094s 			0 MB		 [đúng]
test 21 :	0.009906s 			0 MB		 [đúng]
test 22 :	0.007463s 			0 MB		 [đúng]
test 23 :	0.009265s 			0 MB		 [đúng]
test 24 :	0.009309s 			0 MB		 [đúng]
test 25 :	0.008801s 			0 MB		 [đúng]
test 26 :	0.006287s 			0 MB		 [đúng]
test 27 :	0.006796s 			0 MB		 [đúng]
test 28 :	0.006749s 			0 MB		 [đúng]
test 29 :	0.006218s 			0 MB		 [đúng]
test 30 :	0.006942s 			0 MB		 [đúng]
test 31 :	0.006799s 			0 MB		 [đúng]
test 32 :	0.007711s 			0 MB		 [đúng]
test 33 :	0.007383s 			0 MB		 [đúng]
test 34 :	0.006549s 			0 MB		 [đúng]
test 35 :	0.006250s 			0 MB		 [đúng]
test 36 :	0.006900s 			0 MB		 [đúng]
test 37 :	0.006564s 			0 MB		 [đúng]
test 38 :	0.006494s 			0 MB		 [đúng]
test 39 :	0.006705s 			0 MB		 [đúng]
test 40 :	0.006423s 			0 MB		 [đúng]
test 41 :	0.007485s 			0 MB		 [đúng]
test 42 :	0.006394s 			0 MB		 [đúng]
test 43 :	0.006410s 			0 MB		 [đúng]
test 44 :	0.006425s 			0 MB		 [đúng]
test 45 :	0.006396s 			0 MB		 [đúng]
test 46 :	0.006315s 			0 MB		 [đúng]
test 47 :	0.006378s 			0 MB		 [đúng]
test 48 :	0.006382s 			0 MB		 [đúng]
test 49 :	0.006429s 			0 MB		 [đúng]
test 50 :	0.010208s 			0 MB		 [đúng]
test 51 :	0.007177s 			0 MB		 [đúng]
test 52 :	0.006350s 			0 MB		 [đúng]
test 53 :	0.006377s 			0 MB		 [đúng]
test 54 :	0.007518s 			0 MB		 [đúng]
test 55 :	0.007108s 			0 MB		 [đúng]
test 56 :	0.007674s 			0 MB		 [đúng]
test 57 :	0.007730s 			0 MB		 [đúng]
test 58 :	0.007639s 			0 MB		 [đúng]
test 59 :	0.007094s 			0 MB		 [đúng]
test 60 :	0.005570s 			0 MB		 [đúng]
test 61 :	0.007492s 			0 MB		 [đúng]
test 62 :	0.007309s 			0 MB		 [đúng]
test 63 :	0.006555s 			0 MB		 [đúng]
test 64 :	0.007126s 			0 MB		 [đúng]
test 65 :	0.006362s 			0 MB		 [đúng]
test 66 :	0.006982s 			0 MB		 [đúng]
test 67 :	0.006178s 			0 MB		 [đúng]
test 68 :	0.007759s 			0 MB		 [đúng]
test 69 :	0.006891s 			0 MB		 [đúng]
test 70 :	0.006268s 			0 MB		 [đúng]
 */