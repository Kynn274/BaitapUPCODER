#include <bits/stdc++.h>
#define fmax 1000
using namespace std;

// BÀI TOÁN TÌM TẤT CẢ CÁCH TẠO RA 1 TỔNG TỪ CÁC SỐ ĐÃ CHO
vector<long long> a(fmax);                        // Mảng chứa phần tử đề cho
vector<long long> f;                              // Mảng chứa các trường hợp
long long n, k;                                   // Số phần tử, Tổng
long long tong = 0;                               // Tổng số trường hợp

void xuly(vector<long long> a, long long k){
  if(k == 0){
    tong++;
    long long len = f.size();
    for(long long i = 0; i < len; i++)            
      cout << f[i] << ' ';
    cout << endl;
  }else{
    for(long long i = 0; i < n; i++){
      if(a[i] <= k){
        f.push_back(a[i]);
        k -= a[i];
        xuly(a, k);
        k += a[i];
        f.pop_back();
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for(long long i = 0; i < n; i++) cin >> a[i];
  xuly(a, k);
  cout << tong;
  
  return 0;
}
