#include <bits/stdc++.h>
#define MOD 1000000007
#define fmax 1000006
using namespace std;

// XUẤT ĐỘ DÀI CHUỖI CON TĂNG DÀI NHẤT    

long long f[fmax];                                // dãy con tăng dài nhất

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n;                                    // độ dài mảng nhập
  cin >> n;
  
  vector<long long> a(n);
  for(long long i = 0; i < n; i++) cin >> a[i];   // nhập mảng
  
  long long ans = 0;
  for(long long i = 0; i < n; i++){
    f[i] = 1;                                     // giá trị cơ sở bằng 1
    /*
    Xét các phần từ từ 0 tới j
    Nối chuỗi con dài nhất j vào a[i]
    Lấy chuỗi dài nhất
    */
    for(long long j = 0; j < i; j++)
      if(a[j] < a[i])
        f[i] = max (f[i], f[j] + 1);
    ans = max (ans, f[i]);                       // lấy chuỗi dài nhất
  }
  
  cout << ans;
  return 0;
}
