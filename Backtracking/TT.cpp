#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

// 0 là người A
// 1 là người B

ll soLuong;
ll dongTien[fmax];
ll soCach(0);
vector<ll> nguoiNhan(20);
vector<vector<ll> > danhSachNguoiNhan;

void phatSinh(ll k){
  if(k == soLuong){
    ll tongA(0);
    ll tongB(0);
    
    for(ll i = 0; i < soLuong; i++){
      if(nguoiNhan[i] == 0) tongA += dongTien[i];
      if(nguoiNhan[i] == 1) tongB += dongTien[i];
    }
    
    if(tongA == tongB){
      danhSachNguoiNhan.push_back(nguoiNhan);
      soCach++;
    }
    
  }else{
    for(ll i = 0; i <= 1; i++){
      nguoiNhan[k] = i;
      phatSinh(k + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> soLuong;
  for(ll i = 0; i < soLuong; i++)
    cin >> dongTien[i];
    
  phatSinh(0);
  if(soCach == 0) cout << "khong chia duoc";
  else{
    cout << soCach << '\n';
    for(ll i = 0; i < soCach; i++){
      for(ll j = 0; j < soLuong; j++)
        danhSachNguoiNhan[i][j] == 0? cout << 'A' << ' ' : cout << 'B' << ' ';
      cout << '\n';
    }
  }
  
  return 0;
}
/*
Đúng 6/6
#######################
Thông tin chi tiết
test 1 :	0.008145s 			0 MB		 [đúng]
test 2 :	0.010445s 			0 MB		 [đúng]
test 3 :	0.010097s 			0 MB		 [đúng]
test 4 :	0.009004s 			0 MB		 [đúng]
test 5 :	0.009075s 			0 MB		 [đúng]
test 6 :	0.463993s 			0 MB		 [đúng]
*/
