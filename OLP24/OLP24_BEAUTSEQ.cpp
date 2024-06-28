#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, ans(-1e9);
    long long a[200005], f[200005];
    cin >> n;
    for(long long i = 0; i < n; i++) cin >> a[i];
    a[0] % 3 != 0 ? f[0] = a[0] : f[0] = 0;
    for(long long i = 1; i < n; i++){
        a[i] % 3 != 0 ? f[i] = max(f[i - 1] + a[i], a[i]) : f[i] = 0;
        ans = max(ans, f[i]); 
    }

    cout << ans;
    return 0;
}