#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000006];
long long f[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++)
      a[i] < 0 ? f[i] = f[i - 1] + 1 : f[i] = f[i - 1];
      
    long long ans(0), iC(0), num(0);
    long long i(1), j(i);
    while(j <= n){
      if(num < 3){
        if(a[j] < 0) num += 1;
        j++;
      }
      if(num == 3){
        ans = max(ans, j - i - 1);
        if(a[i] < 0) num--;
        i++;
      }
    }
    ans = max(ans, j - i);
    cout << ans;
    return 0;
}
