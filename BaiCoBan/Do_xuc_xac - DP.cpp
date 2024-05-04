#include <bits/stdc++.h>
#define MOD 1000000007
#define fmax 1000006
using namespace std;

// Tổng số cách đổ xúc xắc ra tổng có giá trị n
long long f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n;
  cin >> n;
  
  f[0] = 1;
  for(long long i = 1; i <= n; i++)
    for(long long j = 1; j <= 6; j++)
      if(j <= i)
        f[i] = (f[i] + f[i - j]) % MOD;
      
  cout << f[n];
  
  return 0;
}
