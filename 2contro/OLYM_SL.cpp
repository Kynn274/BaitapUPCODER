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
/*
Đúng 20/20
#######################
Thông tin chi tiết
test 1 :	0.006636s 			0 MB		 [đúng]
test 2 :	0.008013s 			0 MB		 [đúng]
test 3 :	0.006689s 			0 MB		 [đúng]
test 4 :	0.006792s 			0 MB		 [đúng]
test 5 :	0.008202s 			0 MB		 [đúng]
test 6 :	0.008566s 			0 MB		 [đúng]
test 7 :	0.007225s 			0 MB		 [đúng]
test 8 :	0.006922s 			0 MB		 [đúng]
test 9 :	0.006815s 			0 MB		 [đúng]
test 10 :	0.007184s 			0 MB		 [đúng]
test 11 :	0.008110s 			0 MB		 [đúng]
test 12 :	0.007631s 			0 MB		 [đúng]
test 13 :	0.008088s 			0 MB		 [đúng]
test 14 :	0.008095s 			0 MB		 [đúng]
test 15 :	0.008441s 			0 MB		 [đúng]
test 16 :	0.006973s 			0 MB		 [đúng]
test 17 :	0.007199s 			0 MB		 [đúng]
test 18 :	0.008099s 			0 MB		 [đúng]
test 19 :	0.008945s 			0 MB		 [đúng]
test 20 :	0.009317s 			0 MB		 [đúng]
*/