#include <bits/stdc++.h>
#define ll long long
#define fmax 1003
using namespace std;

ll a, b;
ll road[fmax][fmax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    f[0][0] = 1;
    for(ll i = 1; i <= a; i++)
        f[i][0] = f[i - 1][0];
    for(ll i = 1; i <= a; i++)
        for(ll j = 1; j <= min (b, i); j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1];
    cout << f[a][b];
    return 0;
}
/*
Đúng 20/20
#######################
Thông tin chi tiết
test 1 :	0.006590s 			0 MB		 [đúng]
test 2 :	0.006216s 			0 MB		 [đúng]
test 3 :	0.006984s 			0 MB		 [đúng]
test 4 :	0.008202s 			0 MB		 [đúng]
test 5 :	0.007587s 			0 MB		 [đúng]
test 6 :	0.006546s 			0 MB		 [đúng]
test 7 :	0.006066s 			0 MB		 [đúng]
test 8 :	0.006514s 			0 MB		 [đúng]
test 9 :	0.006432s 			0 MB		 [đúng]
test 10 :	0.006615s 			0 MB		 [đúng]
test 11 :	0.006281s 			0 MB		 [đúng]
test 12 :	0.006280s 			0 MB		 [đúng]
test 13 :	0.006483s 			0 MB		 [đúng]
test 14 :	0.006254s 			0 MB		 [đúng]
test 15 :	0.006567s 			0 MB		 [đúng]
test 16 :	0.006002s 			0 MB		 [đúng]
test 17 :	0.007279s 			0 MB		 [đúng]
test 18 :	0.006402s 			0 MB		 [đúng]
test 19 :	0.006644s 			0 MB		 [đúng]
test 20 :	0.006625s 			0 MB		 [đúng]
*/