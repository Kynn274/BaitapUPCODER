#include <bits/stdc++.h>
#define fmax 1000
using namespace std;

// XUẤT ĐỘ DÀI CHUỖI CON TĂNG DÀI NHẤT CÓ TRUY VẾT  

long long f[fmax];                                // dãy con tăng dài nhất

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n;                                    // độ dài mảng nhập
  cin >> n;
  
  long long a[fmax];                              // mảng nhập
  long long t[fmax];                              // mảng truy vết
  long long vt(-1);                               // dánh dấu vị trí cuối cùng
  for(long long i = 0; i < n; i++) cin >> a[i];   // nhập mảng
  
  memset(t, -1, sizeof t);

  long long ans = 0;
  for(long long i = 0; i < n; i++){
    f[i] = 1;                                     // giá trị cơ sở bằng 1
    /*
    Xét các phần từ từ 0 tới j
    Nối chuỗi con dài nhất j vào a[i]
    Lấy chuỗi dài nhất
    */
    for(long long j = 0; j < i; j++)
      if(a[j] < a[i]){
        if(f[j] + 1 > f[i]){
          f[i] = f[j] + 1;
          t[i] = j;
        }
      }
    if(ans < f[i]){                              // lấy chuỗi dài nhất
      ans = f[i];
      vt  = i;
    }
  }
  
  cout << ans << endl;
  while(vt != -1){                               // Xuất chuỗi dài nhất
    cout << a[vt] << ' ';
    vt = t[vt];
  }
  return 0;
}
