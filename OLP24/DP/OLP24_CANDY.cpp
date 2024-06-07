#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

// tràn dữ liệu --> tổng max 10000000
// --> sử dụng mảng 1 chiều
ll n(0);
ll tong(0), ans(1e9), A, B;
ll f[fmax];
ll g[fmax];
vector<ll> a(fmax);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> a[n]){
        tong += a[n];
        n++;
    }

    a.resize(n);
    vector<ll> b(n, 0);

    f[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        f[i][0] = 1;
        for(ll j = tong; j >= 1; j--){
            f[i][j] = f[i - 1][j];
            if(j >= a[i - 1]) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i - 1]]);
        }
    }

    for(ll i = 0; i <= tong; i++)
        if(f[n][i] == 1)
            if(abs(tong - 2 * i) < ans){
                A = i;
                B = tong - i;
                ans = abs(tong - 2 * i);
            }
    
    ll i = n, j = A;
    while(i >= 0 && j > 0){
        if(f[i][j] != f[i - 1][j]){
            b[i - 1] = 1;
            j -= a[i - 1];
        }
        i--;
    }
    
    if(b[0] == 1){
        cout << A << ' ' << B << ' ' << abs(A - B) << '\n';
        for(ll i = 0; i < n; i++)
            if(b[i] == 1) cout << a[i] << ' ';
        cout << '\n';
        for(ll i = 0; i < n; i++)
            if(b[i] == 0) cout << a[i] << ' ';
    }else{
        cout << B << ' ' << A << ' ' << abs(A - B) << '\n';
        for(ll i = 0; i < n; i++)
            if(b[i] == 0) cout << a[i] << ' ';
        cout << '\n';
        for(ll i = 0; i < n; i++)
            if(b[i] == 1) cout << a[i] << ' ';
    }  

    return 0;
}