#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll sx, sy, ex, ey;
ll n, z;
ll buocNhay_x[fmax];
ll buocNhay_y[fmax];
ll banSoLieu[fmax][fmax];

// Hàm tìm kiếm năng lượng tiêu hao ít nhất khi di chuyển giữa 2 toạ độ
ll doDaiDuongDi(ll x1, ll y1, ll x2, ll y2){
  return max(abs(x1 - x2), abs(y1 - y2));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  // Tịnh tiến tất cả toạ độ lên 10
  cin >> sx >> sy >> ex >> ey;
  sx += 10;
  sy += 10;
  ex += 10;
  ey += 10;
  
  cin >> n >> z;
  for(ll i = 1; i <= n; i++){
    cin >> buocNhay_x[i] >> buocNhay_y[i];
    buocNhay_x[i] += 10;
    buocNhay_y[i] += 10;
  }

  // Tìm năng lượng tiêu tốn ít nhất của từng bước nhảy đến đích
  banSoLieu[buocNhay_x[n]][buocNhay_y[n]] = doDaiDuongDi(buocNhay_x[n], buocNhay_y[n], ex, ey);
  for(ll i = n - 1; i >= 0; i--)
    banSoLieu[buocNhay_x[i]][buocNhay_y[i]] = min(doDaiDuongDi(buocNhay_x[i], buocNhay_y[i], ex, ey), 1 + banSoLieu[buocNhay_x[i + 1]][buocNhay_y[i + 1]]);

  // Lựa chọn phương pháp đi ít tiêu hao năng lượng nhất
  // TH1 - đi thẳng đến đích
  // Th2 - đi đến 1 bước nhảy rồi đi đến đích
  ll haoPhiItNhat = doDaiDuongDi(sx, sy, ex, ey);
  for(ll i = 0; i <= n; i++){
    haoPhiItNhat = min(haoPhiItNhat, doDaiDuongDi(sx, sy, buocNhay_x[i], buocNhay_y[i]) + banSoLieu[buocNhay_x[i]][buocNhay_y[i]]);
  }
  
  if(haoPhiItNhat <= z) cout << "YES\n" << z - haoPhiItNhat;
  else cout << "NO";

  return 0;
}
/*
Đúng 4/4
#######################
Thông tin chi tiết
test 1 :	0.006756s 			0 MB		 [đúng]
test 2 :	0.006854s 			0 MB		 [đúng]
test 3 :	0.007102s 			0 MB		 [đúng]
test 4 :	0.007013s 			0 MB		 [đúng]
*/
