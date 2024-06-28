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
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007282s 			0 MB		 [đúng]
test 2 :	0.008380s 			0 MB		 [đúng]
test 3 :	0.006049s 			0 MB		 [đúng]
test 4 :	0.006022s 			0 MB		 [đúng]
test 5 :	0.009706s 			0 MB		 [đúng]
test 6 :	0.009169s 			0 MB		 [đúng]
test 7 :	0.011616s 			0 MB		 [đúng]
test 8 :	0.033367s 			0 MB		 [đúng]
test 9 :	0.035939s 			0 MB		 [đúng]
test 10 :	0.061122s 			0 MB		 [đúng]
 */