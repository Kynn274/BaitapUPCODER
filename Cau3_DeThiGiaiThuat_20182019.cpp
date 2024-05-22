#include <bits/stdc++.h>
#define MOD 10000007 
#define fmax 10000007
#define ll long long
using namespace std;

ll n, k;
double a[fmax];
double sum[fmax];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  
  // HÀM CẢI TIẾN - Dùng quy hoạch động
  a[0] = 1;
  for(ll i = 1; i <= n + 1; i++)
    a[i] = a[i - 1] * 2 * i / (2 * (i - 1) + 3);
  sum[0] = a[0];
  for(ll i = 1; i <= n + 1; i++){
    sum[i] = sum[i - 1] + a[i];
    cout << sum[i] << ' ';
  }
  cout << '\n';
  
  float s = 1;
  for(ll i = 0; i <= n; i++){
    float b = 1;
    for(ll j = 0; j <= i; j++)
      b = b * 2 * (j + 1) / (2 * j + 3);
    s += b;
    cout << s << ' ';
  }
  return 0;
}
