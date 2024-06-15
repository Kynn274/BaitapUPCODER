#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
using namespace std;

long long t, n, _max(1);
long long f[fmax];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> t;
  memset(f, 0, sizeof f);
  
  while(t--){
    cin >> n;
    f[0] = 1;
    
    if(n > _max){
      for(long long i = _max; i <= n; i++)
        f[i] = (i % MOD * f[i - 1]) % MOD;
    }
    cout << f[n] << '\n';
    _max = max(_max, n);
  }
  return 0;
}
/*
Đúng 4/4
#######################
Thông tin chi tiết
test 1 :	0.016745s 			0 MB		 [đúng]
test 2 :	0.019607s 			0 MB		 [đúng]
test 3 :	0.024615s 			0 MB		 [đúng]
test 4 :	0.023534s 			0 MB		 [đúng]
 */