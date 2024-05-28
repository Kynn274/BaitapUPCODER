#include <bits/stdc++.h>
#define fmax 102
#define ll long long
using namespace std;

ll n, m;
ll x, y;
string a[fmax][fmax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == "abcde"){
                x = i;
                y = j;
            }
        }

    cout << char('A' + y) << x + 1;
    return 0;
}
/*
Đúng 9/9
#######################
Thông tin chi tiết
test 1 :	0.007716s 			0 MB		 [đúng]
test 2 :	0.007881s 			0 MB		 [đúng]
test 3 :	0.007769s 			0 MB		 [đúng]
test 4 :    0.006233s 			0 MB		 [đúng]
test 5 :	0.006362s 			0 MB		 [đúng]
test 6 :	0.006038s 			0 MB		 [đúng]
test 7 :	0.006256s 			0 MB		 [đúng]
test 8 :	0.006070s 			0 MB		 [đúng]
test 9 :	0.006611s 			0 MB		 [đúng]
*/