#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long m, n, k;
    cin >> n >> m >> k;
    long long _m, _n;
    m % k == 0 ? _m = m / k : _m = m / k + 1;
    n % k == 0 ? _n = n / k : _n = n / k + 1;
    cout << _m * _n;
    return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007105s 			0 MB		 [đúng]
test 2 :	0.011925s 			0 MB		 [đúng]
test 3 :	0.009474s 			0 MB		 [đúng]
test 4 :	0.007306s 			0 MB		 [đúng]
test 5 :	0.010297s 			0 MB		 [đúng]
test 6 :	0.010832s 			0 MB		 [đúng]
test 7 :	0.007712s 			0 MB		 [đúng]
test 8 :	0.008453s 			0 MB		 [đúng]
test 9 :	0.008498s 			0 MB		 [đúng]
test 10 :	0.007083s 			0 MB		 [đúng]
 */