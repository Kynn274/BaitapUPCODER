#include <bits/stdc++.h>
#define fmax 1003
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, ans(-1e9);
    int a[fmax][fmax], f[fmax][fmax];

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    for(int i = k; i <= n; i++)
        for(int j = k; j <= n; j++)
            ans = max(f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k], ans);
        
    cout << ans;
    return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.010299s 			0 MB		 [đúng]
test 2 :	0.010720s 			0 MB		 [đúng]
test 3 :	0.010012s 			0 MB		 [đúng]
test 4 :	0.012492s 			0 MB		 [đúng]
test 5 :	0.024581s 			0 MB		 [đúng]
test 6 :	0.043351s 			0 MB		 [đúng]
test 7 :	0.206731s 			0 MB		 [đúng]
test 8 :	0.247683s 			0 MB		 [đúng]
test 9 :	0.285591s 			0 MB		 [đúng]
test 10 :	0.292139s 			0 MB		 [đúng]

 */