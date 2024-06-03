#include <bits/stdc++.h>
#define ll long long
#define fmax 150
using namespace std;

ll n, m;
ll f[fmax][fmax];
ll s[fmax][fmax];
ll ans(-1e9), vt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<ll> a(n + 1);                            // giá trị
    vector<ll> b(n + 1);                            // thể tích
    
    memset(f, 0, sizeof f);
    for(ll i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++){
            f[i][j] = f[i - 1][j];
            s[i][j] = s[i - 1][j];
            if(j >= b[i])
              if(f[i - 1][j - b[i]] + a[i] >= f[i - 1][j]){
                f[i][j] = f[i - 1][j - b[i]] + a[i];
                s[i][j] = j - b[i];
              }
            if(f[i][j] > ans){
                ans = f[i][j];
                vt = j;
            }
        }
    cout << ans << '\n';
    
    vector<ll> item;
    ll i = n, j = vt;
    while(j > 0 && i > 0){
        if(f[i][j] != f[i - 1][j] || s[i][j] != s[i - 1][j]){
            item.push_back(i);
            j = s[i][j];
        }
        i--;
    }
    cout << item.size() << ' ';
    for(ll i = item.size() - 1; i >= 0; i--) cout << item[i] << ' ';
    return 0;
}