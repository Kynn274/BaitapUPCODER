#include <bits/stdc++.h>
#define nmax 102
#define amax 1000006
#define MOD 1000000007
using namespace std;

// TỔNG SỐ CÁCH TÍNH TỔNG TỪ CÁC PHẦN TỬ ĐÃ CHO THEO THỨ TỰ 
int f[amax], n, S;                                          // Mảng số cách, số lượng phần tử, tổng cho trước

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> S;
  
  int a[nmax];                                              // Mảng phần tử 
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  f[0] = 1;
  for(int i = 1; i <= n; i++)
    for(int s = 0; s <= S; s++)
      if(s >= a[i])
        /*
        Tính số cách tính tổng cách số từ 0 tới S cho từng phần từ a[i]
        Phần tử sau tính dựa trên số cách tính trước, cộng với các trường hợp phát sinh mới 
        Có 2 trường hợp chính:
        - Trường hớp 1: s[i] đã được tạo từ các phần tử a[i] trước đó -> giữ lại
        - Trường hợp 2: s[i] tạo bởi phẩn tử a[i] hiện tại và tổng trước đó sao cho tổng trước đó + a[i] bằng tổng hiện tại
        */
        f[s] = (f[s] + f[s - a[i]]) % MOD;
  
  cout << f[S];
     
  return 0;
}
